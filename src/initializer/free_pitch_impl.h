#pragma once

class Window;

class FreePitchImpl {
    private:
        Window window;
    public:
        FreePitchImpl(Window window);
        int Run() override;
};