#include <iostream>
#include <CL/sycl.hpp>

const std::string secret { "Ifmmp-!xpsme\"\012J(n!tpssz-!Ebwf/!" "J(n!bgsbje!J!dbo(u!ep!uibu/!.!IBM\01" };
const auto sz = secret.size();

int main(void) {
  sycl::queue q;
  std::cout << "Running on: "
            << q.get_device().get_info<sycl::info::device::name>()
            << "\n";

  return 0;
}
