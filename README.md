## Description

> - Learning heterogeneous systems through Intel oneAPI and DPC++/SYCL.
> - I'm currently learning the [Data Parallel C++](https://link.springer.com/book/10.1007/978-1-4842-5574-2) book so this is an ongoing playground.
> - This is purely learning repo to tinker around the Intel oneAPI and DPC++/SYCL.
> - As I try to learn Physics or Math, I'm gonna try to implement it here.

<br />
<br />
<br />



## Local Setup

> - Please note, I'm using Debian Linux for this.

> - Install the [icpx](https://en.wikipedia.org/wiki/Intel_C++_Compiler) compiler.

```sh
# Add the Intel oneAPI repository.
wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB \
  | gpg --dearmor \
  | sudo tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null

echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] \
  https://apt.repos.intel.com/oneapi all main" \
  | sudo tee /etc/apt/sources.list.d/oneAPI.list

sudo apt update

# Install the full Base Toolkit.
sudo apt install intel-oneapi-base-toolkit

# Source the Intel oneAPI environment.
source /opt/intel/oneapi/setvars.sh

# Then, check the version.
icpx --version

# For permanent sourcing it, add it in the .bashrc file.
echo 'source /opt/intel/oneapi/setvars.sh' >> ~/.bashrc
```

> - Install [GNUPlot](https://en.wikipedia.org/wiki/Gnuplot) for displaying graph of calculation.

> - To run the programs, follow the scripts below.

```sh
# Choose either of the script below to run your preferred program.
make run-amdahls-law operation=nonparallel
make run-calculus example=1
make run-daxpy
make run-hello
```

<br />
<br />
<br />



## Learning Resources

> - https://link.springer.com/book/10.1007/978-1-4842-5574-2
> - https://www.intel.com/content/www/us/en/docs/dpcpp-cpp-compiler/developer-guide-reference/2026-2/overview.html
