#define SDL_MAIN_HANDLED // insert this

#include <iostream>

#include "PixelBufferDisplay.h"


static const Uint16 WIDTH = 240;
static const Uint16 HEIGHT = 320;

void UpdatePixels(Uint32* pixels) {
    for (size_t row = 0; row < WIDTH; row++) {
        for (size_t col = 0; col < HEIGHT; col++) {
            Uint32 red = row;
            Uint32 green = col * 2;
            Uint32 blue = 5;
            Uint32 color = (red << 16) | (green << 8) | blue;
            pixels[row * HEIGHT + col] = color;
        }
    }
}

int main(int argc, char** argv) {
    std::cout << "Player Test..." << std::endl;

    PixelBufferDisplay player(HEIGHT, WIDTH);

    Uint32* pixelBuffer = new Uint32[HEIGHT * WIDTH];

    for (size_t i = 0; i < 3000; i++) {
        UpdatePixels(pixelBuffer);
        player.SetBuffer(pixelBuffer);
        player.UpdateDisplay();
    }

    delete[] pixelBuffer;
    std::cout << "Finished play test." << std::endl;
    return 0;
}