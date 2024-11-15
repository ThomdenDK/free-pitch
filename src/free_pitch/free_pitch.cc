#include "free_pitch.h"
#include <SDL2/SDL.h>
#include <memory>
#include "i_window.h"
#include "states/state.h"
#include "states/main_menu.h"

FreePitch::FreePitch(IWindow& win, State& initial_state) : 
    window(win), state(initial_state) {}

void FreePitch::ChangeState(State& state) {
    this->state = state;
}

void FreePitch::Run() {
    window.Open();

    while (1) {
        if (state.HandleAllEvents() < 0) break;
        window.DrawStateContents(state);
        window.Render();
    }
    
    window.Close();
}
