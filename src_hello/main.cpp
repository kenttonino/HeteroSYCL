#include <iostream>
#include <sycl/sycl.hpp>
#include "../utils/utils.hpp"

const std::string secret { "Ifmmp-!xpsme\"\012" };
const auto sz = secret.size();

int main(void) {
  // Setup a qeueu in offloading parallel computation.
  sycl::queue q;

  // Show the current available device.
  std::string device = q.get_device().get_info<sycl::info::device::name>();
  std::cout << "Running on: " << device;
  Utils::newline(1);

  char* result = sycl::malloc_shared<char>(sz, q);
  std::memcpy(result, secret.data(), sz);

  q.parallel_for(sz, [=] (auto& i) {
    result[i] -= 1;
  }).wait();

  std::cout << result << std::endl;

  return 0;
}
