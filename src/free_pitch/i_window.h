#include <string>
#include <memory>

class State;

class IWindow {
    public:
        void Open();
        void Close();
        void Render();
        void DrawStateContents(State& state);
};