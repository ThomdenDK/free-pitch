#include "i_free_pitch.h"
#include "free_pitch/free_pitch.h"
#include "window/window.h"
#include "states/main_menu.h"

int main() {
    auto main_menu = MainMenu();
    auto window = Window();
    auto fp = FreePitch(window, main_menu);
    fp.Run();
    return 0;
}