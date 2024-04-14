#pragma once

#include <SDL.h>

extern int wWidth;
extern int wHeight;


namespace Colors {
    const SDL_Color Background = {48, 50, 61, 255};
    const SDL_Color Primary = {232, 197, 71, 255};
    const SDL_Color Secondary = {77, 80, 97, 255};
    const SDL_Color AccentBlue = {92, 128, 188, 255};
    const SDL_Color AccentWhite = {205, 209, 196, 255};
    const SDL_Color Black = {0, 0, 0, 255};
}

struct vector2 {
    int x, y;
    vector2 operator+(vector2 v) {
        return {x + v.x, y + v.y};
    }
    vector2 operator-(vector2 v) {
        return {x - v.x, y - v.y};
    }
    vector2 operator*(int scalar) {
        return {x * scalar, y * scalar};
    }
    vector2 operator/(int scalar) {
        return {x / scalar, y / scalar};
    }
    bool operator==(vector2 v) const {
        return {x==v.x && y==v.y};
    }
    bool operator!=(vector2 v) const {
        return {x!=v.x && y!=v.y};
    }
    bool operator<(vector2 v) const {
        return {x<v.x && y<v.y};
    }
    bool operator>(vector2 v) const {
        return {x>v.x && y>v.y};
    }
    bool operator<=(vector2 v) const {
        return {x<=v.x && y<=v.y};
    }
    bool operator>=(vector2 v) const {
        return {x>=v.x && y>=v.y};
    }
    bool operator!=(int scalar) const {
        return {x!=scalar && y!=scalar};
    }
    bool operator==(int scalar) const {
        return {x==scalar && y==scalar};
    }
    bool operator<(int scalar) const {
        return {x<scalar && y<scalar};
    }
    bool operator>(int scalar) const {
        return {x>scalar && y>scalar};
    }
    bool operator<=(int scalar) const {
        return {x<=scalar && y<=scalar};
    }
    bool operator>=(int scalar) const {
        return {x>=scalar && y>=scalar};
    }

};


const vector2 RESISTOR_SIZE = {2, 1};
const vector2 CAPACITOR_SIZE = {1, 1};
const vector2 INDUCTOR_SIZE = {3, 2};