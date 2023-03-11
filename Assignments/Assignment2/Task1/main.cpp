#include "listType.h"
#include <cassert>

using namespace std;

void FunctionTests();

int main()
{
    FunctionTests();
}

void FunctionTests()
{
    listType<int> list(15);
    assert(list.isEmptyList() == 1);
    assert(list.isFullList() == 0);
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);
    assert(list.showLength() == 4);
    list.deleteItem(5);
    assert(list.showLength() == 3);
    list.printList();
    list.destroyList();
    assert(list.showLength() == 0);
    
    cout << "Test cases passed" << endl;
}