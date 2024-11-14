#include "free_pitch.h"
#include <SDL2/SDL.h>
#include <memory>
#include "i_window.h"
#include "states/state.h"
#include "states/main_menu.h"

FreePitch::FreePitch(IWindow& win) : window(win) {}

void FreePitch::Run() {
    window.Open();
    //Start program from the main menu
    std::unique_ptr<State> state = std::make_unique<MainMenu>();

    while (1) {
        if (state->HandleAllEvents() < 0) break;
        window.DrawStateContents(*state);
        window.Render();
    }
    window.Close();
}