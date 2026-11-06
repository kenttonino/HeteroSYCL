.PHONY: build run-hello

build:
	icpx -fsycl -std=c++17 ./src-hello/main.cpp -o ./build/src-hello

run-hello: build
	./build/src-hello
