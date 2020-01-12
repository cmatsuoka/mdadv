#include <SDL2/SDL.h>
#include "graphics.h"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
SDL_Surface *screen;

#define NUM_COLORS 4
#define TIMER 7

static int palette[NUM_COLORS * 3] = {
    0x00, 0x00, 0x00,    /*  0 */
    0x00, 0x2a, 0x3f,    /*  1 */
    0x3f, 0x2a, 0x00,    /*  2 */
    0x3f, 0x3f, 0x3f     /*  3 */
};

static Uint32 mapped_color[NUM_COLORS];
static volatile Uint32 tick_timer = 0;

#define KEY_QUEUE_SIZE 16

static int key_queue[KEY_QUEUE_SIZE];
static int key_queue_start = 0;
static int key_queue_end = 0;

#define key_enqueue(k) do { key_queue[key_queue_end++] = (k); \
        key_queue_end %= KEY_QUEUE_SIZE; } while (0)
#define key_dequeue(k) do { (k) = key_queue[key_queue_start++]; \
        key_queue_start %= KEY_QUEUE_SIZE; } while (0)


static Uint32 timer_function(Uint32 i, void *parm)
{
    tick_timer++;
    return i;
}

static void process_events ()
{
    SDL_Event event;
    int key = 0;

    while (SDL_PollEvent (&event) > 0) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch (key = event.key.keysym.sym) {
            case SDLK_LSHIFT:
            case SDLK_RSHIFT:
                key = 0;
                break;
            }
            if (key) {
                key_enqueue(key);
            }
            break;
        }
    }
}


static inline void drawpixel(SDL_Surface *surf, int x, int y, int c)
{
    if (x < 0 || x >= surf->w || y < 0 || y >= surf->h) {
        return;
    }

    uint8_t *bits = ((Uint8 *) surf->pixels) + y * surf->pitch + x * 4;
    *((Uint32 *)(bits)) = mapped_color[c];
}

static void render_screen(SDL_Texture *text, SDL_Surface *surf)
{
    SDL_UpdateTexture(text, NULL, surf->pixels, GFX_WIDTH * sizeof (Uint32));
    SDL_RenderCopy(renderer, text, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void gfx_put_pixel(int x, int y, int c)
{
    drawpixel(screen, x, y, c);
}

void gfx_put_pixels(int x, int y, int w, uint8_t *buf)
{
    for (int i = 0; i < w; i++) {
        drawpixel(screen, x + i, y, *buf++);
    }
}

int gfx_init(char *title)
{
    int i;
    Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x000000ff;
    bmask = 0x0000ff00;
    amask = 0x00ff0000;
#else
    rmask = 0x00ff0000;
    gmask = 0x0000ff00;
    bmask = 0x000000ff;
    amask = 0xff000000;
#endif
    
    if (SDL_Init(SDL_INIT_VIDEO /*| SDL_INIT_AUDIO*/) < 0) {
        fprintf(stderr, "sdl: can't initialize: %s\n",
            SDL_GetError());
        return -1;
    }

#if 0
    if (opt.fullscreen)
        mode |= SDL_FULLSCREEN;
#endif

    if ((window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED, 512, 384,
            SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)) == NULL) {
        fprintf(stderr, "sdl: can't create window: %s\n", SDL_GetError());
        return -1;
    }
    atexit(SDL_Quit);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    if ((renderer = SDL_CreateRenderer(window, -1, 0)) == NULL) {
        fprintf(stderr, "sdl: can't create renderer: %s\n", SDL_GetError());
        return -1;
    }

    if ((texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                               SDL_TEXTUREACCESS_STREAMING, GFX_WIDTH, GFX_HEIGHT)) == NULL) {
        fprintf(stderr, "sdl: can't create texture: %s\n", SDL_GetError());
        return -1;
    }

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_GL_SetSwapInterval(1);
    SDL_RenderClear(renderer);

    screen = SDL_CreateRGBSurface(0, GFX_WIDTH, GFX_HEIGHT, 32,
                    rmask, gmask, bmask, amask);

    if (screen == NULL) {
        fprintf(stderr, "sdl: can't create surface: %s\n", SDL_GetError());
        return -1;
    }

    for (i = 0; i < NUM_COLORS; i++) {
        Uint8 r = palette[i * 3] << 2;
        Uint8 g = palette[i * 3 + 1] << 2;
        Uint8 b = palette[i * 3 + 2] << 2;
        mapped_color[i] = SDL_MapRGB(screen->format, r, g, b);
    }

    tick_timer = 0;
    SDL_AddTimer(10, timer_function, NULL);

    return 0;
}

void gfx_show()
{
    render_screen(texture, screen);
}


void poll_timer()
{
    static uint32_t m = 0;
    uint32_t dm;

    if (tick_timer < m) {
        m = 0;
    }

    while ((dm = tick_timer - m) < TIMER) {
        SDL_Delay(TIMER);
    }
    m = tick_timer;

    process_events();
}

static int is_keypress()
{
    process_events ();
    return key_queue_start != key_queue_end;
}

int read_key()
{
    int k;

    while (key_queue_start == key_queue_end) {        /* block */
        poll_timer ();
    }
    key_dequeue(k);

   return k;
}

int check_key()
{
    return !is_keypress();
}

int wait_key()
{
    while (!is_keypress()) {
        poll_timer();
    }

    return read_key();
}



