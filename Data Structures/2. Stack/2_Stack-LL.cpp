// #include<iostream.h>
// #include<conio.h>
// #include<stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    int maxSize;
    int top;
    Node(int data, int size) : data(data), next(NULL), maxSize(size), top(-1) {}
};

class StackLinkedList
{

public:
    // Method to check if the stack is empty
    int isEmpty(struct Node *&header)
    {
        if (header == NULL || header->top == -1)
            return 1;
        else return 0;
    }

    // Method to check if the stack is full
    int isFull(struct Node *&header)
    {
        if (header != NULL && header->top == header->maxSize - 1)
            return 1;
        else
            return 0;
    }

    // Push to stack
    void push(struct Node *&header)
    {
        if (isFull(header))
        {
            cout << "Stack overflow. Cannot push element.\n";
            return;
        }

        int data;
        cout << "Enter data for the new Node: ";
        cin >> data;

        if (header->top == -1)
        {
            header->data = data;
            header->top++;
            // cout << endl << ".top = " << header->top << endl;
            return;
        }

        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = header;
        new_node->maxSize = header->maxSize;
        new_node->top = header->top + 1;
        header = new_node;

        // cout << endl << "top = " << header->top << endl;
    }

    // Pop first element from the Stack
    void pop(struct Node *&header)
    {
        if (isEmpty(header))
        {
            cout << "Stack underflow. Cannot pop element.\n";
            return;
        }

        struct Node *temp = header;
        header = header->next;
        free(temp);
        // delete temp;

        header->top--;

        cout << "First Node deleted successfully." << endl;
    }

    // Peep - Diplay the first element in the Stack
    void peep(struct Node *&header)
    {
        if (isEmpty(header))
        {
            cout << "Stack is empty. Cannot peep.\n";
            return;
        }
        cout << "Top element of the stack: " << header->data << "\n";
    };

    // Display SLL
    void display_Stack(struct Node *header)
    {
        if (isEmpty(header))
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack: ";
        struct Node *current = header;
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};


// void main()
int main()
{
    // clrscr();
    struct Node *header = NULL;

    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    // Create a stack with a maximum size of 'size'
    StackLinkedList stackLL;

    // Initialize header with maxSize
    header = new Node(0, size);

    int choice;
    do
    {
        cout << "\n----MENU----";
        cout << "\n1. Display Stack";
        cout << "\n2. Push into Stack";
        cout << "\n3. Pop from Stack";
        cout << "\n4. Peep from Stack";
        cout << "\n5. Check if Stack is empty?";
        cout << "\n6. Check if Stack is full?";
        cout << "\n7. Exit";
        cout << "\n ---- \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            stackLL.display_Stack(header);
            break;
        case 2:
            stackLL.push(header);
            break;
        case 3:
            stackLL.pop(header);
            break;
        case 4:
            stackLL.peep(header);
            break;
        case 5:
            cout << "Stack is " << (stackLL.isEmpty(header) ? "empty." : "not empty.") << "\n";
            break;
        case 6:
            cout << "Stack is " << (stackLL.isFull(header) ? "full." : "not full.") << "\n";
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    // getch();
    return 0;
}