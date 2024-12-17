#include <vector>
#include <SDL2/SDL.h>
#include "state.h"
#include "ui_elements/ui_element.h"
#include "ui_elements/ui_clickable.h"
#include "free_pitch/i_window.h"

std::vector<UIElement*> State::GetUIElements() {
    return ui_elements;
}

std::vector<UIClickable*> State::GetUIClickables() {
    return ui_clickables;
}

//Returns -1 when loop should quit. Feeds all current events into state's event handler
int State::HandleAllEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) return -1;
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            int mx, my, ww, wh;
            SDL_GetMouseState(&mx, &my);
            this->HandleClick(mx, my, ww, wh);
        }
        this->HandleEvent(event);
    }
    return 0;
}