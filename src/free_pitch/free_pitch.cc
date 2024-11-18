#include "free_pitch.h"
#include <SDL2/SDL.h>
#include <memory>
#include "i_window.h"
#include "states/state.h"
#include "states/main_menu.h"

FreePitch::FreePitch(IWindow& win) : window(win) {}

void FreePitch::ChangeState(State* state) {
    this->state = state;
}

IWindow& FreePitch::GetWindow() {
    return window;
}

void FreePitch::Run() {
    window.Open();

    while (1) {
        if (state->HandleAllEvents(window) < 0) break;
        window.DrawStateContents(*state);
        window.Render();
    }
    
    window.Close();
}
