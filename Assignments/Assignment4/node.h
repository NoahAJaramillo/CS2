#ifndef H_node
#define H_node

template <class T>
class node
{
public:
T data;
node<T>* left;
node<T>* right;

node(T data)
{
    this->data = data;
    left = nullptr;
    right = nullptr;
}

};

#endif