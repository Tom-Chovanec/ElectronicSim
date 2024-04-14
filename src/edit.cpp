#include <headers/edit.hpp>

Edit::Edit(Base& base) : base(base) {
    // Edit phase specific initialization
    currentComponent = NONE;
}

void Edit::handleEvents(HUD& hud) {
    if (base.mouseState & SDL_BUTTON(SDL_BUTTON_LEFT) && buttonReleased && !hud.isClicked(base.mousePos)) {
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
            resistor->gridPos = base.getGridPos({base.mousePos.x, base.mousePos.y});
            resistor->texture = base.loadTexture(resistor->imagePath);
            resistor->realSize = resistor->gridSize * base.GRID_SIZE;
            base.components.push_back(std::move(resistor));
            currentComponent = NONE;
            break;
        }
        case CAPACITOR: {
            auto capacitor = std::make_unique<Capacitor>();
            capacitor->gridPos = base.getGridPos({base.mousePos.x, base.mousePos.y});
            capacitor->texture = base.loadTexture(capacitor->imagePath);
            capacitor->realSize = capacitor->gridSize * base.GRID_SIZE;
            base.components.push_back(std::move(capacitor));
            currentComponent = NONE;
            break;
        }
        case INDUCTOR: {
            auto inductor = std::make_unique<Inductor>();
            inductor->gridPos = base.getGridPos({base.mousePos.x, base.mousePos.y});
            inductor->texture = base.loadTexture(inductor->imagePath);
            inductor->realSize = inductor->gridSize * base.GRID_SIZE;
            base.components.push_back(std::move(inductor));
            currentComponent = NONE;
            break;
        }
    }
}

void Edit::showCurrent() {
    vector2 gridPos = base.getGridPos({base.mousePos.x, base.mousePos.y});
    vector2 renderPos = base.getRealPos(gridPos);
    switch (currentComponent) {
        case RESISTOR:
            base.render(base.loadTexture("res/images/resistor.png"), renderPos, base.getRealSize(RESISTOR_SIZE));
            break;
        case CAPACITOR:
            base.render(base.loadTexture("res/images/capacitor.png"), renderPos, base.getRealSize(CAPACITOR_SIZE));
            break;
        case INDUCTOR:
            base.render(base.loadTexture("res/images/inductor.png"), renderPos, base.getRealSize(INDUCTOR_SIZE));
            break;
        default:
            break;
    }
}


Edit::~Edit() {

}