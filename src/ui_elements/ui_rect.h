#include "ui_element.h"

class SDL_Renderer;
class SDL_Rect;
class SDL_Color;
struct PropRect;

class UIRect : public UIElement {
    private:
        SDL_Rect rect;
        SDL_Color color;
    public:
        UIRect(PropRect prop_rect, SDL_Color color);
        void Draw(SDL_Renderer* renderer) override;
        SDL_Rect GetRect();
};