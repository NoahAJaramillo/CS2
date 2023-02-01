CXX = g++

CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = sort.exe

CPPFILES = main1.cpp

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

clean:
	@rm -f $(PROGRAM) *.o

run:
	./$(PROGRAM)

