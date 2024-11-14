#include "ui_element.h"

class SDL_Renderer;
class SDL_Rect;
class SDL_Color;

class UIRect : public UIElement {
    private:
        SDL_Rect rect;
        SDL_Color color;
    public:
        UIRect(SDL_Rect rect, SDL_Color color);
        void Draw(SDL_Renderer* renderer) override;
        SDL_Rect GetRect();
};