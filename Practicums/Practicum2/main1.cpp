#include <iostream>

using namespace std;

void FindSmallest(int * a, int * b, int * c);

int main()
{
    int *a, *b, *c;
    cin >> *a >> *b >> *c;
    cout << *a << *b << *c;
    FindSmallest(a, b, c);
    cout << *a << *b << *c;
    
}

void FindSmallest(int * a, int * b, int * c)
{
    int * temp;
    if(&a > &b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(&a > &c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if(&b > &c)
    {
        temp = b;
        b = c;
        c = temp;
    }


}