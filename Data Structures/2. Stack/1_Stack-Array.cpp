// #include<iostream.h>
// #include<conio.h>
// #include<stdlib.h>

#include <iostream>
using namespace std;

class Stack
{
private:
    int maxSize;
    int top;
    int *stackArray;

public:
    // Constructor to initialize the stack with a given size
    Stack(int size)
    {
        maxSize = size;
        top = -1;
        stackArray = (int*)malloc(size * sizeof(int));
        // stackArray = new int[maxSize];
    }

    // Destructor to free the dynamically allocated memory
    ~Stack()
    {
        delete[] stackArray;
    }

    // Method to check if the stack is empty
    bool isEmpty()
    {
        return (top == -1);
    }

    // Method to check if the stack is full
    bool isFull()
    {
        return (top == maxSize - 1);
    }

    // Method to push an element onto the stack
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow. Cannot push element.\n";
            return;
        }
        stackArray[++top] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    // Method to pop an element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow. Cannot pop element.\n";
            return;
        }
        stackArray[top--] = 0;
        cout << "Popped " << stackArray[top--] << " from the stack.\n";
    }

    // Method to peep at the top element of the stack
    void peep()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peep.\n";
            return;
        }
        cout << "Top element of the stack: " << stackArray[top] << "\n";
    }

    // Method to display the elements of the stack
    void displayStack()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << stackArray[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{

    // clrscr();
    int size, key;
    cout << "Enter the size of the stack: ";
    cin >> size;

    // Create a stack with a maximum size of 'size'
    Stack myStack(size);

    int choice;
    do
    {
        cout << "\n---Stack Implementation using Array - MENU----";
        cout << "\n1. Push into Stack";
        cout << "\n2. Peep into Stack";
        cout << "\n3. Pop from Stack";
        cout << "\n4. Display into Stack";
        cout << "\n5. Check if stack is Full.";
        cout << "\n6. Check if stack is Empty.";
        cout << "\n7. Exit Program.";
        cout << "\n ---- \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data to be pushed: ";
            cin >> data;
            myStack.push(data);
            break;
        case 2:
            myStack.peep();
            break;
        case 3:
            myStack.pop();
            break;
        case 4:
            myStack.displayStack();
            break;
        case 5:
            myStack.isFull();
            break;
        case 6:
            myStack.isEmpty();
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 13);
    // getch();

    return 0;
}
