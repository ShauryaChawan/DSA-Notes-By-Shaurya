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

class DoublyLinkedList
{
public:
	void create_DLL(struct Node *&header);
	void display_DLL(struct Node *header);
	void insert_node_front_DLL(struct Node *&header);
	void insert_node_end_DLL(struct Node *&header);
	void insert_in_the_mid_DLL(struct Node *&header);
	void delete_first_node_DLL(struct Node *&header);
	void delete_last_node_DLL(struct Node *&header);
	void delete_desired_node_DLL(struct Node *&header);
	void search_DLL(struct Node *&header);
	void sort_DLL(struct Node *&header);
	void reverse_DLL(struct Node *&header);
	void concate_DLL(struct Node *&header, struct Node *&header_1);
};

// Create Doubly Linked List
void DoublyLinkedList::create_DLL(struct Node *&header)
{
	char choice;
	do
	{
		struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
		// struct Node *new_node = new Node();
		cout << "Enter data for the new Node: ";
		cin >> new_node->data;
		new_node->prev = NULL;
		new_node->next = NULL;

		if (header == NULL)
		{
			header = new_node;
		}
		else
		{
			struct Node *temp = header;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
		}

		node_count++;

		cout << "Do you want to add another Node? (y/n): ";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');
}

// Display Doubly Linked List
void DoublyLinkedList::display_DLL(struct Node *header)
{
	if (header == NULL)
	{
		cout << "The linked list is empty." << endl;
		return;
	}

	cout << "Doubly Linked List: ";
	struct Node *current = header;
	while (current != NULL)
	{
		cout << current->data << " <-> ";
		current = current->next;
	}
	cout << "NULL" << endl;
}

// Insert Node in front in DLL
void DoublyLinkedList::insert_node_front_DLL(struct Node *&header)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	// struct Node *new_node = new Node();
	cout << "Enter data for the new Node: ";
	cin >> new_node->data;
	new_node->prev = NULL;
	new_node->next = header;

	if (header != NULL)
	{
		header->prev = new_node;
	}

	header = new_node;
	node_count++;
}

// Insert Node at end in DLL
void DoublyLinkedList::insert_node_end_DLL(struct Node *&header)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	// struct Node *new_node = new Node();
	cout << "Enter data for the new Node: ";
	cin >> new_node->data;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (header == NULL)
	{
		header = new_node;
	}
	else
	{
		struct Node *temp = header;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}

	node_count++;
}

// Insert Node in the Middle in DLL
void DoublyLinkedList::insert_in_the_mid_DLL(struct Node *&header)
{
	int position;
	cout << "Enter the position to insert the Node (1 to " << node_count + 1 << "): ";
	cin >> position;

	if (position < 1 || position > node_count + 1)
	{
		cout << "Invalid position." << endl;
		return;
	}

	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	// struct Node *new_node = new Node();
	cout << "Enter data for the new Node: ";
	cin >> new_node->data;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (position == 1)
	{
		new_node->next = header;
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
		if (temp->next != NULL)
		{
			temp->next->prev = new_node;
		}
		temp->next = new_node;
	}

	node_count++;
}

// Delete First Node in DLL
void DoublyLinkedList::delete_first_node_DLL(struct Node *&header)
{
	if (header == NULL)
	{
		cout << "The linked list is empty. Nothing to delete." << endl;
		return;
	}

	struct Node *temp = header;
	header = header->next;
	if (header != NULL)
	{
		header->prev = NULL;
	}

	free(temp);
	// delete temp;
	node_count--;

	cout << "First Node deleted successfully." << endl;
}

// Delete Last Node in DLL
void DoublyLinkedList::delete_last_node_DLL(struct Node *&header)
{
	if (header == NULL)
	{
		cout << "The linked list is empty. Nothing to delete." << endl;
		return;
	}

	if (header->next == NULL)
	{
		free(header);
		// delete header;
		header = NULL;
	}
	else
	{
		struct Node *temp = header;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}

		free(temp->next);
		// delete temp->next;
		temp->next = NULL;
	}

	node_count--;

	cout << "Last Node deleted successfully." << endl;
}

// Delete Desired Node in DLL
void DoublyLinkedList::delete_desired_node_DLL(struct Node *&header)
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
		header = header->next;
		if (header != NULL)
		{
			header->prev = NULL;
		}
		free(temp);
		// delete temp;
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
		if (temp->next != NULL)
		{
			temp->next->prev = temp;
		}
		free(deleted_node);
		delete deleted_node;
	}

	node_count--;

	cout << "Node at position " << position << " deleted successfully." << endl;
}

// Search Node in DLL
void DoublyLinkedList::search_DLL(struct Node *&header)
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
	while (current != NULL)
	{
		if (current->data == key)
		{
			cout << "Data found at position " << position << "." << endl;
			return;
		}
		current = current->next;
		position++;
	}

	cout << "Data not found in the linked list." << endl;
}

// Sort DLL
void DoublyLinkedList::sort_DLL(struct Node *&header)
{
	if (header == NULL || header->next == NULL)
	{
		cout << "The linked list is already sorted or empty." << endl;
		return;
	}

	struct Node *current, *index;
	int temp;

	for (current = header; current != NULL; current = current->next)
	{
		for (index = current->next; index != NULL; index = index->next)
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

	cout << "Linked list sorted successfully." << endl;
}

// Reverse DLL
void DoublyLinkedList::reverse_DLL(struct Node *&header)
{
	struct Node *temp = NULL;
	struct Node *current = header;

	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
	{
		header = temp->prev;
	}

	cout << "Linked list reversed successfully." << endl;
}

// Concatenate DLL
void DoublyLinkedList::concate_DLL(struct Node *&header, struct Node *&header_1)
{
	if (header == NULL)
	{
		header = header_1;
	}
	else
	{
		struct Node *temp = header;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = header_1;
		header_1->prev = temp;
	}

	cout << "Linked lists concatenated successfully." << endl;
}

// void main()
int main()
{
	struct Node *header = NULL;
	struct Node *header_1 = NULL; // for concatenation
	DoublyLinkedList linkedList;
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
			linkedList.create_DLL(header);
			break;
		case 2:
			linkedList.display_DLL(header);
			break;
		case 3:
			linkedList.insert_node_front_DLL(header);
			break;
		case 4:
			linkedList.insert_node_end_DLL(header);
			break;
		case 5:
			linkedList.insert_in_the_mid_DLL(header);
			break;
		case 6:
			linkedList.delete_first_node_DLL(header);
			break;
		case 7:
			linkedList.delete_last_node_DLL(header);
			break;
		case 8:
			linkedList.delete_desired_node_DLL(header);
			break;
		case 9:
			linkedList.search_DLL(header);
			break;
		case 10:
			linkedList.sort_DLL(header);
			break;
		case 11:
			linkedList.reverse_DLL(header);
			break;
		case 12:
			linkedList.create_DLL(header_1); // create a second list for concatenation
			linkedList.display_DLL(header_1);
			linkedList.concate_DLL(header, header_1);
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