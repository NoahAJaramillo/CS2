#include <iostream>
#include <string>

using namespace std;

void Reverse(char* src);

int main()
{
    string str;
    getline(cin, str);
    Reverse(&str[0]);
    return 0;
}

void Reverse(char* src)
{
    int length = 0;
    char* ch = src;

    while(*ch != '\0')
    {
        ch++;
        length++;
    }
    
    for(int i = length; i >= 0; i--)
    {
        cout << src[i];
    }

}