#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <variables.hpp>

class Base;

enum Component {
    NONE,
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
};

class ComponentC {
public:
    ComponentC();
    ~ComponentC();
    Component type;
    vector2 realPos;
    vector2 gridPos;
    vector2 realSize;
    vector2 gridSize;
    const char* imagePath;
    SDL_Texture* texture;

};

class Resistor : public ComponentC {
public:
    Resistor();
    ~Resistor();
};

class Capacitor : public ComponentC {
public:
    Capacitor();
    ~Capacitor();
};

class Inductor : public ComponentC {
public:
    Inductor();
    ~Inductor();
};