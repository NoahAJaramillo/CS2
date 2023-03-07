CXX = g++

CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = AccountSim

CPPFILES = Account.cpp main.cpp

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

clean:
	rm *.o AccountSim