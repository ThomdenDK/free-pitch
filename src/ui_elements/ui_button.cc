#include <SDL2/SDL.h>
#include <iostream>
#include "ui_button.h"
#include "ui_text.h"
#include "ui_clickable.h"
#include "ui_rect.h"
#include "prop_rect.h"
#include "prop_to_pixel.h"
#include "free_pitch/i_window.h"

UIButton::UIButton(std::string str, SDL_Color text_color, SDL_Color bkg_color, PropRect prop_rect) {
    this->text = std::make_unique<UIText>(UIText(str, text_color, prop_rect, true));
    this->rect = std::make_unique<UIRect>(UIRect(prop_rect, bkg_color));
}

void UIButton::Draw(SDL_Renderer* renderer) {
    this->rect->Draw(renderer);
    this->text->Draw(renderer);
}

bool UIButton::WasClicked(int mx, int my, int ww, int wh) {
    if (pixel_rect.h == 0) pixel_rect.h = pixel_rect.w / str.length() * 2;
    if (r.x > mx || mx > r.x + r.w) {
        return false;
    }
    if (r.y > my || my > r.y + r.h) {
        return false;
    }
    return true;
}