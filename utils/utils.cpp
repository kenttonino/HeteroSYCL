#include <cstdio>

// ASCII colors.
#define BLUE "\e[0;34m"
#define GREEN "\e[0;32m"
#define REST "\e[0m"

namespace Utils {
  void newline(int lines) {
    for (int i = 0; i < lines; i++) {
      printf("\n");
    }
  }
}
