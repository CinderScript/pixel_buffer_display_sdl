#include "PixelBufferDisplay.h"


PixelBufferDisplay::PixelBufferDisplay(int windowHeight, int windowWidth, void (*bufferUpdater)(Uint32*))
    : height(windowHeight), width(windowWidth), update(bufferUpdater), quit(false) {

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL2 Pixel Drawing",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    texture = SDL_CreateTexture(renderer,
        SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, width, height);
    pixelBuffer = new Uint32[height * width];

    memset(pixelBuffer, 255, height * width * sizeof(Uint32));
}

PixelBufferDisplay::~PixelBufferDisplay() {
    delete[] pixelBuffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
    SDL_Quit();
}

void PixelBufferDisplay::SetBuffer() {

    while (!quit) {
        SDL_UpdateTexture(texture, NULL, pixelBuffer, width * sizeof(Uint32));

        SDL_WaitEvent(&event);

        if (event.type == SDL_QUIT) {
            quit = true;
        }

        update(pixelBuffer);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
}