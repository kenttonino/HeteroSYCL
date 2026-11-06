#include <iostream>
#include <sycl/sycl.hpp>

int main(void) {
  sycl::queue q;
  std::cout << "Running on: "
            << q.get_device().get_info<sycl::info::device::name>()
            << "\n";

  return 0;
}
