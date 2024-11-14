#include "include/i_free_pitch.h"
#include "include/initialize_free_pitch.h"

int main() {
    // Dependency injections
    IFreePitch* fp = InitializeFreePitch();
    fp->Run();
    return 0;
}