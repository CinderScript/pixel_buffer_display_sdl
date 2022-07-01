
cmake_minimum_required(VERSION 3.0)
project(pixel_buffer_sdl_display)
set(SOURCES 
    main.cpp
    PixelBufferDisplay.h
    PixelBufferDisplay.cpp  
)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
add_executable(pixel_buffer_sdl_display ${SOURCES})
target_link_libraries(pixel_buffer_sdl_display ${SDL2_LIBRARY})