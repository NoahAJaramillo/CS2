#include "sort.h"

static int n, nlast, nfirst, cCount;
static int* value;

void Sort(int arr[],int nval,int& ncomp)
{
    n = nval;
    cCount = 0;
    nfirst = 0;
    Quicksort(arr, nfirst, nlast);
}

void Quicksort(int arr[], int left, int right)
{
    int Pivot;
    Partition(arr, left, right, Pivot);
    Quicksort(arr, left, Pivot-1);
    Quicksort(arr,Pivot+1, right);
}

bool Compare(int x, int y)
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

void Partition(int arr[], int low, int high, int& pivot)
{
    int LIndex, RIndex, PValue;
    PValue = arr[low];
    LIndex = low;
    RIndex = high;
    while (Compare(LIndex, RIndex) && Compare(arr[LIndex], PValue))
    {
        LIndex++;
        while(Compare(arr[LIndex], PValue))
        {
            LIndex++;
        }
        RIndex--;
        while(Compare(PValue, arr[RIndex]))
        {
            RIndex--;
        }
        if(Compare(LIndex, RIndex))
        {
            swap(&arr[LIndex],&arr[RIndex]);
        }
    }
    pivot = RIndex;
    swap(&arr[low],&arr[RIndex]);
}

void swap(int* l, int* r)
{
    int* temp;
    temp = l;
    *l = *r;
    *r = *temp;
}

