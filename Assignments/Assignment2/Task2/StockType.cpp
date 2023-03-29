#include "StockType.h"
#include <string>

double StockType::getOpenPrice()
{
    return openPrice;
}
double StockType::getClosePrice()
{
    return closePrice;
}
long int StockType::getShares()
{
    return shares;
}
double StockType::getHighPrice()
{
    return highPrice;
}
double StockType::getLowPrice()
{
    return lowPrice;
}
double StockType::getPreviousPrice()
{
    return previousPrice;
}
double StockType::getPercentGain()
{
    return percentGain;
}

void StockType::setOpenPrice(double num)
{
    openPrice = num;
}
void StockType::setClosePrice(double num)
{
    closePrice = num;
}
void StockType::setShares(long int num)
{
    shares = num;
}
void StockType::setHighPrice(double num)
{
    highPrice = num;
}
void StockType::setLowPrice(double num)
{
    lowPrice = num;
}
void StockType::setPreviousPrice(double num)
{
    previousPrice = num;
}

void StockType::setSymbol(newString str)
{
    symbol = str;
}
ostream& operator<<(ostream& os, StockType& obj)
{
    os << obj.symbol << "   " << obj.getOpenPrice() << "   " << obj.getClosePrice() << "   "
        << obj.getHighPrice() << "   " << obj.getLowPrice() << "   " << obj.getPreviousPrice() << "   " << obj.getPercentGain() << "   " << obj.getShares();
    return os;
}
istream& operator>>(istream& is, StockType& obj)
{

    is >> obj.symbol;
    double price;
    is >> price;
    obj.setOpenPrice(price);
    is >> price;
    obj.setClosePrice(price);
    is >> price;
    obj.setHighPrice(price);
    is >> price;
    obj.setLowPrice(price);
    is >> price;
    obj.setPreviousPrice(price);
    long int shares;
    is >> shares;
    obj.setShares(shares);


    obj.setPercentGain();
    return is;
}

void StockType::setPercentGain()
{
    double temp = (closePrice - openPrice) / openPrice;
    percentGain = temp * 100;
}

bool StockType::operator==(const StockType& obj) const
{
    if (symbol == obj.symbol)
    {
        return true;
    }
    return false;
}
bool StockType::operator!=(const StockType& obj) const
{
    if (symbol == obj.symbol)
    {
        return false;
    }
    return true;
}
bool StockType::operator<=(const StockType& obj) const
{
    if (symbol <= obj.symbol)
    {
        return true;
    }
    return false;
}
bool StockType::operator<(const StockType& obj) const
{
    if (percentGain < obj.percentGain)
    {
        return true;
    }
    return false;
}
bool StockType::operator>=(const StockType& obj) const
{
    if (symbol >= obj.symbol)
    {
        return true;
    }
    return false;
}
bool StockType::operator>(const StockType& obj) const
{
    if (symbol > obj.symbol)
    {
        return true;
    }
    return false;
}
StockType& StockType::operator=(const StockType& obj)
{
    setOpenPrice(obj.openPrice);
    setClosePrice(obj.closePrice);
    setShares(obj.shares);
    setHighPrice(obj.highPrice);
    setLowPrice(obj.lowPrice);
    setPreviousPrice(obj.previousPrice);
    setPercentGain();
    setPercentGain();
    return *this;
}
void StockType::print()
{
    cout << this;
}
