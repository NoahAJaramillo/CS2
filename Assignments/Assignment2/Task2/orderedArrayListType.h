#include "../Task1/arrayListType.h"

using namespace std;

template<typename T>
class OrderedListType : public listType<class T>
{
public:

    OrderedListType(int listSize ) : listType(listSize) {}
    OrderedListType() : listType() {}

    void insert(T num)
    {
        listType<T>::insert(num);
        listType<T>::sort();
    }

    void deleteItem(T num)
    {
        listType<T>::deleteItem(num);
        listType<T>::sort();
    }
};

