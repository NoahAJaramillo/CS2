#include "arrayListType.h"

using namespace std;

template<typename T>
class UnorderedListType : public listType<T>
{
public:

    UnorderedListType(T listSize) : listType<T>(listSize) {}
    UnorderedListType() : listType<T>() {}
};
