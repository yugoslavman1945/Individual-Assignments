CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: bst

bst: driver.o BinarySearchTree.o Node.o
	$(CXX) $(CXXFLAGS) -o bst driver.o BinarySearchTree.o Node.o

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$(CXX) $(CXXFLAGS) -c BinarySearchTree.cpp

Node.o: Node.cpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

clean:
	rm -f *.o bst
