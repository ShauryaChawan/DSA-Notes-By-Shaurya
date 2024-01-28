// #include<iostream.h>
// #include<conio.h>
// #include<stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int node_count = 0;

class CircularLinkedList
{
public:
    void create_CLL(struct Node *&header);
    void display_CLL(struct Node *header);
    void insert_node_front_CLL(struct Node *&header);
    void insert_node_end_CLL(struct Node *&header);
    void insert_in_the_mid_CLL(struct Node *&header);
    void delete_first_node_CLL(struct Node *&header);
    void delete_last_node_CLL(struct Node *&header);
    void delete_desired_node_CLL(struct Node *&header);
    void search_CLL(struct Node *&header);
    void sort_CLL(struct Node *&header);
    void reverse_CLL(struct Node *&header);
    void concate_CLL(struct Node *&header, struct Node *&header_1);
};

// Create Circular Linked List
void CircularLinkedList::create_CLL(struct Node *&header)
{
    char choice;
    do
    {
        struct Node *new_node = new Node();
        cout << "Enter data for the new Node: ";
        cin >> new_node->data;
        new_node->next = NULL;

        if (header == NULL)
        {
            header = new_node;
            new_node->next = header;
        }
        else
        {
            struct Node *temp = header;
            while (temp->next != header)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = header;
        }

        node_count++;

        cout << "Do you want to add another Node? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

// Display Circular Linked List
void CircularLinkedList::display_CLL(struct Node *header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    cout << "Circular Linked List: ";
    struct Node *current = header;
    do
    {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != header);
    cout << "HEAD" << endl;
}

// Insert Node in front in CLL
void CircularLinkedList::insert_node_front_CLL(struct Node *&header)
{
    struct Node *new_node = new Node();
    cout << "Enter data for the new Node: ";
    cin >> new_node->data;
    new_node->next = header;

    struct Node *temp = header;
    while (temp->next != header)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    header = new_node;
    node_count++;
}

// Insert Node at end in CLL
void CircularLinkedList::insert_node_end_CLL(struct Node *&header)
{
    struct Node *new_node = new Node();
    cout << "Enter data for the new Node: ";
    cin >> new_node->data;
    new_node->next = header;

    if (header == NULL)
    {
        header = new_node;
        new_node->next = header;
    }
    else
    {
        struct Node *temp = header;
        while (temp->next != header)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }

    node_count++;
}

// Insert Node in the Middle in CLL
void CircularLinkedList::insert_in_the_mid_CLL(struct Node *&header)
{
    int position;
    cout << "Enter the position to insert the Node (1 to " << node_count + 1 << "): ";
    cin >> position;

    if (position < 1 || position > node_count + 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    struct Node *new_node = new Node();
    cout << "Enter data for the new Node: ";
    cin >> new_node->data;
    new_node->next = NULL;

    if (position == 1)
    {
        new_node->next = header;

        struct Node *temp = header;
        while (temp->next != header)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        header = new_node;
    }
    else
    {
        struct Node *temp = header;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    node_count++;
}

// Delete First Node in CLL
void CircularLinkedList::delete_first_node_CLL(struct Node *&header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty. Nothing to delete." << endl;
        return;
    }

    struct Node *temp = header;
    while (temp->next != header)
    {
        temp = temp->next;
    }

    if (temp == header)
    {
        delete header;
        header = NULL;
    }
    else
    {
        temp->next = header->next;
        delete header;
        header = temp->next;
    }

    node_count--;

    cout << "First Node deleted successfully." << endl;
}

// Delete Last Node in CLL
void CircularLinkedList::delete_last_node_CLL(struct Node *&header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty. Nothing to delete." << endl;
        return;
    }

    struct Node *temp = header;
    struct Node *prev = NULL;

    while (temp->next != header)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == header)
    {
        delete header;
        header = NULL;
    }
    else
    {
        prev->next = header;
        delete temp;
    }

    node_count--;

    cout << "Last Node deleted successfully." << endl;
}

// Delete Desired Node in CLL
void CircularLinkedList::delete_desired_node_CLL(struct Node *&header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty. Nothing to delete." << endl;
        return;
    }

    int position;
    cout << "Enter the position to delete the Node (1 to " << node_count << "): ";
    cin >> position;

    if (position < 1 || position > node_count)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 1)
    {
        struct Node *temp = header;
        while (temp->next != header)
        {
            temp = temp->next;
        }

        if (temp == header)
        {
            delete header;
            header = NULL;
        }
        else
        {
            temp->next = header->next;
            delete header;
            header = temp->next;
        }
    }
    else
    {
        struct Node *temp = header;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }

        struct Node *deleted_node = temp->next;
        temp->next = temp->next->next;
        delete deleted_node;
    }

    node_count--;

    cout << "Node at position " << position << " deleted successfully." << endl;
}

