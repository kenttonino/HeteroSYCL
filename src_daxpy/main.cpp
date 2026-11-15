/*
 * A simple implementation of DAXPY
 *  D -> Double Precision (64-bit float)
 *  A -> A scalar (the constant a)
 *  X -> Vector X
 *  P -> Plus
 *  Y -> Vector Y
 * */
#include <vector>
#include <sycl/sycl.hpp>
#include "./daxpy/daxpy.hpp"
#include "../utils/utils.hpp"
#include "./display/display.hpp"

int main() {
  // Show program description.
  Utils::new_line(2);
  Display::app_description();
  Utils::new_line(2);

  // Initiate the device queue for parallel compute.
  sycl::queue q(sycl::gpu_selector_v);
  std::string device = q.get_device().get_info<sycl::info::device::name>();
  std::cout << "Running on: " << Utils::text_green(device);
  Utils::new_line(2);

  const int n = 8;
  const float a = 2.0;

  std::vector<float> x = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
  std::vector<float> y = { 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0 };

  before_daxpy(n, y);
  daxpy(q, n, a, x.data(), y.data());
  after_daxpy(n, a, y);

  Utils::new_line(2);
  return 0;
}
