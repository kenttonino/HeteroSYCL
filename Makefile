.PHONY: build run-hello

build:
	g++ -o ./build/src-hello ./src-hello/main.cpp

run-hello: build
	./build/src-hello
