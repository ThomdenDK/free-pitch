#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
#include "main_menu.h"
#include "ui_elements/ui_text.h"
#include "ui_elements/ui_button.h"
#include "ui_elements/ui_clickable.h"
#include "free_pitch/i_window.h"

MainMenu::MainMenu(IFreePitch* fp) {
    free_pitch = fp;
    UIText* title = new UIText(
        "FreePitch", 
        {255, 255, 255}, 
        {0.2, 0.2, 0.6, 0.0},
        true
    );
    UIButton* minigames_button = new UIButton(
        "Minigames", 
        {255, 255, 255}, 
        {0, 0, 0}, 
        {0.2, 0.5, 0.6, 0}
    );
    this->ui_elements.push_back(title);
    this->ui_elements.push_back(minigames_button);
    this->ui_clickables.push_back(minigames_button);
}

void MainMenu::HandleEvent(SDL_Event& event) {}

void MainMenu::HandleClick(int mx, int my, int ww, int wh) {

}
