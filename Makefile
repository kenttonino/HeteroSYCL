.PHONY: build run-hello

build:
	icpx -fsycl ./src-hello/main.cpp -o ./build/src-hello

run-hello: build
	./build/src-hello
