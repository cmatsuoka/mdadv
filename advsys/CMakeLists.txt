cmake_minimum_required(VERSION 2.6)
  
project(advsys)

include_directories(${mdadv_INCLUDE_DIRS})

include_directories(SDL_INCLUDE_DIR})

add_library(${PROJECT_NAME}
	advsys11.c
	advutil.c
	advcode1.c
)

