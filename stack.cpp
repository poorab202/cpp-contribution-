#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isempty()//to check whether the sta
    {
        if (top == -1)
            return (true);
        else
            return (false);
    }
    bool isfull()
    {
        if (top == 4)
            return (true);
        else
            return (false);
    }
    void push(int val)
    {
        if (isfull())
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            arr[++top] = val;
        }
    }
    int pop()
    {
        if (isempty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            int val = arr[top];
            arr[top--] = 0;
            return (val);
        }
    }
    int count()
    {
        return (top + 1);
    }
    int peek(int index)
    {
        if (isempty())
        {
            cout << "stack is empty";
            return 0;
        }
        else
            return (arr[index]);
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
main()
{
    Stack s1;
    int option, value, position;
    do
    {
        system("cls");
        cout << endl;
        cout << "0. exit" << endl;
        cout << "1 . push()" << endl;
        cout << "2 . pop()" << endl;
        cout << "3 . isempty()" << endl;
        cout << "4 . isfull()" << endl;
        cout << "5 . count()" << endl;
        cout << "6 . peek()" << endl;
        cout << "7 . display()" << endl;

        cout << endl
             << endl
             << "Which operation do you want to perform? Enter the operation number here:";

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an interger to push inside a stack :";
            cin >> value;
            s1.push(value);
            cout << "entered sucessfully" << endl;
            system("pause");
            break;
        case 2:
            cout << "pop function called - poped value : " << s1.pop() << endl;
            system("pause");
            break;
        case 3:
            if (s1.isempty() == 1)
                cout << "stack is empty" << endl;
            else
                cout << "stack is not empty" << endl;
            system("pause");
            break;
        case 4:
            if (s1.isfull() == 1)
                cout << "stack is full" << endl;
            else
                cout << "stack is not full" << endl;
            system("pause");
            break;
        case 5:
            cout << "count function called - total value are : " << s1.count() << endl;
            system("pause");
            break;
        case 6:
            cout << "enter position of the item you want to peek : ";
            cin >> position;
            cout << "peek function called - value at position " << position << " is " << s1.peek(position) << endl;
            system("pause");
            break;
        case 7:
            cout << "values inside the stack are : " << endl;

            s1.display();
            system("pause");
        }
    } while (option != 0);
}

