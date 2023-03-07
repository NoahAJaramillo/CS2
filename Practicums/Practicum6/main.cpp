#include <iostream>

using namespace std;

int RecursiveSum(int num, int sum);
int FibonacciNum(long long int num, long long int sum);

int main()
{
    int num = 0;
    int sum = 0;
    cout << "What number would you like the recursive sum of?" << endl;
    cin >> num;

    cout << "Recursive sum of " << num << " equals " << RecursiveSum(num, sum) << endl;

    sum = 0;
    num = 0;
    cout << "What number would you like the Fibonacci sum of?" << endl;
    cin >> num;

    cout << "Fibonacci sum of " << num << " equals " << FibonacciNum(num, sum);


    return 0;
}

int RecursiveSum(int num, int sum)
{
    if(num == 1)
    {
        sum += 1;
        return sum;
    }
    else
    {
        sum += num;
        return RecursiveSum(num - 1, sum);
    }
}

int FibonacciNum(long long int num, long long int sum)
{
    if(num <= 2)
    {
        return 1;
    }
    else
    {
        sum = (FibonacciNum(num - 1, sum) + FibonacciNum(num - 2, sum));
        return sum;
    }
}