// Search Node in CLL
void CircularLinkedList::search_CLL(struct Node *&header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    int key;
    cout << "Enter the data to search: ";
    cin >> key;

    struct Node *current = header;
    int position = 1;

    do
    {
        if (current->data == key)
        {
            cout << "Data found at position " << position << "." << endl;
            return;
        }
        current = current->next;
        position++;

    } while (current != header);

    cout << "Data not found in the linked list." << endl;
}

// Sort CLL
void CircularLinkedList::sort_CLL(struct Node *&header)
{
    if (header == NULL || header->next == header)
    {
        cout << "The linked list is already sorted or empty." << endl;
        return;
    }

    struct Node *current, *index;
    int temp;

    do
    {
        for (current = header; current->next != header; current = current->next)
        {
            for (index = current->next; index != header; index = index->next)
            {
                if (current->data > index->data)
                {
                    // Swapping data
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }

    } while (current->next != header);

    cout << "Linked list sorted successfully." << endl;
}

// Reverse CLL
void CircularLinkedList::reverse_CLL(struct Node *&header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    struct Node *prev = NULL;
    struct Node *current = header;
    struct Node *next;

    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    } while (current != header);

    header->next = prev;
    header = prev;

    cout << "Linked list reversed successfully." << endl;
}

// Concatenate CLL
void CircularLinkedList::concate_CLL(struct Node *&header, struct Node *&header_1)
{
    if (header == NULL)
    {
        header = header_1;
    }
    else
    {
        struct Node *temp = header;
        while (temp->next != header)
        {
            temp = temp->next;
        }

        temp->next = header_1;

        temp = header_1;
        while (temp->next != header_1)
        {
            temp = temp->next;
        }

        temp->next = header;
    }

    cout << "Linked lists concatenated successfully." << endl;
}

int main()
{
    struct Node *header = NULL;
    struct Node *header_1 = NULL; // for concatenation
    CircularLinkedList linkedList;

    int choice;
    do
    {
        cout << "\n----MENU----";
        cout << "\n1. Create Linked List";
        cout << "\n2. Display Linked List";
        cout << "\n3. Insert at the Front";
        cout << "\n4. Insert at the End";
        cout << "\n5. Insert in the Middle";
        cout << "\n6. Delete First Node";
        cout << "\n7. Delete Last Node";
        cout << "\n8. Delete Desired Node";
        cout << "\n9. Search Node";
        cout << "\n10. Sort Linked List";
        cout << "\n11. Reverse Linked List";
        cout << "\n12. Concatenate Linked Lists";
        cout << "\n13. Exit";
        cout << "\n ---- \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            linkedList.create_CLL(header);
            break;
        case 2:
            linkedList.display_CLL(header);
            break;
        case 3:
            linkedList.insert_node_front_CLL(header);
            break;
        case 4:
            linkedList.insert_node_end_CLL(header);
            break;
        case 5:
            linkedList.insert_in_the_mid_CLL(header);
            break;
        case 6:
            linkedList.delete_first_node_CLL(header);
            break;
        case 7:
            linkedList.delete_last_node_CLL(header);
            break;
        case 8:
            linkedList.delete_desired_node_CLL(header);
            break;
        case 9:
            linkedList.search_CLL(header);
            break;
        case 10:
            linkedList.sort_CLL(header);
            break;
        case 11:
            linkedList.reverse_CLL(header);
            break;
        case 12:
            linkedList.create_CLL(header_1); // create a second list for concatenation
            linkedList.display_CLL(header_1);
            linkedList.concate_CLL(header, header_1);
            break;
        case 13:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 13);

    return 0;
}
