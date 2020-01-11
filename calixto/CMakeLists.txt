cmake_minimum_required(VERSION 3.1)
  
project(calixto)

include_directories(${mdadv_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
	advdata2.c
	advcode2.c
	main.c
)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/advsys/libadvsys.a SDL2)
