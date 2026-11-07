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

int main() {
  const int n = 8;
  const double a = 2.0;

  std::vector<double> x = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
  std::vector<double> y = { 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0 };

  before_daxpy(n, a, x, y);
  daxpy(n, a, x.data(), y.data());
  after_daxpy(n, a, y);

  return 0;
}
