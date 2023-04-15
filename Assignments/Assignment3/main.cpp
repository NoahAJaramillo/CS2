#include "sorts.h"
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>

using namespace std;

//#define DEBUG

int main()
{
#ifdef DEBUG
    double arr[50];
    srand(4331248);
    double x;
    for(int i = 0; i < 50; i++)
    {
        x = rand() % 99900 + 100;
        arr[i] = x;
    }
    cout << "presort" << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    InsertionSort(arr, 50);
    cout << "postsort" << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
#endif

    double arr [] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    cout << "presort" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    BubbleSort(arr, 10);
    cout << "post sort" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
}