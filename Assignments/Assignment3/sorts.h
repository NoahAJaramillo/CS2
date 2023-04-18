#include <iostream>

using namespace std;

//#define DEBUG

static int quickComp, quickAssgn, insertComp, insertAssgn, bubSwaps, quickCompMedian, quickAssgnMedian, quickCompMiddle, quickAssgnMiddle, quickCompIMedian, quickCompIMiddle, quickAssgnIMedian, quickAssgnIMiddle;

enum PivotType {
    MIDDLE,
    MEDIAN
};

bool QuickCompare(double x, double y)
{
    if(x > y)
    {
        quickComp++;
        return true;
    }
    else
    {
        quickComp++;
        return false;
    }
}

bool InsertCompare(double x, double y)
{
    if(x > y)
    {
        insertComp++;
        return true;
    }
    else
    {
        insertComp++;
        return false;
    }
}

void Swap(double* l, double* r)
{
    //cout << "l: " << *l << endl;
    //cout << "r: " << *r << endl;
    double temp;
    temp = *l;
    *l = *r;
    *r = temp;
    //cout << "l: " << *l << endl;
    //cout << "r: " << *r << endl;
}

void InsertionSort(double arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i;
        while(j > 0 && InsertCompare(arr[j-1], arr[j]))
        {
            Swap(&arr[j], &arr[j-1]);
            insertAssgn++;
            j = j - 1;
        }
    }
}

int Partition(double arr[], int low, int high, PivotType pivotType)
{
    int mid = (low + high) / 2;
    int pivot = high; // initialize pivot variable
    switch (pivotType)
    {
    case MIDDLE:
        Swap(&arr[mid], &arr[high]);
        quickAssgn++;
        break;
    case MEDIAN: // median algorithm adopted from mycplus.com/featured-articles/quicksort-in-c-programming-language/
        // Chooses the median of the first, middle, and last elements as the pivot by comparing and ordering
        if (QuickCompare(arr[low], arr[mid]))
        {
            Swap(&arr[low], &arr[mid]);
            quickAssgn++;
        }           
        if (QuickCompare(arr[low], arr[high]))
        {
            Swap(&arr[low], &arr[high]);
            quickAssgn++;
        }
        if (QuickCompare(arr[mid], arr[high]))
        {
            Swap(&arr[mid], &arr[high]);
            quickAssgn++;
        }
        Swap(&arr[mid], &arr[high]);
        quickAssgn++;
        break;
    }
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        quickComp++;
        if (arr[j] <= arr[pivot])
        {
            i++;
            Swap(&arr[i], &arr[j]);
            quickAssgn++;
        }
    }
    Swap(&arr[i+1], &arr[pivot]);
    quickAssgn++;
    return i + 1;
}

void QuickSort(double arr[], int low, int high, PivotType pivotType)
{

    if(low < high)
    {
        int pivot = Partition(arr, low, high, pivotType);//first partition
        QuickSort(arr, low, pivot - 1, pivotType); // Sorts left of pivot
        QuickSort(arr, pivot + 1, high, pivotType); // Sorts right of pivot
    }
}

void QuickSortI(double arr[], int low, int high, PivotType pivotType)
{

    if(low < high)
    {
        if (high - low + 1 < 20) 
        {
            InsertionSort(arr + low, high - low + 1);
        }
        int pivot = Partition(arr, low, high, pivotType);//first partition
        QuickSortI(arr, low, pivot - 1, pivotType); // Sorts left of pivot
        QuickSortI(arr, pivot + 1, high, pivotType); // Sorts right of pivot
    }
}

void BubbleSort(double arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool noSwap = true;//ends sort early if array is sorted
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                noSwap = false;
                Swap(&arr[j], &arr[j + 1]);
                bubSwaps++;
            }
        }
        if(noSwap == true)
            break;
    }
}





//#endif