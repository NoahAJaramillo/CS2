#include <iostream>
using namespace std;

struct employee
{
	int employee_no;
	char employee_name[128];
};

const int MAX = 5;

bool addemployee(employee*& record);	// creates an employee structure dynamically
void PrintEmployees(employee* employees[]);
void DeleteEmployees(employee* employees[]);
// add your function prototypes here

int main()
{
    	employee* employees[MAX] = {NULL};
      	int i = 0;

       	for (i = 0; i < 5; i++)
		{
			if (addemployee(employees[i]))
            		break;
        }
       
	// add function to output employees
		PrintEmployees(employees);
	// add function to free all employees from the array
        
	return 0;
}

// add additional code here.

bool addemployee(employee*& record)
{
	employee* first = new employee;
	if(record = first)
	{
		cout << "Please enter employee ID #" << endl;
		cin >> first->employee_no;
		cout << "Please enter employee name" << endl;
		cin >> first->employee_name;
		return true;
	}
	else
	{
		return false;
	}
}

void PrintEmployees(employee* employees[])
{
	for(int i = 0; i < 5; i++)
	{
		cout << "Employee " << i << "'s name is " << employees[i]->employee_name;
		cout << "Employee " << i << "'s number is " << employees[i]->employee_no;
	}
}
void DeleteEmployees(employee* employees[])
{
	for(int i = 0; i < 5; i++)
	{
		delete employees[i];
	}
}
