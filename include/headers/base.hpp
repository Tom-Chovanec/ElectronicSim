#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

struct vector2 {
    int x, y;
};

enum State {
    EDIT = 0,
    SIMULATION,
    EXIT
};




class Base {
public:
    Base();
    ~Base();
    vector2 mousePos;
    Uint32 mouseState;
    State baseState;
    TTF_Font* MontserratBold;
    void render(SDL_Texture* texture, int x, int y);
    SDL_Texture* loadTexture(const char* filePath);
    void handleEvents();
    void run();
    void drawGrid();
    void fill();
    void setColor(SDL_Color color);
    void drawRect(SDL_Rect rect, SDL_Color fillColor = {0, 0, 0, 0}, int borderWidth = 0, SDL_Color borderColor = {0, 0, 0, 255});
    void renderText(const char* text, int x, int y, TTF_Font* font, SDL_Color color);
    void getMousePos();
    TTF_Font* loadFont(const char* path, int size);

protected:
    SDL_Window* window;
    SDL_Renderer* renderer;
};