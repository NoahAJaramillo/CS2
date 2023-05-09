/*
a = x
If |a^2 - x| <= e then a is square root of x within tolerance, otherwise replace a with (a^2 + x)(2a), then repeat first step
write recursive program to test.
*/
#include <iostream>

using namespace std;

double NewtonsMethod(double, double);



int main()
{
    cout << "Which number do you want the square root of: ";
    double num;
    cin >> num;
    double a = num;
    double answer = NewtonsMethod(num, a);
    cout << answer;
}

double NewtonsMethod(double x, double a)
{

    double tolerance = .01;
    if (a < 0)
    {
        a = a * (-1.0);
    }
    if ((a * a - x) <= tolerance)
    {
        return a;
    }
    else
    {
        a = (a + (x / a)) * .5;
        //cout << "This is a before new method: " << a << endl;
        return NewtonsMethod(x, a);
    }

    return 0;
}

/*
if(((a * a) - x) <= tolerance && ((a * a) - x) > 0)
    {
        cout << a << endl;
        return a;
    }
    else
    {
        if((a * a) - x < 0)
        {
            y = ((a*a + x) * 2) * a * -1;
            return NewtonsMethod(y);
        }
        y = (a*a + x) * 2 * a;
        return NewtonsMethod(y);
    }
*/