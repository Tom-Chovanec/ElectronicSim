#include <headers/hud.hpp>
#include <headers/variables.hpp>

HUD::HUD(Base& base) : base(base) {
    // HUD phase specific initialization
}

HUD::~HUD() {
    // HUD phase specific destruction
}

void HUD::draw() {
    SDL_Rect hudRect = {0, 0, wWidth, 80};
    base.drawRect(hudRect, Colors::Primary);
}

bool buttonReleased = false;

void HUD::dropDown(int x, int y, int w, int h, const char* options[], int numOptions, const char* title, TTF_Font* font, std::vector<std::function<void()>> onClicks) {
    std::pair<int, int> position = std::make_pair(x, y);
    if (open.find(position) == open.end())
        open[position] = false;

    if (!(base.mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))) {
        buttonReleased = true;
    }

    if ((open[position] != true) && (base.mousePos.x > x && base.mousePos.x < x + w && base.mousePos.y > y && base.mousePos.y < y + h)) {
        if (base.mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
            open[position] = true;
            buttonReleased = false;
    }

    if ((open[position] == true) && (base.mousePos.x > x && base.mousePos.x < x + w && base.mousePos.y > y && base.mousePos.y < y + h*numOptions)) 
        open[position] = true;
    else if (base.mouseState & (SDL_BUTTON(SDL_BUTTON_LEFT) | SDL_BUTTON(SDL_BUTTON_MIDDLE) | SDL_BUTTON(SDL_BUTTON_RIGHT))) 
        open[position] = false;



    int textWidth, textHeight;

    if (open[position] == true) {
        for (int i = 1; i-1 < numOptions; i++) {

            TTF_SizeText(font, options[i-1], &textWidth, &textHeight);

            int textX = x + (w - textWidth) / 2;
            int textY = y + h * (i-1) + (h - textHeight) / 2;

            SDL_Rect rect = {x, y+h*(i-1), w, h};

            if ((base.mousePos.x > x && base.mousePos.x < x + w && base.mousePos.y > y + h * (i-1) && base.mousePos.y < y + h * i)) {
                base.drawRect(rect, Colors::Primary, 2);
                base.renderText(options[i-1], textX, textY, font, Colors::Background);
                if (base.mouseState & SDL_BUTTON(SDL_BUTTON_LEFT) && buttonReleased) {
                    onClicks[i-1]();
                    buttonReleased = false;
                }
            }
            else {
                base.drawRect(rect, Colors::Secondary, 2);
                base.renderText(options[i-1], textX, textY, font, Colors::AccentWhite);
            }
        }
    }
    else {
        TTF_SizeText(font, title, &textWidth, &textHeight);
        int textX = x + (w - textWidth) / 2;
        int textY = y + (h - textHeight) / 2;
        SDL_Rect rect = {x, y, w, h};
        base.drawRect(rect, Colors::Secondary, 2);
        base.renderText(title, textX, textY, font, Colors::AccentWhite);
    }
}