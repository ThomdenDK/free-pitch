#include <vector>
#include <SDL2/SDL.h>
#include "state.h"
#include "ui_elements/ui_element.h"
#include "ui_elements/ui_clickable.h"

std::vector<UIElement*> State::GetUIElements() {
    return ui_elements;
}

std::vector<UIClickable*> State::GetUIClickables() {
    return ui_clickables;
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