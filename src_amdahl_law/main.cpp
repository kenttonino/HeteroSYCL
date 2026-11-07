/*
 * Ahmadal's Law Forula = 1 / 1 - p
 *
 * This sample is trying to test only the amdahl's law using DAXPY implmentation we have.
 *  - Run implementation without parallelism -> measure time.
 *  - Run implementation with parallelism -> measure time.
 *  - Check the factor of speed-up.
 * */

#include <iostream>

int main(int argc, char** argv) {
  std::cout << argc << std::endl;

  return 0;
}
