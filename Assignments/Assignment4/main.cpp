/*
1- Load your tree with data - generate 100,000 long int in the range of 100 to
100,000,000 and insert in the tree, use cstdlib rand() function – use last 4 digit
of your 700 number as seed.
2- Output the data in order to a data file, name to be passed in as command line
argument at run time. Format 3 to 5 numbers per line tab separated.
3- Test all 11 functions in the tree as defined above and as specified below.
4- Output each of the 11 tests in a clear section to the file, output the tree
height to the file.
5- Output the run time from start to finish in minutes, seconds and milliseconds to
the file (you can use ctime or chrono).
6- No user interactions I/O nothing on the display.
7- You may (probably need to) if you wish add 2 functions to your driver to update
and print values passed by reference or use any other mechanism to make
your code carry out the tasks specified above.

*/

#include <fstream>
#include <chrono>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "binaryTree.h"
#include "binarySearchTree.h"

using namespace std;


void FillTree(BinaryTree<long int>);

int main()
{
    BinaryTree<long int>* tree(); 
}

void FillTree(BinaryTree<long int> tree)
{
    srand(4331248);
    long int arr [100];
    long int x;
    for(int i = 0; i < 100; i++)
    {
        x = rand() % 999999900 + 100;
        arr[i] = x;
    }
    for(int i = 0; i < 100; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
}