#include "sorts.h"
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG_INS
#define DEBUG_BUB
#define DEBUG_QUICK

void Test();

int main()
{
    int size = 50000;
    quickComp, quickAssgn, insertComp, insertAssgn, bubSwaps = 0;
    Test();
    cout << "quickComp: " << quickComp << endl;
    cout << "quickAssgn: " << quickAssgn << endl;
    cout << "insertComp: " << insertComp << endl;
    cout << "insertAssgn: " << insertAssgn << endl;
}

void Test()
{
    #ifdef DEBUG_INS
    double array[50];
    srand(4331248);
    double x;
    for(int i = 0; i < 50; i++)
    {
        x = rand() % 99900 + 100;
        array[i] = x;
    }
    cout << "presort" << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << i << ": " << array[i] << endl;
    }
    InsertionSort(array, 50);
    cout << "postsort" << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << i << ": " << array[i] << endl;
    }
#endif
#ifdef DEBUG_BUB
    double arr1 [] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    cout << "presort" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << i << ": " << arr1[i] << endl;
    }
    BubbleSort(arr1, 10);
    cout << "post sort" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << i << ": " << arr1[i] << endl;
    }
#endif
#ifdef DEBUG_QUICK
    double arr[50];
    srand(4331248);
    double y;
    for(int i = 0; i < 50; i++)
    {
        y = rand() % 99900 + 100;
        arr[i] = y;
    }
    cout << "presort" << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    QuickSort(arr, 0, 49, MIDDLE);//, MEDIAN
    cout << "postsort" << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
#endif
}