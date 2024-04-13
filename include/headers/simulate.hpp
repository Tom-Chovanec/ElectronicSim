#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <headers/base.hpp>

class Simulate{
public:
    Simulate(Base& Base);
    ~Simulate();
    Base& base;
    // Simulation phase specific methods
};