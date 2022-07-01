#include "PixelBufferDisplay.h"


PixelBufferDisplay::PixelBufferDisplay(int windowHeight, int windowWidth)
    : height(windowHeight), width(windowWidth) {

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL2 Pixel Drawing",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    texture = SDL_CreateTexture(renderer,
        SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, width, height);
    pixelBuffer = new Uint32[height * width];

    memset(pixelBuffer, 0, height * width * sizeof(Uint32)); // set to black
}

PixelBufferDisplay::~PixelBufferDisplay() {
    delete[] pixelBuffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
    SDL_Quit();
}

void PixelBufferDisplay::SetBuffer(const Uint32* buffer) {
    memcpy(pixelBuffer, buffer, height * width * sizeof(Uint32));
}

void PixelBufferDisplay::UpdateDisplay() {

    SDL_UpdateTexture(texture, NULL, pixelBuffer, width * sizeof(Uint32));

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}