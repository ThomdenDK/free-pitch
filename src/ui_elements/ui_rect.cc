#include <SDL2/SDL.h>
#include "ui_rect.h"
#include "prop_rect.h"
#include "prop_to_pixel.h"

UIRect::UIRect(PropRect prop_rect, SDL_Color color) {
    this->prop_rect = prop_rect;
    this->color = color;
}

void UIRect::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect pixel_rect = PropToPixel(prop_rect, renderer);
    SDL_RenderFillRect(renderer, &pixel_rect);
}

PropRect UIRect::GetRect() {
    return prop_rect;
}