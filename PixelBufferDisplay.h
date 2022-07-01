#pragma once

#define SDL_MAIN_HANDLED // insert this
#include <SDL.h>         // for SDL2


class PixelBufferDisplay {
private:
    uint16_t    height;
    uint16_t    width;

    /**
     * @brief Buffer that SDL will display in the window.
     *       Passed to the bufferUpdater callback to update
     *       The graphics.
     */
    Uint32* pixelBuffer;

    // SDL Vars
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Event event;

public:
    PixelBufferDisplay(int windowHeight, int windowWidth);
    ~PixelBufferDisplay();
    void SetBuffer(const Uint32* pixelBuffer);
    void UpdateDisplay();
};