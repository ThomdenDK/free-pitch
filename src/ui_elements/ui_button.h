#pragma once
#include <string>
#include <memory>
#include "ui_element.h"
#include "ui_clickable.h"

class SDL_Rect;
class SDL_Renderer;
class SDL_Color;
class UIText;
class UIRect;
struct PropRect;

class UIButton : public UIElement, public UIClickable {
    private:
        std::unique_ptr<UIText> text;
        std::unique_ptr<UIRect> rect;
    public:
        UIButton(std::string str, SDL_Color text_color, SDL_Color bkg_color, PropRect prop_rect);
        void Draw(SDL_Renderer* renderer) override;
        bool WasClicked(int mx, int my, int ww, int wh) override;
};