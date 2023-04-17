#include "sorts.h"
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace chrono;

//#define DEBUG

double middleTime, medianTime, TIME;//used for outputfile writing

void Test();
void WriteDataUnsorted(double*, int);
void WriteDataQuickSort(double*, int);
void WriteDataInsertionSort(double*, int);
void WriteDataBubbleSort(double*, int);
void FillArray(double*, int);

int main()
{
    Test();
    ofstream logFile("error.log"); // opens logfile for errors
    cerr.rdbuf(logFile.rdbuf());   // redirects cerr to logfile

    quickComp = quickAssgn = insertComp = insertAssgn = bubSwaps = quickCompMedian = quickAssgnMedian = 0;
    int size = 50000;

    double *list1MIDDLE = new double[size];
    double *list1MEDIAN = new double[size];
    double *list2 = new double[size];
    double *list3 = new double[size];

    try
    {
        FillArray(list1MIDDLE, size);
#ifdef DEBUG
        cout << "middle" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << list1MIDDLE[i] << endl;
        }
#endif
        FillArray(list1MEDIAN, size);
#ifdef DEBUG
        cout << "median" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << list1MIDDLE[i] << endl;
        }
#endif
        FillArray(list2, size);
        FillArray(list3, size);
    }
    catch (const exception &ex)
    {
        cerr << "Error in FillArray: " << ex.what() << endl;
    }

    try
    {
        WriteDataUnsorted(list2, size);
    }
    catch (const exception &ex)
    {
        cerr << "Error in WriteDataUnsorted: " << ex.what() << endl;
    }
    try
    {
        auto start = high_resolution_clock::now(); // starts timer
        QuickSort(list1MIDDLE, 0, size - 1, MIDDLE);
        auto end = high_resolution_clock::now();                       // end timer
        auto time = duration_cast<nanoseconds>(end - start);           // figures total time
        middleTime = static_cast<double>(time.count()) / 1000000000.0; // converts to double to allow outputfile writing
    }
    catch (const exception &ex)
    {
        cerr << "Error in QuickSort-Middle: " << ex.what() << endl;
    }
    quickAssgnMedian = quickAssgn; // allows me to use same variable for all quickSort types
    quickCompMedian = quickComp;
    try
    {
        auto start = high_resolution_clock::now();
        QuickSort(list1MEDIAN, 0, size - 1, MEDIAN);
        auto end = high_resolution_clock::now();
        auto medTime = duration_cast<nanoseconds>(end - start);
        medianTime = static_cast<double>(medTime.count()) / 1000000000.0;
        WriteDataQuickSort(list1MEDIAN, size);
    }
    catch (const exception &ex)
    {
        cerr << "Error in QuickSort-Median: " << ex.what() << endl;
    }
    try
    {
        auto start = high_resolution_clock::now();
        InsertionSort(list2, size);
        auto end = high_resolution_clock::now();
        auto time = duration_cast<nanoseconds>(end - start);
        TIME = static_cast<double>(time.count()) / 1000000000.0;
        WriteDataInsertionSort(list2, size);
    }
    catch (const exception &ex)
    {
        cerr << "Error in InsertionSort: " << ex.what() << endl;
    }
    try
    {
        auto start = high_resolution_clock::now();
        BubbleSort(list3, size);
        auto end = high_resolution_clock::now();
        auto time = duration_cast<nanoseconds>(end - start);
        TIME = static_cast<double>(time.count()) / 1000000000.0;
        WriteDataBubbleSort(list3, size);
    }
    catch (const exception &ex)
    {
        cerr << "Error in BubbleSort: " << ex.what() << endl;
    }

    try
    {
        delete[] list1MIDDLE;
        delete[] list1MEDIAN;
        delete[] list2;
        delete[] list3;
    }
    catch (const exception &ex)
    {
        cerr << "Error deleting arrays: " << ex.what() << endl;
    }

#ifdef DEBUG
    Test();
#endif
    logFile.close();
}

