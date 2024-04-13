#include <headers/base.hpp>
#include <headers/variables.hpp>


Base::Base() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow("Electronic Sim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wWidth, wHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cout << "ERROR: window could not be initialized - " << SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cout << "ERROR: renderer could not be initialized - " << SDL_GetError() << std::endl;
    }
    baseState = EDIT;
}

Base::~Base() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Base::render(SDL_Texture* texture, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

SDL_Texture* Base::loadTexture(const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        std::cout << "ERROR: surface could not be loaded - " << SDL_GetError() << std::endl;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cout << "ERROR: texture could not be loaded - " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(surface);
    return texture;
}

void Base::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                baseState = EXIT;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_e) {
                    baseState = EDIT;
                } else if (event.key.keysym.sym == SDLK_s) {
                    baseState = SIMULATION;
                }
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    wWidth = event.window.data1;
                    wHeight = event.window.data2;
                }
                break;
            default:
                break;
            
        }
        mouseState = SDL_GetMouseState(&mousePos.x, &mousePos.y);
    }
}

void Base::run() {
    SDL_RenderPresent(renderer);
}   

void Base::drawGrid() {
    SDL_SetRenderDrawColor(renderer, Colors::Secondary.r, Colors::Secondary.g, Colors::Secondary.b, Colors::Secondary.a);
    for (int i = 0; i < wWidth; i += 20) {
        SDL_RenderDrawLine(renderer, i, 0, i, wHeight);
    }
    for (int i = 0; i < wHeight; i += 20) {
        SDL_RenderDrawLine(renderer, 0, i, wWidth, i);
    }
}

void Base::fill() {
    SDL_SetRenderDrawColor(renderer, Colors::Background.r, Colors::Background.g, Colors::Background.b, Colors::Background.a);
    SDL_RenderClear(renderer);
}

void Base::setColor(SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Base::drawRect(SDL_Rect rect, SDL_Color fillColor, int borderWidth, SDL_Color borderColor) {
    if (fillColor.a != 0) {
        setColor(fillColor);
        SDL_RenderFillRect(renderer, &rect);
    }
    setColor(borderColor);
    for (int i = 0; i < borderWidth; i++) {
        SDL_Rect outlineRect = {rect.x - i, rect.y - i, rect.w + 2*i, rect.h + 2*i};
        SDL_RenderDrawRect(renderer, &outlineRect);
    }
}

void Base::renderText(const char* text, int x, int y, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, {color.r, color.g, color.b});
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect Message_rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(Message);
}

TTF_Font* Base::loadFont(const char* path, int size) {
    TTF_Font* font = TTF_OpenFont(path, size);
    if (font == NULL) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
    }
    return font;
}