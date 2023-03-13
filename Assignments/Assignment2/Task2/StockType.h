#include "myString.h"

#ifndef H_Stock
#define H_Stock

class StockType
{
public:

    friend ostream& operator << (ostream&, StockType&);
    friend istream& operator >> (istream&, StockType&);
    bool operator==(const StockType&) const;
    bool operator!=(const StockType&) const;
    bool operator<=(const StockType&) const;
    bool operator<(const StockType&) const;
    bool operator>=(const StockType&) const;
    bool operator>(const StockType&) const;

    newString symbol;
    void print();
    double getOpenPrice();
    double getClosePrice();
    long int getShares();
    double getHighPrice();
    double getLowPrice();
    double getPreviousPrice();
    double getPercentGain();
    void setSymbol(newString);
    void setOpenPrice(double);
    void setClosePrice(double);
    void setShares(long int);
    void setHighPrice(double);
    void setLowPrice(double);
    void setPreviousPrice(double);
    void setPercentGain(double);
    

private:
    double openPrice;
    double closePrice;
    long int shares;
    double highPrice;
    double lowPrice;
    double previousPrice;
    double percentGain = openPrice/closePrice;
    
};

#endif