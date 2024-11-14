#include <SDL2/SDL.h>
#include "ui_rect.h"

UIRect::UIRect(SDL_Rect rect, SDL_Color color) {
    this->rect = rect;
    this->color = color;
}