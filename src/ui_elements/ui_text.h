#include <string>
#include "ui_element.h"
#include "prop_rect.h"

class SDL_Rect;
class SDL_Renderer;
class SDL_Color;
struct PropRect;

class UIText : public UIElement {
    private:
        std::string str;
        SDL_Color color;
        PropRect prop_rect;
        bool auto_adjust_height;
    public:
        UIText(std::string str, SDL_Color color, PropRect rect, bool auto_adjust_height);
        void Draw(SDL_Renderer* renderer) override;
};