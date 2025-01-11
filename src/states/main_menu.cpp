#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
#include "states.h"
#include "ui_elements/ui_elements.h"
#include "free_pitch.h"

MainMenu::MainMenu() {
    UIText* title = new UIText(
        "FreePitch", 
        {255, 255, 255}, 
        {50, 50, 400, 100},
        true
    );
    UIButton* minigames_button = new UIButton(
        "Minigames", 
        {255, 255, 255}, 
        {0, 0, 0}, 
        {50, 250, 400, 100},
        [&]() {
            this->state_machine->ChangeState(new MinigameMenu());
        }
    );
    this->ui_elements.push_back(title);
    this->ui_elements.push_back(minigames_button);
    this->ui_clickables.push_back(minigames_button);
}