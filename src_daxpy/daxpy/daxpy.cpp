#include <sycl/sycl.hpp>

/*
 *
 * Basic Linear ALgebra Program (BLAS)
 *  y = a*x + y (BLAS Level 1 DAXPY)
 *  n - number of elements
 *  a - scalar multiplier
 *  x - input vector (read-only)
 *  y - input/output vector (overwritten with result)
 *
 * */
void daxpy(
  int n,
  double a,
  const double* x,
  double* y
) {
  sycl::queue q;

  // Allocate device memory for x and y vectors.
  double* d_x = sycl::malloc_device<double>(n, q);
  double* d_y = sycl::malloc_device<double>(n, q);

  // Copy host -> device.
  q.memcpy(d_x, static_cast<const void*>(x), n * sizeof(double));
  q.memcpy(d_y, static_cast<const void*>(y), n * sizeof(double));
  q.wait();

  // Kernel: each work-item computes one element in parallel.
  q.parallel_for(sycl::range<1>(n), [=](sycl::id<1> i) {
    d_y[i] = a * d_x[i] + d_y[i];
  }).wait();

  // Copy result device -> host back into y.
  q.memcpy(static_cast<void*>(y), d_y, n * sizeof(double)).wait();

  // Free device memory.
  sycl::free(d_x, q);
  sycl::free(d_y, q);
}
