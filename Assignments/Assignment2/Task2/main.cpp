/*
    I declare that all material in this assessment task is my work except where there is clear acknowledgement or reference
    to the work of others. I further declare that I have complied and agreed to the CMU Academic Integrity Policy at the University
    website. http://www.coloradomesa.edu/student-services/documents
    Author's Name: Noah Jaramillo   UID(700#): 700452295  Date: 2/26/2023
*/

#include "../Task1/arrayListType.h"
#include "OrderedArrayListType.h"
#include "myString.h"
#include "StockType.h"
#include "StockListType.h"

using namespace std;

void printStocks(StockListType);
void printCategories();

int main()
{
    StockListType list;
    ifstream fin;
    fin.open("stockdata.txt");
    int i = 0;
    while (i < 7)
    {
        StockType obj;
        fin >> obj;
        list.insert(obj);
        i++;
    }

    printStocks(list);
    
    return 0;
}


void printStocks(StockListType list)
{
    long double closingAssets = 0;
    StockType* ptr = list.getElements(); 
    for(int i = 0; i < list.showLength(); i++)
    {
        closingAssets += (ptr[i].getShares()) * (ptr[i].getClosePrice());
        
    }
   
    cout << "****************** Aussie Foreign Investor's Heaven **********" << endl;
    cout << "****************** Financial Report **************************" << endl;
    printCategories();
    list.print();
    cout << "Closing Assets:                           " << closingAssets << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout.flush();
    cout << endl;
}

void printCategories()
{   cout << "Stock                 Today          Previous       Percent" << endl;
    cout << "Symbol  Open   Close  High   Low     Close          Gain     Volume" << endl;
    cout << "______  _____  _____  _____  ___     ________      ________  ______" << endl;
}