#pragma once

class UIClickable {
    public:
        virtual bool WasClicked(int x, int y) = 0;
};