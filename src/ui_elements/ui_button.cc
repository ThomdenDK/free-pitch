#include <SDL2/SDL.h>
#include "ui_button.h"
#include "ui_text.h"
#include "ui_clickable.h"
#include "ui_rect.h"

UIButton::UIButton(std::string str, SDL_Color text_color, SDL_Color bkg_color, SDL_Rect rect) {
    this->text = std::make_unique<UIText>(UIText(str, text_color, rect));
    this->rect = std::make_unique<UIRect>(UIRect(rect, bkg_color));
}

void UIButton::Draw(SDL_Renderer* renderer) {
    this->rect->Draw(renderer);
    this->text->Draw(renderer);
}

bool UIButton::WasClicked(int x, int y) {
    SDL_Rect r = rect->GetRect();
    if (r.x > x && x > r.x + r.w) {
        return false;
    }
    if (r.y > y && y > r.y + r.h) {
        return false;
    }
    return true;
}