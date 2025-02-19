#include <windows.h>
#include "simulation.h"

int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8
    Simulation sim(20.0); // Start at 20°C
    sim.run();
    sim.print_results();
    return 0;
}