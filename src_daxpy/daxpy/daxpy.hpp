#ifndef DAXPY_HPP
#define DAXPY_HPP
#include <vector>

void before_daxpy(
  const int n,
  const double a,
  const std::vector<double> x,
  const std::vector<double> y
);

void after_daxpy(
  const int n,
  const double a,
  const std::vector<double> y
);

void daxpy(
  int n,
  double a,
  const double* x,
  double* y
);

#endif
