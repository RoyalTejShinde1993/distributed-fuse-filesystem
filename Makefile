CXX=g++
CXXFLAGS=-std=c++17 -Wall -pthread -Iinclude -I/usr/include/fuse3
LDFLAGS=$(shell pkg-config fuse3 --libs)
SRC=$(wildcard src/*.cpp)
OUT=myfs

all:
	$(CXX) $(CXXFLAGS) $(SRC) -lfuse3 -o $(OUT)

clean:
	rm -f $(OUT)
