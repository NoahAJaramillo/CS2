/*
Before designing theclass to implement a binary tree as an ADT, we list various operations that are
typically performed on a binary tree:

• Determine whether the binary tree is empty.
• Search the binary tree for a particular item.
• Insert an item in the binary tree.
• Delete an item from the binary tree.
• Find the height of the binary tree.
• Find the number of nodes in the binary tree.
• Find the number of leaves in the binary tree.
• Traverse the binary tree.
• Copy the binary tree.
*/
#include "node.h"
#ifndef H_binaryTree
#define H_binaryTree

template<class T>
class binaryTree
{
public:

T node root;

binaryTree(T data)
{
    node<T>* root = new node<T> (data);   
}

bool search(const T& searchItem) const
{

}
// Function to determine if searchItem is in the binary
// tree.
// Postcondition: Returns true if searchItem is found in the
// search tree; otherwise, returns false.

void insert(const T& insertItem)
{

}
//Function to insert insertItem in the binary search tree.
//Postcondition: If there is no node in the binary search
// tree that has the same info as insertItem,
// a node with the info insertItem is created
// and inserted in the binary search tree.

void deleteNode(const T& deleteItem)
{

}
//Function to delete deleteItem from the binary search tree
//Postcondition: If a node with the same info as deleteItem
// is found, it is deleted from the binary
// search tree.
// If the binary tree is empty or deleteItem
// is not in the binary tree, an appropriate
// message is printed.

private:
void deleteFromTree(nodeType<T>* &p)
{

}
//Function to delete the node to which p points is deleted
//from the binary search tree.
//Postcondition: The node to which p points is deleted
// from the binary search tree.
};

#endif