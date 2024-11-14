#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "ui_text.h"

UIText::UIText(std::string str, SDL_Color color, SDL_Rect rect) {
    this->str = str;
    this->color = color;
    this->rect = rect;
}

void UIText::Draw(SDL_Renderer* renderer) {
    TTF_Font* font = TTF_OpenFont("../resources/fonts/UbuntuMono-Regular.ttf", 24);
    if (!font) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, str.c_str(), color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface);
    if (rect.h == 0) rect.h = rect.w / sizeof(str);
    SDL_RenderCopy(renderer, message, NULL, &rect);
}