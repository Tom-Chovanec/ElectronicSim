#include <headers/hud.hpp>

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

void HUD::dropDown(int x, int y, int w, int h, const char* options[], int numOptions, const char* title, TTF_Font* font, std::vector<std::function<void()>> onClicks) {
    std::pair<int, int> position = std::make_pair(x, y);
    if (open.find(position) == open.end())
        open[position] = false;

    auto it = std::find_if(elements.begin(), elements.end(), [x, y](const Element& e) { return e.pos.x == x && e.pos.y == y; });
    if (it == elements.end()) return; 

    Element& element = *it;

    if ((open[position] != true) && (base.mousePos.x > x && base.mousePos.x < x + w && base.mousePos.y > y && base.mousePos.y < y + h)) {
        if (base.mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            open[position] = true;
            buttonReleased = false;
        }

    }

    if ((open[position] == true) && (base.mousePos.x > x && base.mousePos.x < x + w && base.mousePos.y > y && base.mousePos.y < y + h*numOptions)) 
        open[position] = true;
    else if (base.mouseState & (SDL_BUTTON(SDL_BUTTON_LEFT) | SDL_BUTTON(SDL_BUTTON_MIDDLE) | SDL_BUTTON(SDL_BUTTON_RIGHT))) 
        open[position] = false;



    int textWidth, textHeight;

    if (open[position] == true) {
        element.size = {w, h * numOptions};

        for (int i = 1; i-1 < numOptions; i++) {

            TTF_SizeText(font, options[i-1], &textWidth, &textHeight);

            int textX = x + (w - textWidth) / 2;
            int textY = y + h * (i-1) + (h - textHeight) / 2;

            SDL_Rect rect = {x, y+h*(i-1), w, h};

            if ((base.mousePos.x > x && base.mousePos.x < x + w && base.mousePos.y > y + h * (i-1) && base.mousePos.y < y + h * i)) {
                base.drawRect(rect, Colors::Primary, 2);
                base.renderText(options[i-1], textX, textY, font, Colors::Background);
                if ((base.mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) && buttonReleased) {
                    onClicks[i-1]();
                    open[position] = false;
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
        element.size = {w, h};
        TTF_SizeText(font, title, &textWidth, &textHeight);
        int textX = x + (w - textWidth) / 2;
        int textY = y + (h - textHeight) / 2;
        SDL_Rect rect = {x, y, w, h};
        base.drawRect(rect, Colors::Secondary, 2);
        base.renderText(title, textX, textY, font, Colors::AccentWhite);
    }
}

bool HUD::isClicked(vector2 mousePos) {
    for (auto& element : elements) {
        if (mousePos >= element.pos && mousePos <= element.pos + element.size){
            std::cout << "Element clicked\n";
            return true;
        }
    }
    return false;
}

void HUD::addElement(int x, int y, int width, int height, std::string id) {
    Element element = {x, y, width, height, id};
    elements.push_back(element);
}