void Test()
{
    #ifdef DEBUG
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
#ifdef DEBUG
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
#ifdef DEBUG
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
    auto start = high_resolution_clock::now();//starts timer
    QuickSort(arr, 0, 49, MIDDLE);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<nanoseconds>(end - start);
    cout << "cpu time used: " << time.count() << " nanoseconds." << endl;
    cout << "postsort" << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
#endif
}

void WriteDataUnsorted(double *arr, int size)
{
    ofstream outFile("OriginalData.txt"); // Open the output file

    if (outFile.is_open())// Check if the file is open
    { 
        for (int i = 0; i < size; i++)
        {
            outFile << arr[i] << "\t"; // Write the current element to the file
            if ((i + 1) % 5 == 0)
            {
                outFile << endl; // Add a new line after every 5 elements
            }
        }
        outFile.close(); // Close the file
    }
    else
    {
        cout << "Unable to open file." << endl; // Output an error message if the file couldn't be opened
    }
}

void FillArray(double* arr, int size)
{
    srand(4331248);
    long int x;
    for(int i = 0; i < size; i++)
    {
        x = rand() % 936780 + 237;
        arr[i] = x;
    }
}

void WriteDataQuickSort(double* arr, int size)
{
    ofstream outFile("QuickSort.txt"); // Open the output file

    if (outFile.is_open())// Check if the file is open
    { 
        for (int i = 0; i < size; i++)
        {
            outFile << arr[i] << "\t"; // Write the current element to the file
            if ((i + 1) % 5 == 0)
            {
                outFile << endl; // Add a new line after every 5 elements
            }
        }
        outFile << endl;
        outFile << "QuickSort Middle Pivot Stats:" << endl;
        outFile << "QuickSort Comparisons: " << quickComp << endl;
        outFile << "QuickSort Assignments: " << quickAssgn << endl;
        outFile << std::fixed << setprecision(9) << "QuickSort time: " << middleTime << " seconds" << endl << endl;
        outFile << "QuickSort Median Pivot Stats:" << endl;
        outFile << "QuickSort Comparisons: " << (quickComp - quickCompMedian) << endl;
        outFile << "QuickSort Assignments: " << (quickAssgn - quickAssgnMedian) << endl;
        outFile << std::fixed << setprecision(9) << "QuickSort time: " << medianTime << " seconds" << endl << endl;
        outFile.close(); // Close the file
    }
    else
    {
        cout << "Unable to open file." << endl; // Output an error message if the file couldn't be opened
    }
}
void WriteDataInsertionSort(double* arr, int size)
{
    ofstream outFile("InsertionSort.txt"); // Open the output file

    if (outFile.is_open())// Check if the file is open
    { 
        for (int i = 0; i < size; i++)
        {
            outFile << arr[i] << "\t"; // Write the current element to the file
            if ((i + 1) % 5 == 0)
            {
                outFile << endl; // Add a new line after every 5 elements
            }
        }
        outFile << endl;
        outFile << "InsertionSort Stats:" << endl;
        outFile << "InsertionSort Comparisons: " << insertComp << endl;
        outFile << "InsertionSort Assignments: " << insertAssgn << endl;
        outFile << std::fixed << setprecision(9) << "InsertionSort time: " << TIME << " seconds" << endl;
        outFile.close(); // Close the file
    }
    else
    {
        cout << "Unable to open file." << endl; // Output an error message if the file couldn't be opened
    }
}
void WriteDataBubbleSort(double* arr, int size)
{
    ofstream outFile("BubbleSort.txt"); // Open the output file

    if (outFile.is_open())// Check if the file is open
    { 
        for (int i = 0; i < size; i++)
        {
            outFile << arr[i] << "\t"; // Write the current element to the file
            if ((i + 1) % 5 == 0)
            {
                outFile << endl; // Add a new line after every 5 elements
            }
        }
        outFile << endl;
        outFile << "BubbleSort Stats:" << endl;
        outFile << "BubbleSort swaps: " << bubSwaps << endl;
        outFile << std::fixed << setprecision(9) << "BubbleSort time: " << TIME << " seconds" << endl;
        outFile.close(); // Close the file
    }
    else
    {
        cout << "Unable to open file." << endl; // Output an error message if the file couldn't be opened
    }
}