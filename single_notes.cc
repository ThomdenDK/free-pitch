#include <iostream>
#include <string>
#include "single_notes.h"
#include "note.h"

void SingleNotes::Start() {
    std::cout << "Type Y when you are ready!\n";
    std::string user_input = "";
    while (user_input != "Y") {
        std::cin >> user_input;
    }
    bool guess_correct;
    Note note;
    while (user_input != "q") {
        note.Randomize(60, 72);
        note.Play();
        std::cout << "Playing...\n";
        std::cin >> user_input;
        guess_correct = (note.AsString() == user_input);
        if (guess_correct) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Incorrect!\n";
        }
    }
    return;
}