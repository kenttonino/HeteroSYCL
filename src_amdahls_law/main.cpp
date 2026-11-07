/*
 * Ahmadal's Law Forula = 1 / 1 - p
 *
 * This sample is trying to test only the amdahl's law using DAXPY implmentation we have.
 *  - Run implementation without parallelism -> measure time.
 *  - Run implementation with parallelism -> measure time.
 *  - Check the factor of speed-up.
 * */

#include <cstring>
#include <iostream>
#include "./daxpy/daxpy.hpp"

int main(int argc, char** argv) {
  // Make sure to always pass the --operation flag.
  if (argc == 1) {
    std::cout << "No command-line arguments passed. \n" << std::endl;
    return 1;
  }

  // Make sure to pass the --operation type (parallel or nonparallel).
  if (strcmp(argv[1], "--operation=") == 0) {
    std::cout << "Pass operation type either parallel or nonparallel." << std::endl;
    return 1;
  }

  // Run the nonparallel DAXPY program.
  if (strcmp(argv[1], "--operation=nonparallel") == 0) {
    nonparallel();
    return 0;
  }

  // Run the parallel DAXPY program.
  if (strcmp(argv[1], "--operation=parallel") == 0) {
    std::cout << "Hello from parallel operation." << std::endl;
    return 0;
  }

  std::cout << "Operation invalid. Use either parallel or nonparallel." << std::endl;

  return 1;
}
