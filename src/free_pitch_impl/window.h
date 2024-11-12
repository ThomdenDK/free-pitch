#include <string>

class UIElement;
class SDL_Rect;
class SDL_Color;
class State;

class Window {
    public:
        void Open();
        void Close();
        void Render();
        void DrawStateContents(State* state);
        void Write(const char* text, SDL_Color color, SDL_Rect rect);
    private:
        void Draw(UIElement* obj);
        SDL_Renderer* renderer;
        SDL_Window* window;
};