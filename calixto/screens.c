#include <stdint.h>

//
//        END FILE: SCREENS.ASM
//

uint8_t scrblu[] = {
    0x20,
    0x00, 0x00, 0x20, 0x5a, 0x55, 0x55, 0xff
};

uint8_t scrblk[] = {
    0x20,
    0x00, 0x00, 0x20, 0x5a, 0x00, 0x00, 0xff
};

uint8_t scrwht[] = {
    0x20,
    0x00, 0x00, 0x20, 0x5a, 0xff, 0xff, 0xff
};

uint8_t scrred[] = {
    0x20,
    0x00, 0x00, 0x20, 0x5a, 0xaa, 0xaa, 0xff
};

uint8_t scrshd[] = {
    0x20,
    0x00, 0x00, 0x20, 0x5a, 0xa8, 0xa8, 0xff
};

uint8_t scrsha[] = {
    0x20,
    0x00, 0x00, 0x20, 0x5a, 0x66, 0x99, 0xff
};

uint8_t scrn[] = {
    0x20,
    0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff,
    0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff,
    0x00, 0x65, 0xff, 0x00, 0x20, 0x00, 0x01, 0x8e,
    0x00, 0x1f, 0xce, 0x00, 0x20, 0x3b, 0x00, 0x20,
    0x2e, 0x00, 0x20, 0xbb, 0x00, 0x20, 0xee,
    0x00, 0x20, 0xbb, 0x00, 0x20, 0xee, 0x00, 0x20,
    0xb8, 0x00, 0x20, 0xec, 0x00, 0x1f, 0xb3,
    0x01, 0xb2, 0x00, 0x20, 0x00, 0x00, 0x1b, 0x77,
    0x05, 0x74, 0x00, 0x37, 0x77, 0x77, 0x00, 0x1b,
    0xdd, 0x05, 0xd0, 0x00, 0x0d, 0xdd, 0xdd,
    0x00, 0x1b, 0x77, 0x05, 0x40, 0x00, 0x07, 0x77,
    0x77, 0x00, 0x0d, 0xdd, 0x05, 0xdf, 0xff,
    0xff, 0xff, 0xfd, 0x00, 0x09, 0xdd, 0x05, 0xc0,
    0x20, 0x01, 0xdd, 0xdd, 0x00, 0x0c, 0x77,
    0x07, 0xff, 0xfe, 0xaa, 0xaa, 0xaa, 0xbf,
    0xff, 0x00, 0x08, 0x77, 0x05, 0x00, 0x80, 0x80,
    0x77, 0x77, 0x00, 0x0b, 0xdd, 0x02, 0xff,
    0xea, 0x00, 0x05, 0xaa, 0x02, 0xab, 0xff, 0x00,
    0x07, 0xdd, 0x05, 0x08, 0x20, 0x20, 0xdd, 0xdd,
    0x00, 0x0a, 0x77, 0x02, 0x7f, 0xfa, 0x00, 0x07,
    0xaa, 0x02, 0xab, 0xff, 0x00, 0x06, 0x77, 0x05,
    0x04, 0x00, 0x08, 0x77, 0x77, 0x00, 0x09, 0xdd, 0x02,
    0xdf, 0xfe, 0x00, 0x09, 0xaa, 0x02, 0xab, 0xfd,
    0x00, 0x05, 0xdd, 0x05, 0x10, 0x00, 0xc1, 0x1d,
    0xdd, 0x00, 0x09, 0x77, 0x01, 0xfe, 0x00, 0x0b,
    0xaa, 0x02, 0xaf, 0xf7, 0x00, 0x04, 0x77, 0x05,
    0x30, 0x80, 0x43, 0x77, 0x77, 0x00, 0x08,
    0xdd, 0x01, 0xff, 0x00, 0x0d, 0xaa, 0x01, 0xbf,
    0x00, 0x04, 0xdd, 0x05, 0xd0, 0xe0, 0xd1, 0xdd,
    0xdd, 0x00, 0x04, 0x77, 0x05, 0x74, 0x00, 0x03, 0x77,
    0xfa, 0x00, 0x08, 0xaa, 0x0f, 0xa8, 0x00, 0xaa,
    0xaa, 0xaa, 0xab, 0xf7, 0x77, 0x77,
    0x77, 0x73, 0x60, 0x33, 0x77, 0x77,
    0x00, 0x04, 0xdd, 0x04, 0xdc, 0x0d, 0xd1, 0xff,
    0x00, 0x0a, 0xaa, 0x01, 0x02, 0x00, 0x04, 0xaa, 0x09,
    0xbf, 0xdd, 0xdd, 0xdd, 0xd1, 0xe0,
    0x1d, 0xdd, 0xdd, 0x00, 0x04, 0x77, 0x04, 0x74,
    0x07, 0x73, 0xfa, 0x00, 0x0a, 0xaa, 0x01, 0x02,
    0x00, 0x04, 0xaa, 0x09, 0xab, 0xf7, 0x77, 0x77,
    0x77, 0x68, 0x37, 0x77, 0x77, 0x00, 0x04,
    0xdd, 0x03, 0xdc, 0x0d, 0xf3, 0x00, 0x0b,
    0xaa, 0x01, 0x02, 0x00, 0x05, 0xaa, 0x08, 0xbf, 0xdd,
    0xdd, 0xdd, 0xd8, 0x1d, 0xdd, 0xdd,
    0x00, 0x04, 0x77, 0x03, 0x74, 0x07, 0xfa, 0x00, 0x0b,
    0xaa, 0x01, 0x02, 0x00, 0x05, 0xaa, 0x08, 0xab, 0xf7,
    0x77, 0x77, 0x78, 0x07, 0x77, 0x77, 0x00,
    0x04, 0xdd, 0x02, 0xdc, 0x0f, 0x00, 0x0c, 0xaa,
    0x01, 0x02, 0x00, 0x06, 0xaa, 0x07, 0xbd, 0xdd, 0xdd,
    0xda, 0x0d, 0xdd, 0xdd, 0x00, 0x04, 0x77,
    0x02, 0x74, 0x0e, 0x00, 0x0c, 0xaa, 0x01, 0x02,
    0x00, 0x06, 0xaa, 0x07, 0xaf, 0xf7, 0x77, 0x76,
    0x07, 0x77, 0x77, 0x00, 0x04, 0xdd, 0x02, 0xdc,
    0x0a, 0x00, 0x0c, 0xaa, 0x01, 0x02, 0x00, 0x07, 0xaa,
    0x06, 0xff, 0xdd, 0xde, 0x01, 0xdd, 0xdd,
    0x00, 0x04, 0x77, 0x1c, 0x7c, 0x0a, 0xaa,
    0x00, 0x28, 0x2a, 0x00, 0x8a, 0xa2, 0x00, 0x08,
    0x00, 0xaa, 0xaa, 0x02, 0x80, 0x0a, 0x0a,
    0x80, 0x0a, 0x0a, 0x8a, 0x00, 0xf7, 0x76,
    0x83, 0x77, 0x77, 0x00, 0x04, 0xdd, 0x1c,
    0xfc, 0x0a, 0xaa, 0x0a, 0x28, 0x2a,
    0x82, 0x82, 0xa2, 0xa0, 0xa8, 0x28,
    0xaa, 0xaa, 0x02, 0x82, 0xaa, 0x0a, 0x82,
    0x8a, 0x0a, 0x8a, 0x0b, 0x3d, 0xdd,
    0x81, 0xdd, 0xdd, 0x00, 0x04, 0x77, 0xfe,
    0xf8, 0x0a, 0xaa, 0x0a, 0x28, 0x2a,
    0x82, 0x82, 0x8a, 0xa0, 0xa8, 0x28,
    0xaa, 0xaa, 0x02, 0x82, 0xaa, 0x0a, 0x82,
    0x8a, 0x02, 0x8a, 0x0a, 0x3f, 0x77, 0x83,
    0x77, 0x77, 0xdd, 0xdd, 0xdd, 0xdf,
    0xe8, 0x0a, 0xaa, 0x0a, 0x28, 0x2a,
    0x82, 0xa0, 0x8a, 0xa0, 0xa8, 0x28,
    0xaa, 0xaa, 0x02, 0x82, 0xaa, 0x0a, 0x82,
    0x8a, 0x02, 0x8a, 0x0a, 0x2f, 0xdd, 0x80,
    0xdd, 0xdd, 0x77, 0x77, 0x77, 0x7f,
    0xa8, 0x0a, 0xaa, 0x0a, 0x28, 0x2a,
    0x82, 0xa0, 0x2a, 0xa0, 0xa8, 0x28,
    0xaa, 0xaa, 0x02, 0x80, 0x0a, 0x0a, 0x82,
    0x8a, 0x02, 0x8a, 0x0a, 0x2b, 0xf7, 0x80,
    0x77, 0x77, 0xdd, 0xdd, 0xdd, 0xfe,
    0xa8, 0x0a, 0xaa, 0x00, 0x28, 0x2a, 0x82,
    0xa8, 0x2a, 0xa0, 0xa8, 0x28, 0xaa,
    0xaa, 0x02, 0xaa, 0x0a, 0x0a, 0x80, 0x0a,
    0x08, 0x8a, 0x0a, 0x2a, 0xfd, 0xa0, 0xdd,
    0xdd, 0x77, 0x77, 0x77, 0xea, 0xa8,
    0x0a, 0xa2, 0x0a, 0x28, 0x2a, 0x82,
    0xa0, 0x2a, 0xa0, 0xa8, 0x28, 0xaa,
    0xaa, 0x02, 0xaa, 0x0a, 0x0a, 0x82, 0x8a,
    0x08, 0x8a, 0x0a, 0x2a, 0xbf, 0x60, 0x77,
    0x77, 0xdd, 0xdd, 0xdf, 0xaa, 0xa8,
    0x0a, 0xa2, 0x0a, 0x28, 0x2a, 0x82,
    0xa2, 0x0a, 0xa0, 0xa8, 0x28, 0xaa,
    0xaa, 0x02, 0xaa, 0x0a, 0x0a, 0x82, 0x8a,
    0x08, 0x8a, 0x0a, 0x2a, 0xab, 0xe0, 0xdd,
    0xdd, 0x77, 0x77, 0x7e, 0xaa, 0xa8,
    0x0a, 0xa2, 0x0a, 0x28, 0x2a, 0x82,
    0x8a, 0x0a, 0xa0, 0xa8, 0x28, 0xaa,
    0xaa, 0x02, 0xaa, 0x0a, 0x0a, 0x82, 0x8a,
    0x0a, 0x0a, 0x0a, 0x2a, 0xaa, 0xe0,
    0x37, 0x77, 0xdd, 0xdd, 0xfa, 0xaa,
    0xa8, 0x00, 0x02, 0x0a, 0x28, 0x02, 0x00, 0x8a,
    0x82, 0xa0, 0xa8, 0x00, 0xaa, 0xa8, 0x00,
    0x80, 0x0a, 0x00, 0x82, 0x8a, 0x0a, 0x0a,
    0x00, 0xaa, 0xaa, 0xa0, 0x1d, 0xdd, 0x77,
    0x77, 0x01, 0xea, 0x00, 0x1a, 0xaa, 0x05, 0xa8,
    0x37, 0x77, 0xdd, 0xdf, 0x00, 0x1b, 0xaa,
    0x05, 0xa8, 0x1d, 0xdd, 0x77, 0x7e, 0x00,
    0x1b, 0xaa, 0x05, 0xa8, 0x37, 0x77, 0xdd,
    0xfe, 0x00, 0x1b, 0xaa, 0x03, 0xa8, 0x05, 0xdd,
    0x00, 0x1d, 0x55, 0x03, 0x58, 0x0a, 0xaa,
    0x00, 0x1c, 0x55, 0x04, 0x5a, 0x88, 0x00, 0x00,
    0x00, 0x1b, 0x55, 0x05, 0x6a, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x1a, 0x55, 0x00, 0x26, 0x00, 0x01, 0x8e,
    0x00, 0x1f, 0xce, 0x00, 0x20, 0x3b, 0x00, 0x20,
    0x2e, 0x00, 0x20, 0xbb, 0x00, 0x20, 0xee,
    0x00, 0x20, 0xbb, 0x00, 0x20, 0xee, 0x00, 0x20,
    0xb8, 0x00, 0x20, 0xec, 0x00, 0x1f, 0xb3,
    0x01, 0xb2, 0x00, 0x20, 0x00, 0xff
};

