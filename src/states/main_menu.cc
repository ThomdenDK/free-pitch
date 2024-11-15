#include <SDL2/SDL.h>
#include <memory>
#include "main_menu.h"
#include "ui_elements/ui_text.h"
#include "ui_elements/ui_button.h"
#include "ui_elements/ui_clickable.h"

MainMenu::MainMenu() {
    UIElement *title, *minigames_button;
    title = new UIText("FreePitch", {255, 255, 255}, {100, 100, 400, 0});
    minigames_button = new UIButton("Minigames", 
        {255, 255, 255}, {0, 0, 0}, {100, 400, 400, 0});
    this->ui_elements.push_back(title);
    this->ui_elements.push_back(minigames_button);
    this->ui_clickables.push_back((UIClickable*)minigames_button);
}

void MainMenu::HandleEvent(SDL_Event& event) {
    if (event.type != SDL_MOUSEBUTTONDOWN) {
        return;
    }
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (ui_clickables[0]->WasClicked(x, y)) {
        
    }
}
