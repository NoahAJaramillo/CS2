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

template <class T>
class BinaryTree
{
public:
    node<T> *root;

    BinaryTree()
    {
        this->root = nullptr;
    }

    BinaryTree(T data) // constructor sets root
    {
        this->root = new node<T>(data);
    }

    BinaryTree(const BinaryTree<T>& next)
    {
        root = copyTree(other.root);
    }

    node<T>* copyTree(node<T>* otherNode)
    {
        if(otherNode == nullptr)
        {
            return nullptr;
        }
        node<T>* newNode = new node<T>(othernode->data);

        newNode->left = copyTree(otherNode->left);
        newNode->right = copyTree(otherNode->right);

        return newNode;
    }

    void DeleteSubtree(node<T>* n)
    {
        if(n == nullptr)
        {
            return;
        }
        DeleteSubtree(n->left);
        DeleteSubtree(n->right);
        delete n;
    }

    ~BinaryTree()
    {
        DeleteSubtree(root);
        root = nullptr;
    }

    int FindHeight(node<T> *n, int curr_Height) const // finds height by checking if node is null, then increments height counter for each subtree, returning height of longest subtree
    {
        if (n == nullptr)
        {
            return curr_Height;
        }
        else
        {
            int left = FindHeight(n->left, (curr_Height + 1));
            int right = FindHeight(n->right, (curr_Height + 1));

            if (left > right)
            {
                return left;
            }
            else
            {
                return right;
            }
        }
    }

    int NumberOfNodes(node<T> *n) const
    {
        if (n == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + NumberOfNodes(n->left) + NumberOfNodes(n->right); // returns 1 from previous node and keeps branching through subtrees, incrementing count by one until all nodes are null
        }
    }

    int NumberOfLeaves(node<T> *n) const
    {
        if (n == nullptr)
        {
            return 0;
        }
        else if (n->left == nullptr && n->right == nullptr)
        {
            return 1;
        }
        else
        {
            return NumberOfLeaves(n->left) + NumberOfLeaves(n->right);
        }
    }

    bool IsEmpty() const
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Search(node<T> *n, const T &searchItem) const
    {
        if (n == nullptr)
        {
            return false;
        }
        else if (n->data == searchItem)
        {
            return true;
        }
        else if (searchItem < n->data)
        {
            return Search(n->left, searchItem);
        }
        else
        {
            return Search(n->right, searchItem);
        }
    }
    // Function to determine if searchItem is in the binary
    // tree.
    // Postcondition: Returns true if searchItem is found in the
    // search tree; otherwise, returns false.

    void Insert(node<T>* &n, const T &insertItem)
    {
        if (n == nullptr)
        {
            n = new node<T>(insertItem);
        }
        else if (insertItem < n->data)
        {
            Insert(n->left, insertItem);
        }
        else
        {
            Insert(n->right, insertItem);
        }
    }
    // Function to insert insertItem in the binary search tree.
    // Postcondition: If there is no node in the binary search
    //  tree that has the same info as insertItem,
    //  a node with the info insertItem is created
    //  and inserted in the binary search tree.

    void DeleteFromTree(node<T>* &n) // change p to n
    {
        if (n == nullptr) // check if n is null
        {
            return;
        }
        else if (n->left == nullptr && n->right == nullptr) // check if n has no children
        {
            delete n;
            n = nullptr;
        }
        else if (n->left != nullptr && n->right == nullptr) // check if n has only left child
        {
            node<T> *temp = n;
            n = n->left; // change n to its left child
            delete temp;
        }
        else if (n->left == nullptr && n->right != nullptr) // check if n has only right child
        {
            node<T> *temp = n;
            n = n->right; // change n to its right child
            delete temp;
        }
        else // n has both left and right children
        {
            node<T> *temp = n->right;
            while (temp->left != nullptr) // find the leftmost node in the right subtree of n
            {
                temp = temp->left;
            }
            n->data = temp->data;                 // replace the data of n with the data of the leftmost node in the right subtree of n
            DeleteFromTree(n->right, temp->data); // delete the leftmost node in the right subtree of n
        }
    }

    // Function to delete the node with data value equal to 'data' from the binary search tree rooted at n.
    // If no node has data value equal to 'data', the function does nothing.
    // Postcondition: The node with data value equal to 'data' is deleted from the binary search tree rooted at n.
    void DeleteFromTree(node<T>* &n, const T &deleteItem)
    {
        if (n == nullptr)
        {
            return;
        }
        else if (deleteItem < n->data)
        {
            DeleteFromTree(n->left, deleteItem);
        }
        else if (deleteItem > n->data)
        {
            DeleteFromTree(n->right, deleteItem);
        }
        else // n->data == data
        {
            if(n->left == nullptr && n->right == nullptr)//checks for children
            {
                delete n;
                n = nullptr;
            }
            else if(n->left != nullptr && n->right == nullptr)//check for left child
            {
                node<T> *Temp = n;
                n = n->left; //sets n to its left child
                delete temp;
            }
            else if(n->left == nullptr && n->right != nullptr)//checks for right child
            {
                node<T> *temp = n;
                n = n->right; // sets n to its right child
                delete temp;
            }
            else
            {
                node<T> *temp = n->right;
                while(temp->left != nullptr)//find most left node in right subtree
                {
                    temp = temp->left;
                }
                n->data = temp->data;// set data of n with data of leftmost node in right sub
                DeleteFromTree(n->right, temp->data);
            }
        }
    }
};

#endif
