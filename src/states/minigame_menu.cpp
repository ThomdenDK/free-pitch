#include "states/states.h"
#include "ui_elements/ui_elements.h"

MinigameMenu::MinigameMenu() {
    UIButton* single_notes_button = new UIButton(
        "Single Note Recognition", 
        {255, 255, 255}, 
        {0, 0, 0}, 
        {50, 250, 400, 100},
        []() {
            
        }
    );
    this->ui_elements.push_back(single_notes_button);
    this->ui_clickables.push_back(single_notes_button);
}