#include <iostream>

using namespace std;

void FindSmallest(int* a, int* b, int* c);

int main()
{

    int* a = new int, * b = new int, * c = new int;
    cin >> *a >> *b >> *c;

    int* arr[] = {a, b, c};
    FindSmallest(a, b, c);

    for(int i =0; i < 3; i++)
    {
        cout << *arr[i] << endl;
    }

    delete a;
    delete b;
    delete c;

    return 0;
}

void FindSmallest(int* a, int* b, int* c)
{
    int temp;
    for(int i = 0; i < 2; i++)
    {
        if(*a > *b)
        {
            temp = *a;
            *a = *b;
            *b = temp;
        }
        if(*b > *c)
        {
            temp = *b;
            *b = *c;
            *c = temp;
        }
    }
}