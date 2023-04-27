/*
The following operations are typically performed on a binary search tree:
1. Determine whether the binary tree is empty.
2. Search the binary search tree for a particular item
3. Insert an item in the binary search tree.
4. Delete an item from the binary search tree.
5. Find the height of the binary search tree.
6. Find the number of nodes in the binary search tree.
7. Find the number of leaves in the binary search tree.
8. Traverse the binary search tree (3).
9. Copy the binary search tree.
*/

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include <cassert>
#include "binaryTree.h"

using namespace std;

template<class elemType>
class BSearchTreeType: public BinaryTree<elemType>
{
public:
bool Search(const elemType& searchItem) const;
//Function to determine if searchItem is in the binary
//search tree.
//Postcondition: Returns true if searchItem is found in the
// binary search tree; otherwise, returns false.
void Insert(const elemType& insertItem);
//Function to insert insertItem in the binary search tree.
//Postcondition: If there is no node in the binary search
// tree that has the same info as insertItem,
// a node with the info insertItem is created
// and inserted in the binary search tree.
void DeleteNode(const elemType& deleteItem);
//Function to delete deleteItem from the binary search tree
//Postcondition: If a node with the same info as deleteItem
// is found, it is deleted from the binary
// search tree.
// If the binary tree is empty or deleteItem
// is not in the binary tree, an appropriate
// message is ptinted.
private:
void DeleteFromTree(nodeType<elemType>* &p);
//Function to delete the node to which p points is deleted
//from the binary search tree.
//Postcondition: The node to which p points is deleted
// from the binary search tree.
};

#endif