#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <headers/base.hpp>
#include <headers/components.hpp>
#include <headers/hud.hpp>

class Edit{
public:
    Edit(Base& Base);
    ~Edit();
    Base& base;
    Component currentComponent;
    void chooseComponent(Component);
    void placeComponent();
    void removeComponent();
    void handleEvents(HUD& hud);
    void showCurrent();

};

