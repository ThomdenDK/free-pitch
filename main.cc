#include "i_free_pitch.h"
#include "free_pitch/free_pitch.h"
#include "window/window.h"
#include "states/main_menu.h"

int main() {
    auto window = Window();
    auto fp = FreePitch(window);
    auto main_menu = MainMenu(&fp);
    fp.ChangeState(&main_menu);
    fp.Run();
    return 0;
}