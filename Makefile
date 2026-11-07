PATH_HOME = ${shell pwd}
HEADERS_DAXPY = -I${PATH_HOME}/src_daxpy/daxpy
SOURCE_FILES_DAXYPY = ${wildcard ./src_daxpy/daxpy/*.cpp}

.PHONY: build-hello build-daxpy run-hello run-daxpy

build-hello:
	icpx -fsycl -std=c++17 ./src_hello/main.cpp -o ./build/src_hello

build-daxpy:
	icpx -fsycl -std=c++17 ${HEADERS_DAXPY} ./src_daxpy/main.cpp ${SOURCE_FILES_DAXYPY} -o ./build/src_daxpy

run-hello: build-hello
	./build/src_hello

run-daxpy: build-daxpy
	./build/src_daxpy
