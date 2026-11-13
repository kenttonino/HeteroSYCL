#include <cstdio>
#include <cstring>

int main(int argc, char** argv) {
  // Make sure to always pass the --example flag.
  if (argc == 1) {
    printf("Pass the --example flag, its required.\n");
    return 1;
  }

  // Make sure to pass the --example number.
  if (strcmp(argv[1], "--example=") == 0) {
    printf("Pass the example number. \n");
    return 1;
  }

  printf("Welcome to calculus. \n");

  return 0;
}
