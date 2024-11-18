#pragma once

class UIClickable {
    public:
        virtual bool WasClicked(int mx, int my, int ww, int wh) = 0;
};