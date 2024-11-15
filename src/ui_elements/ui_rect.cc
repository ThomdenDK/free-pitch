#include <SDL2/SDL.h>
#include "ui_rect.h"
#include "prop_rect.h"

UIRect::UIRect(PropRect prop_rect, SDL_Color color) {
    this->rect = rect;
    this->color = color;
}

void UIRect::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect UIRect::GetRect() {
    return rect;
}