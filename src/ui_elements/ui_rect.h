#include "ui_element.h"
#include "prop_rect.h"

class SDL_Renderer;
class SDL_Color;
struct PropRect;

class UIRect : public UIElement {
    private:
        PropRect prop_rect;
        SDL_Color color;
    public:
        UIRect(PropRect prop_rect, SDL_Color color);
        void Draw(SDL_Renderer* renderer) override;
        PropRect GetRect();
};