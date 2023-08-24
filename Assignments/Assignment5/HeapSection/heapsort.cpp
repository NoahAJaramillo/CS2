/*
    I found your heapsort to be clean and efficient. I originally misread the assignment and created my own heapsort,
    and i found mine was consistently over twice as long than the stl sort, while yours is just barely 1.4 times as long on average to sort compared
    to the stl sort. Not only is yours faster than mine, but it is much shorter in implementation, which I found impressive.
*/



#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

void makeMeAHeap(vector<int>& vec, int len, int x)
{
    int largest = x, left = 2 * x + 1, right = 2 * x + 2;
    if (left < len && vec[left] > vec[largest])
        largest = left;
    if (right < len && vec[right] > vec[largest])
        largest = right;
    if (largest != x)
    {
        std::swap(vec[x], vec[largest]);
        makeMeAHeap(vec, len, largest);
    }
}
void heapSort(vector<int>& vec, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        makeMeAHeap(vec, len, i);
    for (int i = len - 1; i >= 0; i--)
    {
        std::swap(vec[0], vec[i]);
        makeMeAHeap(vec, i, 0);
    }
}


void display(vector<int>& vec, int len)
{
    std::cout << "After sorting, the vec is: \n";
    for (int i = 0; i < len; ++i)
       std::cout << vec[i] << " "<< std::endl;
}

void FillVector(int size, vector<int>& vec1, vector<int>& vec2)
{
    srand(4331248);
    for(int i = 0; i < size; i++)
    {
        int randomNum = rand() % 50000;
        vec1.push_back(randomNum);
        vec2.push_back(randomNum);
    }
}

void STLHeapSort(vector<int>& vec)
{
    sort(vec.begin(), vec.end());
}

int main()
{
    int size = 2000;
    vector<int> vec1;
    vector<int> vec2;

    FillVector(size, vec1, vec2);

    clock_t start, end;
    double heapSortTime, stlSortTime;

    //HeapSort
    start = clock();
    heapSort(vec1, size);
    end = clock();
    heapSortTime = double(end - start) / CLOCKS_PER_SEC;

    //stlSort
    start = clock();
    STLHeapSort(vec2);
    end = clock();
    stlSortTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Heap Sort Time: " << heapSortTime << " seconds" << endl;
    cout << "STL Sort Time: " << stlSortTime << " seconds" << endl;
    
}
