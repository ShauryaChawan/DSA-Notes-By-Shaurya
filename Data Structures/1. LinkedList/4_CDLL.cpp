// #include<iostream.h>
// #include<conio.h>
// #include<stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

int node_count = 0;

class CircularDoublyLinkedList
{
public:
    void create_CDLL(struct Node *&header);
    void display_CDLL(struct Node *header);
    void insert_node_front_CDLL(struct Node *&header);
    void insert_node_end_CDLL(struct Node *&header);
    void insert_in_the_mid_CDLL(struct Node *&header);
    void delete_first_node_CDLL(struct Node *&header);
    void delete_last_node_CDLL(struct Node *&header);
    void delete_desired_node_CDLL(struct Node *&header);
    void search_CDLL(struct Node *&header);
    void sort_CDLL(struct Node *&header);
    void reverse_CDLL(struct Node *&header);
    void concate_CDLL(struct Node *&header, struct Node *&header_1);
};

// Create Circular Doubly Linked List
void CircularDoublyLinkedList::create_CDLL(struct Node *&header)
{
    char choice;
    do
    {
        struct Node *new_node = new Node();
        cout << "Enter data for the new Node: ";
        cin >> new_node->data;
        new_node->next = header;
        new_node->prev = NULL;

        if (header == NULL)
        {
            header = new_node;
            header->next = header;
            header->prev = header;
        }
        else
        {
            struct Node *temp = header->prev;
            temp->next = new_node;
            new_node->prev = temp;

            header->prev = new_node;
        }

        node_count++;

        cout << "Do you want to add another Node? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

// Display Circular Doubly Linked List
void CircularDoublyLinkedList::display_CDLL(struct Node *header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    cout << "Circular Doubly Linked List: ";
    struct Node *current = header;
    do
    {
        cout << current->data << " <-> ";
        current = current->next;
    } while (current != header);
    cout << "HEAD" << endl;
}

// Insert Node in front in CDLL
void CircularDoublyLinkedList::insert_node_front_CDLL(struct Node *&header)
{
    struct Node *new_node = new Node();
    cout << "Enter data for the new Node: ";
    cin >> new_node->data;
    new_node->next = header;
    new_node->prev = header->prev;

    header->prev->next = new_node;
    header->prev = new_node;
    header = new_node;

    node_count++;
}

// Insert Node at end in CDLL
void CircularDoublyLinkedList::insert_node_end_CDLL(struct Node *&header)
{
    struct Node *new_node = new Node();
    cout << "Enter data for the new Node: ";
    cin >> new_node->data;
    new_node->next = header;
    new_node->prev = header->prev;

    header->prev->next = new_node;
    header->prev = new_node;

    node_count++;
}

// Insert Node in the Middle in CDLL
void CircularDoublyLinkedList::insert_in_the_mid_CDLL(struct Node *&header)
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

    if (position == 1)
    {
        new_node->next = header;
        new_node->prev = header->prev;

        header->prev->next = new_node;
        header->prev = new_node;

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
        new_node->prev = temp;

        temp->next->prev = new_node;
        temp->next = new_node;
    }

    node_count++;
}

// Delete First Node in CDLL
void CircularDoublyLinkedList::delete_first_node_CDLL(struct Node *&header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty. Nothing to delete." << endl;
        return;
    }

    if (header->next == header)
    {
        delete header;
        header = NULL;
    }
    else
    {
        struct Node *temp = header;
        header->prev->next = header->next;
        header->next->prev = header->prev;
        header = header->next;
        delete temp;
    }

    node_count--;

    cout << "First Node deleted successfully." << endl;
}

// Delete Last Node in CDLL
void CircularDoublyLinkedList::delete_last_node_CDLL(struct Node *&header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty. Nothing to delete." << endl;
        return;
    }

    if (header->next == header)
    {
        delete header;
        header = NULL;
    }
    else
    {
        struct Node *temp = header->prev;
        temp->prev->next = header;
        header->prev = temp->prev;
        delete temp;
    }

    node_count--;

    cout << "Last Node deleted successfully." << endl;
}

// Delete Desired Node in CDLL
void CircularDoublyLinkedList::delete_desired_node_CDLL(struct Node *&header)
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
        header->prev->next = header->next;
        header->next->prev = header->prev;
        header = header->next;
        delete temp;
    }
    else
    {
        struct Node *temp = header;
        for (int i = 1; i < position; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    node_count--;

    cout << "Node at position " << position << " deleted successfully." << endl;
}

// Search Node in CDLL
void CircularDoublyLinkedList::search_CDLL(struct Node *&header)
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

// Sort CDLL
void CircularDoublyLinkedList::sort_CDLL(struct Node *&header)
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

// Reverse CDLL
void CircularDoublyLinkedList::reverse_CDLL(struct Node *&header)
{
    if (header == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }

    struct Node *current = header;
    struct Node *temp;
    do
    {
        // Swapping next and prev pointers for each node
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    } while (current != header);

    // Swapping header's next and prev pointers
    temp = header->next;
    header->next = header->prev;
    header->prev = temp;

    cout << "Linked list reversed successfully." << endl;
}

// Concatenate CDLL
void CircularDoublyLinkedList::concate_CDLL(struct Node *&header, struct Node *&header_1)
{
    if (header == NULL)
    {
        header = header_1;
    }
    else if (header_1 != NULL)
    {
        struct Node *temp = header->prev;

        header->prev->next = header_1;
        header->prev = header_1->prev;

        header_1->prev->next = header;
        header_1->prev = temp;
    }

    cout << "Linked lists concatenated successfully." << endl;
}

int main()
{
    struct Node *header = NULL;
    struct Node *header_1 = NULL; // for concatenation
    CircularDoublyLinkedList linkedList;

    // clrscr();

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
            linkedList.create_CDLL(header);
            break;
        case 2:
            linkedList.display_CDLL(header);
            break;
        case 3:
            linkedList.insert_node_front_CDLL(header);
            break;
        case 4:
            linkedList.insert_node_end_CDLL(header);
            break;
        case 5:
            linkedList.insert_in_the_mid_CDLL(header);
            break;
        case 6:
            linkedList.delete_first_node_CDLL(header);
            break;
        case 7:
            linkedList.delete_last_node_CDLL(header);
            break;
        case 8:
            linkedList.delete_desired_node_CDLL(header);
            break;
        case 9:
            linkedList.search_CDLL(header);
            break;
        case 10:
            linkedList.sort_CDLL(header);
            break;
        case 11:
            linkedList.reverse_CDLL(header);
            break;
        case 12:
            linkedList.create_CDLL(header_1); // create a second list for concatenation
            linkedList.display_CDLL(header_1);
            linkedList.concate_CDLL(header, header_1);
            break;
        case 13:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 13);

    // getch();
    return 0;
}