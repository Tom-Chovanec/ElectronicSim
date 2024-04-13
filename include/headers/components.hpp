#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Resistor {
public:
    Resistor();
    ~Resistor();
    SDL_Texture* texture;
    int x, y;
    int width, height;
    int resistance;
    int current; // Added current
    int voltage; // Added voltage

    void calculateVoltage();
    void calculateCurrent();
};