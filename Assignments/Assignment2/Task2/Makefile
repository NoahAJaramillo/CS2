CXX = g++

CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = main

CPPFILES = main.cpp ../Task1/arrayListType.h ../Task1/unorderedListType.h myString.h myString.cpp OrderedArrayListType.h StockType.h StockType.cpp StockListType.h StockListType.cpp

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

clean:
	rm *.o main
