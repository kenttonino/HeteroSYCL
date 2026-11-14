#include <sycl/sycl.hpp>
#include "../plotter/plotter.hpp"
#include "../json/json.hpp"

#define X_COUNT 10
#define CONSTANT 1.0

void example_1() {
  // Array stored in main memory.
  std::vector<double> x_host(X_COUNT);
  std::vector<double> y_host(X_COUNT);

  // Fils the x_host array with range values of X_COUNT.
  for (int i = 0; i < X_COUNT; i++) {
      x_host[i] = (double)(i + 1);
  }

  // Instantiate a queue to the SYCL device.
  sycl::queue q;

  // SYCL buffers that manages memory between the host (CPU RAM) and device (GPU VRAM).
  sycl::buffer<double, 1> x_buf(x_host.data(), sycl::range<1>(X_COUNT));
  sycl::buffer<double, 1> y_buf(y_host.data(), sycl::range<1>(X_COUNT));

  printf("Device: %s\n", q.get_device().get_info<sycl::info::device::name>().c_str());

  q.submit([&](sycl::handler &h) {
    auto x_acc = x_buf.get_access<sycl::access::mode::read>(h);
    auto y_acc = y_buf.get_access<sycl::access::mode::write>(h);

    h.parallel_for(sycl::range<1>(X_COUNT), [=](sycl::id<1> idx) {
        y_acc[idx] = CONSTANT * sycl::exp(x_acc[idx]);
    });
  });

  JSON::write(x_host, y_host, X_COUNT);
  printf("Written to data/result.json\n");

  Plotter::display(X_COUNT, CONSTANT);
}
