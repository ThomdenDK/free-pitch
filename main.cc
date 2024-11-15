#include "include/i_free_pitch.h"
#include "src/free_pitch/free_pitch.h"
#include "src/window/window.h"
#include "src/states/main_menu.h"

int main() {
    MainMenu main_menu = MainMenu();
    Window window = Window();
    FreePitch fp = FreePitch(window, main_menu);
    fp.Run();
    return 0;
}