#include <iostream>

using namespace std;

//#define DEBUG

void Swap(double arr[],int l, int r)
{
    double temp;
    temp = arr[l];
#ifdef DEBUG
    cout << "temp: " << temp << endl;
    cout << "arr[l]: " << arr[l] << endl;
    cout << "arr[r]: " << arr[r] << endl;
#endif
    arr[l] = arr[r];
#ifdef DEBUG
    cout << "swapped arr[l]: " << arr[l] << endl;
#endif
    arr[r] = temp;
#ifdef DEBUG
    cout << "swapped arr[r]: " << arr[r] << endl;
#endif
}

void QuickSort(double arr[], int, int size)
{

}

int Partition(double arr[], int, int size)
{

}

void BubbleSort(double arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool noSwap = true;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                noSwap = false;
                Swap(arr, j, j + 1);
            }
        }
        if(noSwap == true)
            break;
    }
}

void InsertionSort(double arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i;
        while(j > 0 && arr[j-1] > arr[j])
        {
            Swap(arr, j, j-1);
            j = j - 1;
        }
    }
}



//#endif