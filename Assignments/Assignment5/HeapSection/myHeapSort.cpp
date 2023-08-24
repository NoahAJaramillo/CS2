


#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

void FillVector(int size, vector<int>&, vector<int>&);//fills arrays with similar random numbers
void HeapSort(vector<int>&);//sorts individual arrays
void STLHeapSort(vector<int>&);
void CompareTimes(vector<int>&, vector<int>&);//compares times between sorts

int main()
{
    int size = 2000;
    vector<int> vec1;
    vector<int> vec2;

    FillVector(size, vec1, vec2);
    CompareTimes(vec1, vec2);

    return 0;
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

void HeapSort(vector<int>& vec)
{
    int size = vec.size();

    //build max heap
    for (int i = (size / 2 - 1); i >= 0; i--)
    {
        //heaps the sub at index i
        int parent = i;
        while(true)
        {
            int largest = parent;
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;

            //compares parent with left
            if(left < size && vec[left] > vec[largest])
            {
                largest = left;
            }

            //compares largest with right
            if(right < size && vec[right] > vec[largest])
            {
                largest = right;
            }

            //if largest is not parent, swap and continue heaping
            if(largest != parent)
            {
                swap(vec[parent], vec[largest]);
                parent = largest;
            }
            else
            {
                break;
            }
        }
    }

    //sort
    for(int i = size - 1; i > 0; i--)
    {
        ///move to the end
        swap(vec[0], vec[i]);

        //heap reduced heap
        int parent = 0;
        while(true)
        {
            int largest = parent;
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;

            //copare parent with left
            if(left < i && vec[left] > vec[largest])
            {
                largest = left;
            }

            //compare largest with right
            if(right < i && vec[right] > vec[largest])
            {
                largest = right;
            }

            //if largest not parent, swap and continue
            if(largest != parent)
            {
                swap(vec[parent], vec[largest]);
                parent = largest;
            }
            else
                break;
        }

    }
}

void STLHeapSort(vector<int>& vec)
{
    sort(vec.begin(), vec.end());
}

void CompareTimes(vector<int>& vec1, vector<int>& vec2)
{
    clock_t start, end;
    double heapSortTime, stlSortTime;

    //HeapSort
    start = clock();
    HeapSort(vec1);
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