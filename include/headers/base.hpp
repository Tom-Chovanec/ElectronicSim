#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <memory>
#include <headers/variables.hpp>
#include <headers/components.hpp>

struct vector2 {
    int x, y;
};

enum State {
    EDIT = 0,
    SIMULATION,
    EXIT
};

extern bool buttonReleased;


class Base {
public:
    Base();
    ~Base();
    vector2 mousePos;
    Uint32 mouseState;
    State baseState;
    int frameCount = 0;
    Uint32 startTime = 0;
    TTF_Font* MontserratBold;
    SDL_Texture* loadTexture(const char* filePath);
    void render(SDL_Texture* texture, int x, int y);
    void handleEvents();
    void run();
    void drawGrid();
    void fill();
    void setColor(SDL_Color color);
    void drawRect(SDL_Rect rect, SDL_Color fillColor = {0, 0, 0, 0}, int borderWidth = 0, SDL_Color borderColor = {0, 0, 0, 255});
    void renderText(const char* text, int x, int y, TTF_Font* font, SDL_Color color);
    void drawTexture(SDL_Texture* texture, int x, int y, int w, int h);
    void drawComponents();
    void getMousePress();
    TTF_Font* loadFont(const char* path, int size);
    std::vector<std::unique_ptr<ComponentC>> components;

protected:
    SDL_Window* window;
    SDL_Renderer* renderer;
};