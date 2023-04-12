#include "sorts.h"
//quick, insertion, bubble
void QuickSort(double [], int, int)
{

}

int Partition(double [], int, int)
{

}

void Swap(double arr[],int l, int r)
{
    double temp;
    temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

void BubbleSort(double arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 1; j < size - i - 1; j++)
        {
            if(arr[i] < arr[j])
            {
                Swap(arr, i, j);
            }
        }
    }
}

void InsertionSort(double arr[], int size)
{
    int subArr = 0;
    while(subArr != size)
    {
        for(int i = subArr + 1;i < size; i++)
        {
            if(arr[subArr] > arr[i])
            {
                Swap(arr, subArr, i);
                if(subArr > 0)
                {
                    for(int j = subArr - 1; j >= 0; j--)
                    {
                        if(arr[])
                    }
                }
            }
        }
    }
}