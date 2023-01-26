#include <iostream>

using namespace std;

void FindSmallest(int * a, int * b, int * c);

int main()
{
    int a, b, c;
    int nums[a,b,c];
    cin >> a, b, c;
    int* A = &a;
    int* B = &b;
    int* C = &c;
    FindSmallest(A, B, C);
    for(int i = 0; i < 3; i++)
    {
        cout << nums[i] << endl;
    }
    
}

void FindSmallest(int * a, int * b, int * c)
{
    for(int i = 0; i < 3; i++)
    {
    int * temp;
    if(*a > *b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(*a > *c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if(*b > *c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    }
}