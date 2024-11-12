#include <fluidsynth.h>
#include <iostream>
#include "synth.h"

fluid_settings_t* Synth::settings;
fluid_synth_t* Synth::synth;
fluid_audio_driver_t* Synth::driver;

void Synth::Init() {
    settings = new_fluid_settings();
    synth = new_fluid_synth(settings);
    driver = new_fluid_audio_driver(settings, synth);

    int sfid = fluid_synth_sfload(synth, "/usr/share/sounds/sf2/FluidR3_GM.sf2", 1);
    if (sfid == FLUID_FAILED) {
        std::cerr << "Error loading SoundFont." << std::endl;
        delete_fluid_audio_driver(driver);
        delete_fluid_synth(synth);
        delete_fluid_settings(settings);
    }
}

fluid_synth_t* Synth::GetSynth() {
    return synth;
}

Synth::~Synth() {
    delete_fluid_audio_driver(driver);
    delete_fluid_synth(synth);
    delete_fluid_settings(settings);
}