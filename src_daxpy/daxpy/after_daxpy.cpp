#include <iostream>
#include <vector>

void after_daxpy(
  const int n,
  const double a,
  const std::vector<double> y
) {
 std::cout << "\nAfter daxpy (a=" << a << ", y = a*x + y):\n";

 for (int i = 0; i < n; i++) {
   std::cout << "  y[" << i << "] = " << y[i] << "\n";
 }
}