uint8_t mdlogo[] = {
    0x20,
    0x00, 0x20, 0xff,
    0x09, 0xff, 0xff, 0xaa, 0xaf, 0xfa, 0xaa,
    0xfa, 0xaa, 0xab, 0x00, 0x17, 0xff, 0x0a,
    0x00, 0x00, 0xaa, 0xa0, 0x0a, 0xaa, 0x0a,
    0xaa, 0xaa, 0x80, 0x00, 0x18, 0x00, 0x08, 0xaa,
    0xa0, 0x0a, 0xaa, 0x0a, 0xaa, 0xaa,
    0xa0, 0x00, 0x16, 0x00, 0x0a, 0xff, 0xfe,
    0xaa, 0xaf, 0xea, 0xaa, 0xfa, 0xaa,
    0xaa, 0xaf, 0x00, 0x17, 0xff, 0x09, 0xfe,
    0xaa, 0xaf, 0xea, 0xaa, 0xfa, 0xaa,
    0xaa, 0xab, 0x00, 0x16, 0xff, 0x0a, 0x00,
    0x02, 0xaa, 0xa0, 0x2a, 0xaa, 0x0a, 0xaa,
    0xaa, 0xa8, 0x00, 0x17, 0x00, 0x09, 0x02, 0xaa,
    0xa0, 0x2a, 0xaa, 0x0a, 0xa8, 0x2a,
    0xa8, 0x00, 0x17, 0x00, 0x09, 0x0a, 0xaa, 0xa0,
    0xaa, 0xaa, 0x0a, 0xa8, 0x0a, 0xaa,
    0x00, 0x17, 0x00, 0x09, 0x0a, 0xaa, 0xa0, 0xaa,
    0xaa, 0x0a, 0xa8, 0x0a, 0xaa, 0x00, 0x16,
    0x00, 0x0a, 0xff, 0xea, 0xaa, 0xae, 0xaa,
    0xaa, 0xfa, 0xab, 0xfa, 0xaa, 0x00, 0x16,
    0xff, 0x0a, 0x00, 0x2a, 0xaa, 0xa2, 0xaa,
    0xaa, 0x0a, 0xa8, 0x02, 0xaa, 0x00, 0x17,
    0x00, 0x0a, 0x2a, 0xaa, 0xa2, 0xaa, 0xaa,
    0x0a, 0xa8, 0x02, 0xaa, 0x00, 0x00, 0x14, 0xff,
    0x02, 0x00, 0x00, 0x00, 0x05, 0xaa, 0x05, 0x0a, 0xa8,
    0x02, 0xaa, 0x00, 0x00, 0x14, 0xff, 0x02, 0x00, 0x00,
    0x00, 0x05, 0xaa, 0x05, 0x0a, 0xa8, 0x02, 0xaa,
    0x00, 0x00, 0x14, 0xff, 0x02, 0x00, 0x00, 0x00, 0x05, 0xaa,
    0x05, 0x0a, 0xa8, 0x0a, 0xaa, 0x00, 0x00, 0x14,
    0xff, 0x02, 0x00, 0x02, 0x00, 0x05, 0xaa, 0x05, 0x0a,
    0xa8, 0x0a, 0xaa, 0x00, 0x00, 0x14, 0xff,
    0x02, 0x00, 0x02, 0x00, 0x05, 0xaa, 0x05, 0x0a, 0xa8,
    0x2a, 0xa8, 0x00, 0x00, 0x14, 0xff, 0x0c,
    0x00, 0x02, 0xaa, 0x8a, 0xaa, 0xa2, 0xaa,
    0x0a, 0xaa, 0xaa, 0xa8, 0x00, 0x00, 0x14,
    0xff, 0x0c, 0x00, 0x0a, 0xaa, 0x8a, 0xaa,
    0xa2, 0xaa, 0x0a, 0xaa, 0xaa, 0xa8,
    0x00, 0x00, 0x14, 0xff, 0x0c, 0x00, 0x0a, 0xaa,
    0x8a, 0xaa, 0xa2, 0xaa, 0x0a, 0xaa,
    0xaa, 0xa0, 0x00, 0x00, 0x14, 0xff, 0x0c,
    0x00, 0x0a, 0xaa, 0x0a, 0xaa, 0x82, 0xaa,
    0x0a, 0xaa, 0xaa, 0xa0, 0x00, 0x00, 0x14,
    0xff, 0x0c, 0x00, 0x0a, 0xaa, 0x0a, 0xaa,
    0x82, 0xaa, 0x0a, 0xaa, 0xaa, 0x80,
    0x00, 0x00, 0x14, 0xff, 0x0a, 0x00, 0x0a, 0xa8,
    0x0a, 0xaa, 0x02, 0xaa, 0x0a, 0xaa, 0xa8,
    0x00, 0x17, 0x00, 0x09, 0xfa, 0xab, 0xfa, 0xaa,
    0xfe, 0xaa, 0xfa, 0xaa, 0xab, 0xff
};

//
//        END FILE: SCREENS.ASM
//
