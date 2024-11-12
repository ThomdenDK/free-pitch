#include <vector>
#include <SDL2/SDL.h>
#include "state.h"

class MainMenu : public State {
    private:
        std::vector<UIElement*> UI_elements;
    public:
        MainMenu();
        void HandleEvent(SDL_Event& event) override;
};