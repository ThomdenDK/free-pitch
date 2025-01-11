#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include "ui_elements.h"

UIButton::UIButton(std::string str, SDL_Color text_color, SDL_Color bkg_color, 
    SDL_Rect rect, std::function<void()> behaviour)
    : text(UIText(str, text_color, rect, true)), rect(UIRect(rect, bkg_color))
{
    this->text = UIText(str, text_color, rect, true);
    this->rect = UIRect(rect, bkg_color);
    this->behaviour = behaviour;
}

void UIButton::Draw(SDL_Renderer* renderer) {
    this->rect.Draw(renderer);
    this->text.Draw(renderer);
}

bool UIButton::WasClicked(int mx, int my) {
    SDL_Rect r = this->rect.GetRect();
    if (r.x > mx || mx > r.x + r.w) {
        return false;
    }
    if (r.y > my || my > r.y + r.h) {
        return false;
    }
    return true;
}

void UIButton::ExecuteBehaviour() {behaviour();}