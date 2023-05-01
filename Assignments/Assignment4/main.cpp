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
#include "node.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
//#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    auto start = chrono::steady_clock::now();
    string output_file = argv[1];
    //usleep(100000000);
    srand(4331248); // seed random num generator

    BinarySearchTree<long> tree;
    
    for (int i = 0; i < 100000; i++) // fills tree
    {
        long num = rand() % 99999901 + 100;
        tree.Insert(num);
    }

    ofstream fout(output_file);

    bool empty = tree.IsEmpty();
    srand(time(NULL));
    long searchItem = rand() % 99999901 + 100;
    bool found = tree.Search(searchItem);
    tree.Insert(searchItem);
    tree.DeleteFromTree(tree.root, searchItem);
    int height = tree.FindHeight(tree.root, 0);
    int nodesNum = tree.NumberOfNodes(tree.root);
    int leavesNum = tree.NumberOfLeaves(tree.root);

    if (empty == 0)
    {
        fout << "tree is not empty" << endl;
    }
    else
    {
        fout << "tree is empty" << endl;
    }
    fout << "Found " << searchItem << ": " << found << endl;
    fout << "Height: " << height << endl;
    fout << "Number of nodes: " << nodesNum << endl;
    fout << "Number of leaves: " << leavesNum << endl;

    fout << "Tree contents: " << endl;
    tree.printTree(fout);

    auto end = chrono::steady_clock::now();
    auto difference = end - start;
    auto ms = chrono::duration_cast<chrono::milliseconds>(difference).count();
    auto sec = chrono::duration_cast<chrono::seconds>(difference).count() % 60;
    auto min = chrono::duration_cast<chrono::minutes>(difference).count();

    fout << "Run time: " << min << " minutes, " << sec << " seconds, " << ms << " milliseconds" << endl;
    fout.close();

    tree.DestroyTree(tree.root);
}
