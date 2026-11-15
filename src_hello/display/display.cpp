#include <iostream>
#include "../../utils/utils.hpp"

namespace Display {
  void program_description(void) {
    std::cout << Utils::text_blue("# ----------------------------- #");
    Utils::new_line(1);
    std::cout << Utils::text_blue("#                               #");
    Utils::new_line(1);
    std::cout << Utils::text_blue("#") << "  SYCL -> Hello World Program  " << Utils::text_blue("#");
    Utils::new_line(1);
    std::cout << Utils::text_blue("#                               #");
    Utils::new_line(1);
    std::cout << Utils::text_blue("# ----------------------------- #");
  }
}
