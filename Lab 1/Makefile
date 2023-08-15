.PHONY: all test clean

all: pointer.cc
	g++ -std=gnu++20 -o pointer pointer.cc

test: pointer
	./pointer

clean:
	rm -f pointer