## Description

> - Learning heterogeneous compute architectures through Intel oneAPI and SYCL using DPC++ and C/C++.

<br />
<br />
<br />



## Local Setup

> - You need to setup a workspace and this in your `.bashrc`.

```sh
# Do not copy totally the path, this is on my machine only.
DPCPP_HOME="/home/kenttonino/Documents/opensource/sycl_workspace"
export PATH="$DPCPP_HOME:$PATH"
source ~/.bashrc
```

> - Go to the __DPCPP_HOME__ directory and setup the LLVM SYCL for DPC++ Compiler.

```sh
cd $DPCPP_HOME
git clone https://github.com/intel/llvm -b sycl
```

> - Configure and compile the LLVM cloned repository.

```sh
python $DPCPP_HOME/llvm/buildbot/configure.py
python $DPCPP_HOME/llvm/buildbot/compile.py
```

<br />
<br />
<br />



## Learning Resources

> - https://intel.github.io/llvm/
