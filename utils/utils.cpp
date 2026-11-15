#include <cstdio>
#include <string>
#include <iostream>

// ASCII colors.
#define BLUE "\x1b[0;34m"
#define GREEN "\x1b[0;32m"
#define RESET "\x1b[0m"

namespace Utils {
  void new_line(int lines) {
    for (int i = 0; i < lines; i++) {
      std::cout << std::endl;
    }
  }

  std::string text_blue(std::string text) {
    return BLUE + text + RESET;
  }
}
