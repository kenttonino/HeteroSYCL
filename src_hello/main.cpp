#include <iostream>
#include <sycl/sycl.hpp>
#include "../utils/utils.hpp"
#include "./display/display.hpp"
#include "sycl/device_selector.hpp"

const std::string secret { "Ifmmp-!xpsme\"\012" };
const auto sz = secret.size();

int main(void) {
  // Display description of the program.
  Utils::new_line(2);
  Display::program_description();
  Utils::new_line(2);

  // Setup a qeueu in offloading parallel computation.
  sycl::queue q(sycl::gpu_selector_v);

  // Show the current available device.
  std::string device = q.get_device().get_info<sycl::info::device::name>();
  std::cout << "Running on: " << Utils::text_blue(device);
  Utils::new_line(2);

  char* result = sycl::malloc_shared<char>(sz, q);
  std::memcpy(result, secret.data(), sz);

  q.parallel_for(sz, [=] (auto& i) {
    result[i] -= 1;
  }).wait();

  std::cout << result << std::endl;

  Utils::new_line(2);
  return 0;
}
