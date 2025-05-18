#include "main.h"

int main()
{

    initializeBodies("data/solar_system.csv", 1e-9, 1e-8);
    InitialiseOpenGL();

    return 0;
}
// Compile with: g++ -fopenmp -o hello_omp hello_omp.cpp