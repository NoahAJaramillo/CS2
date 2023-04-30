CXX = g++

CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = Assignment4

CPPFILES = main.cpp BinarySearchTree.h BinaryTree.h node.h

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o 
	./$(PROGRAM) $(FILENAME)

clean:
	rm *.o Assignment4
