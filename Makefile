.PHONY: build run-hello

build:
	icpx -fsycl -std=c++17 ./src_hello/main.cpp -o ./build/src_hello

run-hello: build
	./build/src_hello
