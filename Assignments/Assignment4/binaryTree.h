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
class BinaryTree
{
public:

T node root;

BinaryTree(T data)
{
    node<T>* root = new node<T> (data);   
}

int FindHeight()
{

}

int NumberOfNodes()
{

}

int NumberOfLeaves()
{

}

bool IsEmpty()
{

}

bool Search(const T& searchItem) const
{

}
// Function to determine if searchItem is in the binary
// tree.
// Postcondition: Returns true if searchItem is found in the
// search tree; otherwise, returns false.

void Insert(const T& insertItem)
{

}
//Function to insert insertItem in the binary search tree.
//Postcondition: If there is no node in the binary search
// tree that has the same info as insertItem,
// a node with the info insertItem is created
// and inserted in the binary search tree.

void DeleteNode(const T& deleteItem)
{
    if(SearchItem(deleteItem))
    {

    }
    else
    {
        cout << "Item not found... Failed to delete" << endl;
    }
}
//Function to delete deleteItem from the binary search tree
//Postcondition: If a node with the same info as deleteItem
// is found, it is deleted from the binary
// search tree.
// If the binary tree is empty or deleteItem
// is not in the binary tree, an appropriate
// message is printed.

private:
void DeleteFromTree(nodeType<T>* &p)
{

}
//Function to delete the node to which p points is deleted
//from the binary search tree.
//Postcondition: The node to which p points is deleted
// from the binary search tree.
};

#endif