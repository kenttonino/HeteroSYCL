#ifndef DAXPY_HPP
#define DAXPY_HPP
#include <vector>

void before_daxpy(
  const int n,
  const std::vector<float> y
);

void after_daxpy(
  const int n,
  const float a,
  const std::vector<float> y
);

void daxpy(
  int n,
  float a,
  const float* x,
  float* y
);

#endif
