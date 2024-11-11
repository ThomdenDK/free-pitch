#include <random>
#include <string>
#include <fluidsynth.h>
#include <chrono>
#include <thread>
#include "note.h"
#include "notenames.h"
#include "synth.h"

// Function to play a note using FluidSynth on a separate thread
void playNote(fluid_synth_t* synth, int channel, int key, int velocity, int duration) {
    fluid_synth_noteon(synth, channel, key, velocity);
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    fluid_synth_noteoff(synth, channel, key);
}

Note::Note() {
    synth = Synth::GetSynth();
}

void Note::SetKeyIndex(int index) {
    key_index = index;
}

void Note::Randomize(int from, int to) {
    key_index = rand() % (to - from) + from;
}

void Note::Play() {
    int channel = 0;
    int velocity = 80;
    int duration = 2000;  // Duration in milliseconds
    std::thread noteThread(playNote, synth, channel, 
        key_index, velocity, duration);
    noteThread.detach();
}

std::string Note::AsString() {
    return s_notenames[key_index%12];
}