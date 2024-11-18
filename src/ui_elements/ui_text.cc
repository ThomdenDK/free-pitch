#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "ui_text.h"
#include "prop_to_pixel.h"
#include "prop_rect.h"

UIText::UIText(std::string str, SDL_Color color, PropRect prop_rect, bool auto_adjust_height) {
    this->str = str;
    this->color = color;
    this->prop_rect = prop_rect;
    this->auto_adjust_height = auto_adjust_height;
}

void UIText::Draw(SDL_Renderer* renderer) {
    TTF_Font* font = TTF_OpenFont("../resources/fonts/UbuntuMono-Regular.ttf", 24);
    if (!font) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }
    SDL_Surface* surface = TTF_RenderText_Solid(font, str.c_str(), color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface);
    if (auto_adjust_height) {
        int w, h;
        SDL_GetRendererOutputSize(renderer, &w, &h);
        prop_rect.h = prop_rect.w * (float)h / (float)w / str.length() * 2;
    }
    SDL_Rect pixel_rect = PropToPixel(prop_rect, renderer);
    SDL_RenderCopy(renderer, message, NULL, &pixel_rect);
}