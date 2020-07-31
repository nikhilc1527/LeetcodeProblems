all: build run clean

.PHONY: all

build: RegularExpressionMatching.cpp
	g++ -g -std=c++14 RegularExpressionMatching.cpp -o out -DDEBUG

run: out
	./out

clean: out
	rm -f out*
