#include <iostream>

using namespace std;

void FindSmallest(int *a, int *b, int *c);

int main()
{
    int *a = new int, *b = new int, *c = new int;
    int *nums[]= {a, b, c};
    cin >> *a >> *b >> *c;
    
    FindSmallest(a, b, c);
    cout << *a << " " << *b << " " << *c << endl;
    delete a;
    delete b;
    delete c;
}

void FindSmallest(int *a, int *b, int *c)
{
    for(int i = 0; i < 2; i++)
    {
        int temp;
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