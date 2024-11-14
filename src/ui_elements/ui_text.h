#include <string>
#include "ui_element.h"

class SDL_Rect;
class SDL_Renderer;
class SDL_Color;

class UIText : public UIElement {
    private:
        std::string str;
        SDL_Color color;
        SDL_Rect rect;
    public:
        UIText(std::string str, SDL_Color color, SDL_Rect rect);
        void Draw(SDL_Renderer* renderer) override;
};