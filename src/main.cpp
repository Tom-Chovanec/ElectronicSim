#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#include "headers/base.hpp"
#include "headers/components.hpp"
#include "headers/edit.hpp"
#include "headers/simulate.hpp"
#include "headers/hud.hpp"


int main(int argc, char* argv[]) {
    Base base;
    Edit edit(base);
    Simulate simulation(base);
    HUD hud(base);
    TTF_Font* MontserratRegular = base.loadFont("fonts/Montserrat-Regular.ttf", 12);
    const char* options[7] = {"Resistor", "Capacitor", "Inductor"};

    hud.addElement(20, 20, 100, 40, "Components");
    hud.addElement(0, 0, wWidth, 80, "MainBar");
    std::vector<std::function<void()>> chooseComponents = {
        [&edit]() { edit.chooseComponent(Component(RESISTOR)); },
        [&edit]() { edit.chooseComponent(Component(CAPACITOR)); },
        [&edit]() { edit.chooseComponent(Component(INDUCTOR)); }
    };

    while (base.baseState != EXIT) {
        base.handleEvents();
        base.fill();
        base.drawGrid();
        switch (base.baseState) {
        case EDIT:
            edit.handleEvents(hud);
            if (!hud.isClicked(base.mousePos)) std::cout << "able to place\n";
            break;
        
        default:
            break;
        }
        base.drawComponents();
        hud.draw();
        hud.dropDown(20, 20, 100, 40, options, 3, "Components", MontserratRegular, chooseComponents);
        edit.showCurrent();
        base.getMousePress();
        base.run();
        if (argc > 1 && std::string(argv[1]) == "1") {
            base.showFps();
        }
    }

    return 0;
}
