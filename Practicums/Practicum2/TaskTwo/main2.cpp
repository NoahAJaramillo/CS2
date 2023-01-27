#include <iostream>
using namespace std;

struct employee
{
	int employee_no;
	char employee_name[128];
};

const int MAX = 5;

bool addemployee(employee*& record);	// creates an employee structure dynamically

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
		
	// add function to free all employees from the array
        
	return 0;
}

// add additional code here.


