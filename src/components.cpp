#include <headers/components.hpp>

Resistor::Resistor()
{
    texture = nullptr;
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    resistance = 100;
}

Resistor::~Resistor()
{
    SDL_DestroyTexture(texture);
    texture = nullptr;
}

void Resistor::calculateVoltage() {
    voltage = current * resistance;
}

void Resistor::calculateCurrent() {
    current = voltage / resistance;
}