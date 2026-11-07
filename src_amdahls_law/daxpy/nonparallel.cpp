#include <iostream>
#include <vector>

void nonparallel(void) {
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
}
