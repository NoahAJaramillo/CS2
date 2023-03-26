#include <iostream>

using namespace std;

struct student
{
    char name[128];
    int age;
    int gender;
    int courseno;
};

int main()
{
    int n = 10;
    student* list;
    if(list = new student[n])
    {
        cout << "Allocation of student list successful" << endl;
    }
    else
    {
        cout << "Allocation of student list was unsuccessful" << endl;
    }
    
    delete[] list;
}