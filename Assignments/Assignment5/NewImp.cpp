#include <iostream>
#include <string>
#include <stack>
#include "infixToPostfix.h"

using namespace std;

string infixToPostfix::getInfx()
{
    return this->infx;
}

string infixToPostfix::getPfx()
{
    return this->pfx;
}

void infixToPostfix::convertToPostfix()
{
    stack<char> stack; //STL stack

    pfx = "";
    int len = infx.length();

    for (int i = 0; i < len; i++)
    {
        if (infx[i] >= 'A' && infx[i] <= 'Z')
        {
            pfx += infx[i];
        }
        else
        {
            switch (infx[i])
            {
                case '(':
                    stack.push(infx[i]);
                    break;
                case ')':
                    while (!stack.empty() && stack.top() != '(')
                    {
                        pfx += stack.top();
                        stack.pop();
                    }

                    if (!stack.empty() && stack.top() == '(')
                        stack.pop();
                    break;
                case ';':
                case ' ':
                    break;
                default:
                    while (!stack.empty() && precedence(stack.top(), infx[i]))
                    {
                        pfx += stack.top();
                        stack.pop();
                    }
                    stack.push(infx[i]);
                    break;
            }
        }
    }

    while (!stack.empty())
    {
        pfx += stack.top();
        stack.pop();
    }
}

bool infixToPostfix::precedence(char opr1, char opr2)
{
    int prec1, prec2;

    if (opr1 == '*' || opr1 == '/')
        prec1 = 2;
    else if (opr1 == '+' || opr1 == '-')
        prec1 = 1;
    else if (opr1 == '(')
        prec1 = 0;

    if (opr2 == '*' || opr2 == '/')
        prec2 = 2;
    else if (opr2 == '+' || opr2 == '-')
        prec2 = 1;

    return (prec1 >= prec2);
}

void infixToPostfix::getInfix(string data)
{
    infx = data;
    convertToPostfix();
}

void infixToPostfix::showInfix()
{
    cout << "Infix Expression: " << infx << endl;
}

void infixToPostfix::showPostfix()
{
    cout << "Postfix Expression: " << pfx << endl;
}

infixToPostfix::infixToPostfix(string ifx)
{
    infx = ifx;
    convertToPostfix();
}