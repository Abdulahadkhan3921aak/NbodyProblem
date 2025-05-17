#include <iostream>
#include <omp.h>
#include <OpenGL.h>

int main() {
    
    InitialiseOpenGL();

    return 0;
}
// Compile with: g++ -fopenmp -o hello_omp hello_omp.cpp