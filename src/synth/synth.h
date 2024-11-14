#include <fluidsynth.h>

class Synth {
    public:
        static void Init();
        static fluid_synth_t* GetSynth();
        ~Synth();
    private:
        static fluid_settings_t* settings;
        static fluid_synth_t* synth;
        static fluid_audio_driver_t* driver;
};