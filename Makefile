.PHONY: build run-hello

build:
	icpx -fsycl -std=c++17 ./src_hello/main.cpp -o ./build/src_hello
	icpx -fsycl -std=c++17 ./src_daxpy/main.cpp -o ./build/src_daxpy

run-hello:
	./build/src_hello

run-daxpy:
	./build/src_daxpy
