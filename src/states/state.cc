#include <vector>
#include <SDL2/SDL.h>
#include "state.h"

std::vector<UIElement*> State::GetUIElements() {
    return UI_elements;
}

//Returns -1 when loop should quit
int State::HandleAllEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) return -1;
        this->HandleEvent(event);
    }
    return 0;
}