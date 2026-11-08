#include <iostream>
#include <vector>

void before_daxpy(
  const int n,
  const std::vector<double> y
) {
  std::cout << "Before daxpy: " << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << " y[" << i << "] = " << y[i] << std::endl;
  }
}
