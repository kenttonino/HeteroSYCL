## Description

> - Learning heterogeneous compute architectures through Intel oneAPI and SYCL using DPC++ and C/C++.

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

> - To run the programs, follow the scripts below.

```sh
# Build the program.
make build

# Run the specific source program you want to run.
make run-hello
```

<br />
<br />
<br />



## Learning Resources

> - https://www.intel.com/content/www/us/en/docs/dpcpp-cpp-compiler/developer-guide-reference/2026-2/overview.html
