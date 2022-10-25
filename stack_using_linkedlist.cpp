#include <iostream>
using namespace std;
class node
{
public:
    int data, key;
    node *prev;
    node()
    {
        data = 0;
        key = 0;
        prev = NULL;
    }
    node(int k, int d)
    {
        data = d;
        key = k;
        prev = NULL;
    }
};

class stack
{
public:
    node *top;
    stack()
    {
        top = NULL;
    }
    bool isempty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    node *nodeExists(int k)
    {
        node *temp = top;
        while (temp != NULL)
        {
            if (temp->key == k)
                return (temp);
            temp = temp->prev;
        }
        return(temp);
    }
    void push(node *n)
    {
        if (isempty())
        {
            top = n;
            cout << endl
                     << "Node pushed successfully!";
        }
        else
        {
            if (nodeExists(n->key) == NULL)
            {
                node *temp = top;
                top = n;
                top->prev = temp;
                cout << endl
                     << "Node pushed successfully!";
            }
            else
                cout << endl
                     << "Node already exists with same key value!\ntry with some other key value.";
        }
    }
    node *pop()
    {
        if (isempty())
        {
            cout << endl
                 << "Stack underflow!";
            return (NULL);
        }
        else
        {
            node *temp = top;
            top = top->prev;
            cout << endl
                 << "Node poped successfully!";
            return (temp);
        }
    }
    node *peek()
    {
        if (top == NULL)
        {
            cout << endl
                 << "Stack is empty!";
        }
        return (top);
    }
    void count()
    {
        if (top == NULL)
            cout << endl
                 << "No. of nodes = 0";
        else
        {
            int count = 0;
            node *temp = top;
            while (temp != NULL)
            {
                count++;
                temp = temp->prev;
            }
            cout << endl
                 << "Total no. of nodes = " << count;
        }
    }
    void display()
    {
        if (top == NULL)
            cout << endl
                 << "Stack is empty!";
        else
        {
            node *temp = top;
            cout << "STACK:";
            while (temp != NULL)
            {
                cout << endl
                     << "(key=" << temp->key << ", data=" << temp->data << ")";
                temp = temp->prev;
            }
            count();
        }
    }
};

int main()
{
    int option;
    stack s1;
    do
    {
        cout << "0. EXIT" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. PEEK" << endl;
        cout << "4. COUNT" << endl;
        cout << "5. DISPLAY" << endl;
        cout << "6. check if the queue is empty." << endl;
        cout << "Enter number corresponding to the operation you wish to perform : ";
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
        {
            node *n1 = new node();
            cout << "Enter key value for the node : ";
            cin >> n1->key;
            cout << "Enter data for the node : ";
            cin >> n1->data;
            s1.push(n1);
            break;
        }
        case 2:
        {
            node *n = s1.pop();
            if (n != NULL)
            {
                cout << "\nPoped node:\nkey=" << n->key << "\ndata=" << n->data;
            }
            delete n;
            break;
        }
        case 3:
        {
            node *n = s1.peek();
            if (n != NULL)
            {
                cout << "\ntop node:\nkey = " << n->key << ", data = " << n->data;
            }

            break;
        }
        case 4:
        {
            s1.count();

            break;
        }
        case 5:
        {
            s1.display();

            break;
        }
        case 6:
        {
            s1.isempty() ? cout << "\nStack is empty!" : cout << "\nStack is not empty!";
            break;
        }
        default:
        {
            cout << "\nInvalid input! please enter a valid input number.";
        }
        }
        if (option != 0)
        cout<<endl;
            system("pause");
            system("cls");
    } while (option != 0);
    return 0;
}
