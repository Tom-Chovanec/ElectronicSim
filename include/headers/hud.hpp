#pragma once

#include <SDL.h>
#include <base.hpp>
#include <headers/variables.hpp>
#include <map>
#include <functional>

struct Element {
    int x, y, width, height;
    std::string id;
    // Add other properties as needed
};

class HUD {
private:
    std::map<std::pair<int, int>, bool> open;
public:
    HUD(Base& base);
    ~HUD();
    Base& base;
     std::vector<Element> elements;
    void draw();
    void handleEvents();
    void dropDown(int x, int y, int w, int h, const char* options[], int numOptions, const char* title, TTF_Font* font, std::vector<std::function<void()>> onClicks);
    void selection();
    bool isClicked(int mouseX, int mouseY);
    void addElement(int x, int y, int width, int height, std::string id);
 
};