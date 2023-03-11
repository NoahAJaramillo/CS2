#include <random>
#include <iostream>
#include <chrono>

using namespace std;

void BubbleSort(long int [], int size, long int&, long int&);
void SelectionSort(long int [], int size, long int&, long int&);
void InsertionSort(long int [], int size, long int&, long int&);

int main()
{
    long int comparisons = 0;
    long int swaps = 0;
    long int randNum;
    int size = 50;
    unsigned seed = 3.14;
    long int* list1 = new long int [size];
    long int* list2 = new long int [size];
    long int* list3 = new long int [size];
    minstd_rand0 generator (seed);

    for(int i = 0; i < 50; i++)//fill lists with random numbers
    {
        randNum = generator();
        list1[i] = randNum;
        list2[i] = randNum;
        list3[i] = randNum;
    }

    BubbleSort(list1, size, swaps, comparisons);
    cout << "BubbleSort used " << swaps << " assignments and " << comparisons << " comparisons" << endl;
    swaps = 0;
    comparisons = 0;
    SelectionSort(list2, size, swaps, comparisons);
    cout << "SelectionSort used " << swaps << " assignments and " << comparisons << " comparisons" << endl;

    for(int i = 0; i < 50; i++)
    {
        cout << "list1[" << i << "] = " << list1[i] << endl;
    }
    for(int i = 0; i < 50; i++)
    {
        cout << "list2[" << i << "] = " << list2[i] << endl;
    }
    delete[] list1;
        
}

void BubbleSort(long int arr[], int size, long int& swaps, long int& comparisons)
{
    long int temp;
    bool wasSwapped = 0;
    for(int i = 0; i < (size - 1); i++)
    {
        wasSwapped = 0;
        for(int j = 0; j < (size - i - 1); j++)
        {
            comparisons++;
            if(arr[j] > arr[j + 1])
            {
                swaps++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                wasSwapped = true;
            }
        }
        if(wasSwapped == false)
        {
            return;
        }
    }
}

void SelectionSort(long int arr[], int size, long int& swaps, long int& comparisons)
{
    long int temp;
    long int* a;
    long int* b;
    for(int i = 0; i < size - 1; i++)
    {
        a = &arr[i];
        for(int j = 1; j < size; j++)
        {cout << "here" << j << endl;
            comparisons++;
            if(*a > arr[j])
            {
                b = &arr[j];
            }
        }
        swaps++;
        temp = arr[i];
        arr[i] = *b;
        *b = temp;
    }
}

void InsertionSort(long int arr[], int size, long int& swaps, long int& comparisons)
{
    
}