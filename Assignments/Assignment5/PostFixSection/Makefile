CXX = g++

CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = PostFix

CPPFILES = main.cpp NewImp.cpp

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

clean:
	rm *.o PostFix
	rm *.h.gch
