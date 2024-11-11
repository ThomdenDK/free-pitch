#include <iostream>
#include <string>
#include "free_pitch.h"
#include "synth.h"
#include "single_notes.h"

int FreePitch::Run() {
    std::cout << "Welcome to free pitch\n";
    Synth::Init();
    std::cout << "Type 1 to guess single notes. \
    You can type q/Q at any time to quit\n";
    std::string user_input = "";
    while (user_input != "1") {
        std::cin >> user_input;
    }
    SingleNotes single_notes = SingleNotes();
    single_notes.Start();
    return 0;
}