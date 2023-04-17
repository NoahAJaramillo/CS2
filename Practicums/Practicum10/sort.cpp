#include "sort.h"

static int n, nlast, nfirst, cCount;
static int* value;

bool Compare(int x, int y, int& cCount)
{
    if(x < y)
    {
        cCount++;
        return true;
    }
    else
    {
        cCount++;
        return false;
    }
}

void Quicksort(int arr[], int left, int right)
{
    int Pivot;
    Partition(arr, left, right, Pivot);
    Quicksort(arr, left, Pivot-1);
    Quicksort(arr,Pivot+1, right);
}

void Partition(int arr[], int low, int high, int& pivot)
{
    int LIndex, RIndex, PValue;
    PValue = arr[low];
    LIndex = low;
    RIndex = high;
    while (LIndex < RIndex)
    {
        while (LIndex < RIndex && Compare(arr[RIndex], PValue, cCount))
        {
            RIndex--;
        }
        if (LIndex < RIndex)
        {
            arr[LIndex++] = arr[RIndex];
        }
        while (LIndex < RIndex && Compare(arr[LIndex], PValue, cCount))
        {
            LIndex++;
        }
        if (LIndex < RIndex)
        {
            arr[RIndex--] = arr[LIndex];
        }
    }
    arr[LIndex] = PValue;
    pivot = LIndex;
}

void swap(int* l, int* r)
{
    int temp;
    temp = *l;
    *l = *r;
    *r = temp;
}



