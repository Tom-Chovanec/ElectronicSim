#include <headers/edit.hpp>

Edit::Edit(Base& base) : base(base) {
    // Edit phase specific initialization
}

void Edit::handleEvents() {
    // Edit phase specific method
    const Uint8* state = SDL_GetKeyboardState(NULL);
    int mouseX, mouseY;
    Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

    if (state[SDL_SCANCODE_R]) {
        currentComponent = RESISTOR;
    }

    if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        placeComponent();
    }
}

Component Edit::chooseComponent(Component component) {
    std::cout << component;
    return component;
}

void Edit::placeComponent() {
    // Edit phase specific method
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    switch (currentComponent) {
        case RESISTOR:
            base.render(base.loadTexture("res/images/resistor.png"), mouseX, mouseY);
            break;
    }
}

Edit::~Edit() {

}