#include "../Task1/arrayListType.h"
#include "StockType.h"


class StockListType : public listType<StockType>
{
public:
    int sortedIndices[50];
    StockListType() : listType<StockType>() {}
private:
};
