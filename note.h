#pragma once
#include <string>
#include <fluidsynth.h>

class Note {
    public:
        Note();
        void SetKeyIndex(int index);
        void Play();
        void Randomize(int from, int to);
        std::string AsString();
    private:
        int key_index;
        fluid_synth_t* synth;
};