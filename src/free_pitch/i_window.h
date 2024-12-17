#pragma once
class UI;

class IWindow {
    public:
        virtual void Open() = 0;
        virtual void Close() = 0;
        virtual void Render() = 0;
        virtual void DrawUI(UI& ui) = 0;
};