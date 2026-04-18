
CXX=g++
CXXFLAGS=-std=c++17 -Wall -pthread

SRC=$(wildcard src/*.cpp)
OUT=myfs

all:
	$(CXX) $(CXXFLAGS) $(SRC) -lfuse3 -o $(OUT)

clean:
	rm -f $(OUT)
