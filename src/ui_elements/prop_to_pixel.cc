#include "prop_to_pixel.h"
#include "prop_rect.h"
#include <SDL2/SDL.h>

SDL_Rect PropToPixel(PropRect prop_rect, SDL_Renderer* renderer) {
    int width, height;
    SDL_GetRendererOutputSize(renderer, &width, &height);
    SDL_Rect pixel_rect {
        prop_rect.x * (float)width,
        prop_rect.y * (float)height,
        prop_rect.w * (float)width,
        prop_rect.h * (float)height
    };
    return pixel_rect;
}
