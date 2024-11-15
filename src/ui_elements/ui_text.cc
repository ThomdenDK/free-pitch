#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "ui_text.h"
#include "prop_to_pixel.h"
#include "prop_rect.h"

UIText::UIText(std::string str, SDL_Color color, PropRect prop_rect) {
    this->str = str;
    this->color = color;
    this->prop_rect = prop_rect;
    if (prop_rect.h == 0) this->prop_rect.h = prop_rect.w / str.length() * 3;
}

void UIText::Draw(SDL_Renderer* renderer) {
    TTF_Font* font = TTF_OpenFont("../resources/fonts/UbuntuMono-Regular.ttf", 24);
    if (!font) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, str.c_str(), color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect pixel_rect = PropToPixel(prop_rect, renderer);
    SDL_RenderCopy(renderer, message, NULL, &pixel_rect);
}