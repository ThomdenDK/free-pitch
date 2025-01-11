#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "ui_elements.h"

UIText::UIText(std::string str, SDL_Color color, SDL_Rect rect, bool auto_adjust_height) {
    this->str = str;
    this->color = color;
    this->rect = rect;
    this->auto_adjust_height = auto_adjust_height;
}

void UIText::Draw(SDL_Renderer* renderer) {
    TTF_Font* font = TTF_OpenFont("../../resources/fonts/UbuntuMono-Regular.ttf", 24);
    if (!font) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }
    SDL_Surface* surface = TTF_RenderText_Solid(font, str.c_str(), color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface);
    if (auto_adjust_height) {
        int w, h;
        SDL_GetRendererOutputSize(renderer, &w, &h);
        // prop_rect.h = prop_rect.w * (float)h / (float)w / str.length() * 2;
    }
    SDL_RenderCopy(renderer, message, NULL, &rect);
}