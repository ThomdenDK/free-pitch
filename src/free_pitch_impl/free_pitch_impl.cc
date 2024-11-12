#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include "initializer/free_pitch_impl.h"
#include "synth.h"
#include "window.h"
#include "state.h"
#include "main_menu.h"

FreePitchImpl::FreePitchImpl() {
    window = Window();
}

int FreePitchImpl::Run() {
    Synth::Init();
    window.Open();
    //Start program from the main menu
    std::unique_ptr<State> state = std::make_unique<MainMenu>();

    while (1) {
        if (state->HandleAllEvents() < 0) {
            window.Close();
            return 0;
        }
        window.DrawStateContents(state);
        window.Render();
    }
}