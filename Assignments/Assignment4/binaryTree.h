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

 node<T>* root;

BinaryTree()
{
    this->root = nullptr;
}

BinaryTree(T data)//constructor sets root
{
   this->root = new node<T> (data);   
}

int FindHeight(node<T>* n, int curr_Height) const //finds height by checking if node is null, then increments height counter for each subtree, returning height of longest subtree
{
    if(n == nullptr)
    {
        return curr_Height;
    }
    else
    {
        int left = FindHeight(n.left, (curr_Height + 1));
        int right = FindHeight(n.right, (curr_Height + 1));

        if(left > right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

int NumberOfNodes(node<T>* n) const
{
    if(n == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + NumberOfNodes(n.left) + NumberOfNodes(n.right);//returns 1 from previous node and keeps branching through subtrees, incrementing count by one until all nodes are null
    }
}

int NumberOfLeaves(node<T>* n) const
{
    if(n == nullptr)
    {
        return 0;
    }
    else if(n.left == nullptr && n.right == nullptr)
    {
        return 1;
    }
    else
    {
        return NumberOfLeaves(n.left) + NumberOfLeaves(n.right);
    }
}

bool IsEmpty()
{
    if(root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Search(node<T>* n, const T& searchItem) const
{
    if(n == nullptr)
    {
        return false;
    }
    else if(n.data == searchItem)
    {
        return true;
    }
    else if(searchItem < n.data)
    {
        return Search(n.left, searchItem);
    }
    else 
    {
        return Search(n.right, searchItem);
    }

}
// Function to determine if searchItem is in the binary
// tree.
// Postcondition: Returns true if searchItem is found in the
// search tree; otherwise, returns false.

void Insert(node<T>* n, const T& insertItem)
{
    if(n == nullptr)
    {
        n = new node<T>(insertItem);
    }
    else if(insertItem < n.data)
    {
        Insert(n.left, insertItem);
    }
    else
    {
        Insert(n.right, insertItem);
    }
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
        DeleteNode(root, deleteItem);
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
void DeleteFromTree(node<T>* &p)
{
    if(n.left == nullptr && n.right == nullptr)
    {
        delete n;
        n = nullptr;
    }
    else if(n.left != nullptr && n.right == nullptr)
    {
        node<T>* temp = n;
        n = n.left
        delete temp;
    }
    else if(n.left == nullptr && n.right != nullptr)
    {
        node<T>* temp = n;
        n = n.right;
        delete temp;
    }
    else
    {
        node<T>* temp = n.right;
        while(temp.left != nullptr)
        {
            temp = temp.left;
        }
        n.data = temp.data;
        DeleteFromTree(n.right, temp.data);
    }
}
//Function to delete the node to which p points is deleted
//from the binary search tree.
//Postcondition: The node to which p points is deleted
// from the binary search tree.
};

void DeleteFromTree(node<T>* &n, const T &data)
{
    if(n == nullptr)
    {
        return;
    }
    else if (data < n.data)
    {
        DeleteFromTree(n.left, data);
    }
    else if(data > n.data)
    {
        DeleteFromTree(n.right, data);
    }
    else
    {
        DeleteFromTree(n);
    }
}

#endif