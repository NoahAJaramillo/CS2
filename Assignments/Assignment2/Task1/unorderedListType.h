#include "listType.h"

using namespace std;

template<typename T>
class UnorderedListType : public listType<class T>
{
public:

    UnorderedListType(T listSize ) : listType(listSize) {}
    UnorderedListType() : listType() {}
};