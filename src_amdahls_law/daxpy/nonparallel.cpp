#include <iostream>
#include <vector>
#include <chrono>

void nonparallel(void) {
  auto start = std::chrono::steady_clock::now();
  const int n = 8;
  const double a = 2.0;

  std::vector<double> x = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
  std::vector<double> y = { 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0 };

  // Mutate the elements of y vector.
  // Formula = (scalar * vector X) + vector Y
  for (int i = 0; i < n; i++) {
    y[i] = (a * x[i]) + y[i];
  }

  // Display the mutated values of vector Y.
  for (int i = 0; i < n; i++) {
    std::cout << " y[" << i << "] = " << y[i] << std::endl;
  }

  auto end = std::chrono::steady_clock::now();
  auto total = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << total.count() << " ms " << std::endl;
}
