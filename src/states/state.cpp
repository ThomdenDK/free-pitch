#include <vector>
#include <iostream>
#include "states.h"
#include "ui_elements/ui_elements.h"

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
            int mx, my;
            SDL_GetMouseState(&mx, &my);
            this->HandleClick(mx, my);
        }
        this->HandleEvent(event);
    }
    return 0;
}

void State::HandleClick(int mx, int my) {
    for (auto button : this->ui_clickables) {
        if (button->WasClicked(mx, my)) {
            button->ExecuteBehaviour();
        }
    }
}