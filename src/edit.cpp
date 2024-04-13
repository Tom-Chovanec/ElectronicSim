#include <headers/edit.hpp>

Edit::Edit(Base& base) : base(base) {
    // Edit phase specific initialization
}

void Edit::handleEvents(HUD& hud) {
    if (base.mouseState & SDL_BUTTON(SDL_BUTTON_LEFT) && buttonReleased && currentComponent != NONE && !hud.isClicked(base.mousePos.x, base.mousePos.y)) {
        placeComponent();
    }
}

void Edit::chooseComponent(Component component) {
    currentComponent = component;
}

void Edit::placeComponent() {
    switch (currentComponent) {
        case RESISTOR: {
            auto resistor = std::make_unique<Resistor>();
            resistor->posX = base.mousePos.x;
            resistor->posY = base.mousePos.y;
            resistor->texture = base.loadTexture(resistor->imagePath);
            base.components.push_back(std::move(resistor));
            currentComponent = NONE;
            break;
        }
        case CAPACITOR: {
            auto capacitor = std::make_unique<Capacitor>();
            capacitor->posX = base.mousePos.x;
            capacitor->posY = base.mousePos.y;
            capacitor->texture = base.loadTexture(capacitor->imagePath);
            base.components.push_back(std::move(capacitor));
            currentComponent = NONE;
            break;
        }
        case INDUCTOR: {
            auto inductor = std::make_unique<Inductor>();
            inductor->posX = base.mousePos.x;
            inductor->posY = base.mousePos.y;
            inductor->texture = base.loadTexture(inductor->imagePath);
            base.components.push_back(std::move(inductor));
            currentComponent = NONE;
            break;
        }
    }
}

void Edit::showCurrent() {
    switch (currentComponent) {
        case RESISTOR:
            base.render(base.loadTexture("res/images/resistor.png"), base.mousePos.x, base.mousePos.y);
            break;
        case CAPACITOR:
            base.render(base.loadTexture("res/images/capacitor.png"), base.mousePos.x, base.mousePos.y);
            break;
        case INDUCTOR:
            base.render(base.loadTexture("res/images/inductor.png"), base.mousePos.x, base.mousePos.y);
            break;
    }
}


Edit::~Edit() {

}