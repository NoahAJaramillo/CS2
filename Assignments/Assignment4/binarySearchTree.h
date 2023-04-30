/*The following operations are typically performed on a binary search tree:
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
#include "node.h"
#include "binaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    BinarySearchTree() : BinaryTree<T>() {}
    BinarySearchTree(T data) : BinaryTree<T>(data) {}

    // Override the Insert function to maintain the order of the binary search tree
    void Insert(node<T>* &n, const T &insertItem) override
    {
        if (n == nullptr)
        {
            n = new node<T>(insertItem);
        }
        else if (insertItem < n->data)
        {
            Insert(n->left, insertItem);
        }
        else if (insertItem > n->data)
        {
            Insert(n->right, insertItem);
        }
    }

    // a public function to insert a new element into the tree
    void Insert(const T& data)
    {
        Insert(this->root, data);
    }

    //a public function to remove an element from the tree
    void Remove(const T& data)
    {
        DeleteFromTree(this->root, data);
    }

    // Overrides the Search function to take advantage of the BinarySearchTree's structure
    bool Search(node<T>* n, const T &searchItem) const override
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

    // a public function to search for an element in the tree
    bool Search(const T& data) const
    {
        return Search(this->root, data);
    }
};
