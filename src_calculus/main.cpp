#include <cstdio>
#include <cstring>
#include <sycl/sycl.hpp>
#include "json/json.hpp"
#include "./plotter/plotter.hpp"

#define X_COUNT 10
#define CONSTANT 1.0

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

  double x_host[X_COUNT];
  double y_host[X_COUNT];

  for (int i = 0; i < X_COUNT; i++) {
      x_host[i] = (double)(i + 1);
  }

  {
      sycl::queue q;

      printf("Device: %s\n",
             q.get_device().get_info<sycl::info::device::name>().c_str());

      sycl::buffer<double, 1> x_buf(x_host, sycl::range<1>(X_COUNT));
      sycl::buffer<double, 1> y_buf(y_host, sycl::range<1>(X_COUNT));

      q.submit([&](sycl::handler &h) {
          auto x_acc = x_buf.get_access<sycl::access::mode::read>(h);
          auto y_acc = y_buf.get_access<sycl::access::mode::write>(h);

          h.parallel_for(sycl::range<1>(X_COUNT), [=](sycl::id<1> idx) {
              y_acc[idx] = CONSTANT * sycl::exp(x_acc[idx]);
          });
      });
  }

  JSON::write(x_host, y_host, X_COUNT);
  printf("Written to data/result.json\n");

  Plotter::display(X_COUNT, CONSTANT);

  return 0;
}
