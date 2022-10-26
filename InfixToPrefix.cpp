//Code to convert infix expression into prefix.
#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return 0;
}
string infixToPrefix(string infix)
{
    stack<char> stack;
    string prefix;
    reverse(infix.begin(), infix.end());
    for (int i = 0; i <= infix.length() - 1; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    for (int i = 0; i <= infix.length() - 1; i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            stack.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack.top() != '(')
            {
                prefix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            if (stack.empty())
            {
                stack.push(infix[i]);
            }
            else if (precedence(infix[i]) > precedence(stack.top()))
            {
                stack.push(infix[i]);
            }
            else if (precedence(infix[i]) == precedence(stack.top()) && infix[i] == '^')
            {
                prefix += stack.top();
                stack.pop();
                stack.push(infix[i]);
            }
            else if (precedence(infix[i]) == precedence(stack.top()))
            {
                stack.push(infix[i]);
            }
            else
            {
                while (!stack.empty() && (infix[i]) < precedence(stack.top()))
                {
                    prefix += stack.top();
                    stack.pop();
                }
                stack.push(infix[i]);
            }
        }
    }
    while (!stack.empty())
    {
        prefix += stack.top();
        stack.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return (prefix);
}
int main()
{
    string infix, prefix;
    cout << "Enter any infix expression :";
    cin >> infix;
    prefix = infixToPrefix(infix);
    cout << "Equivalent prefix expression : " << prefix;
}
