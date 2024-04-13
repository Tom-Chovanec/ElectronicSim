#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <headers/base.hpp>

enum Component {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
};

class Edit{
public:
    Edit(Base& Base);
    ~Edit();
    Base& base;
    Component currentComponent;
    Component chooseComponent(Component);
    void placeComponent();
    void removeComponent();
    void handleEvents();

};

