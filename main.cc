#include "include/free_pitch.h"
#include "include/initialize_free_pitch.h"

int main() {
    // Dependency injections
    FreePitch* fp = InitializeFreePitch();
    fp->Run();
    return 0;
}