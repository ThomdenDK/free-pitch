#include "free_pitch.h"
#include "window.h"
#include "states/states.h"
#include <memory>
#include <iostream>

const int FPS = 60;
const int frame_delay = 1000/FPS; 

void FreePitch::Run() {
    state = new MainMenu();
    window = new Window();
    *state = MainMenu();
    state->state_machine = this;
    window->Open(800, 600);

    while (1) {
        Uint32 frame_start = SDL_GetTicks(); // Start of frame

        if (state->HandleAllEvents() < 0) break;
        window->Draw(*state);
        window->Render();

        // Frame rate limiting
        Uint32 frameTime = SDL_GetTicks() - frame_start;
        if (frame_delay > frameTime) {
            SDL_Delay(frame_delay - frameTime); // Delay to cap FPS
        }
    }
    
    window->Close();
}

void FreePitch::ChangeState(State* state) {
    std::cout << "Changed\n";
    this->state = state;
}