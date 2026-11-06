#include <iostream>
#include <sycl/sycl.hpp>

int main(void) {
  sycl::queue q;

  std::string device = q.get_device().get_info<sycl::info::device::name>();
  std::cout << "Running on: " << q.get_device().get_info<sycl::info::device::name>() << std::endl;

  return 0;
}
