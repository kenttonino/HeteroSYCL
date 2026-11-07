CXX = icpx -fsycl -std=c++17
PATH_HOME = ${shell pwd}

# Headers of all the sample programs.
HEADERS_DAXPY = -I${PATH_HOME}/src_daxpy/daxpy

# Source files of all the sample programs.
SOURCE_FILES_DAXYPY = ${wildcard ./src_daxpy/daxpy/*.cpp}

.PHONY: build-amdahls-law build-daxpy build-hello run-amdahls-law run-daxpy run-hello

build-amdahls-law:
	${CXX} ./src_amdahl_law/main.cpp -o ./build/src_amdahls_law

build-daxpy:
	${CXX} ${HEADERS_DAXPY} ./src_daxpy/main.cpp ${SOURCE_FILES_DAXYPY} -o ./build/src_daxpy

build-hello:
	${CXX} ./src_hello/main.cpp -o ./build/src_hello

run-amdahls-law: build-amdahls-law
	clear
	./build/src_amdahls_law --operation=${operation}

run-daxpy: build-daxpy
	./build/src_daxpy

run-hello: build-hello
	./build/src_hello
