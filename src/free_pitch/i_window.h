#include <string>
#include <memory>

class State;

class IWindow {
    public:
        virtual void Open() = 0;
        virtual void Close() = 0;
        virtual void Render() = 0;
        virtual void GetSize(int* w, int* h) = 0;
        virtual void DrawStateContents(State& state) = 0;
};