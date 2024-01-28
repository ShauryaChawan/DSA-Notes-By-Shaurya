#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <STDIO.H>

struct link
{
  int info;
  struct link *next;
};

struct link *node, *previous, *new1;
int node_counts = 0;

class snglyst
{
public:
  void create_linked_list(struct link *header)
  {
    char ch = ' ';
    header->next = NULL;
    node = header;
    while (ch != 'n')
    {
      node->next = (struct link *)malloc(sizeof(struct link));
      node_counts = node_counts + 1;
      node = node->next;
      cout << "\nEnter data: ";
      cin >> node->info;
      node->next = NULL;
      fflush(stdin);
      cout << "\nContinue Y/N: ";
      cin >> ch;
    }
  }
  void display_linked_list(struct link *header)
  {
    node = header->next;
    for (int i = 0; i < node_counts; i++)
    {
      cout << node->info << "\t";
      node = node->next;
    }
  }
  void insert_at_beg(struct link *header)
  {
    node = header->next;
    previous = header;
    new1 = (struct link *)malloc(sizeof(struct link));
    node_counts = node_counts + 1;
    previous->next = new1;
    new1->next = node;
    cout << "\nEnter no: ";
    cin >> new1->info;
  }
  void insert_at_end(struct link *header)
  {
    struct link *new1;
    node = header->next;
    previous = header;
    while (node != NULL)
    {
      node = node->next;
      previous = previous->next;
    }
    if (node == NULL)
    {
      new1 = (struct link *)malloc(sizeof(struct link));
      node_counts = node_counts + 1;
      new1->next = node;
      previous->next = new1;
      cout << "\nEnter no: ";
      cin >> new1->info;
    }
  }
  void insert_in_the_middle(struct link *header)
  {
    int node_num = 1;
    int insert_node;
    node = header->next;
    previous = header;
    cout << "\nEnter the index of the node to be inserted: ";
    cin >> insert_node;
    if (insert_node <= node_counts)
    {
      while (node != NULL)
      {
        if (node_num == insert_node)
        {
          new1 = (struct link *)malloc(sizeof(struct link));
          node_counts = node_counts + 1;
          new1->next = node;
          previous->next = new1;
          cout << "Enter the value: ";
          cin >> new1->info;
        }
        else
        {
          node = node->next;
          previous = previous->next;
        }
        node_num = node_num + 1;
      }
    }
    else
    {
      cout << "there are only " << node_counts << " nodes in the list";
    }
  }
  void delete_first_node(struct link *header)
  {
    node = header->next;
    previous = header;
    if (node == NULL)
    {
      cout << "No nodes";
      return;
    }
    else
    {
      previous->next = node->next;
      free(node);
    }
  }
  void delete_last_node(struct link *header)
  {
    int node_num = node_counts;
    node = header->next;
    previous = header;
    if (node == NULL)
    {
      cout << "No nodes";
      return;
    }
    else
    {
      while (node && node_num != 1)
      {
        node = node->next;
        previous = previous->next;
        node_num--;
      }
    }
    if (node_num == 1)
    {
      previous->next = node->next;
      free(node);
    }
  }
  void delete_desired_node(struct link *header)
  {
    int node_num = 1;
    int delete_node = 0;
    node = header->next;
    previous = header;
    cout << "\nEnter the index of the node to be deleted: ";
    cin >> delete_node;
    while (node)
    {
      if (node_num == delete_node)
      {
        previous->next = node->next;
        free(node);
        node_counts = node_counts - 1;
      }
      else
      {
        node = node->next;
        previous = previous->next;
      }
      node_num = node_num + 1;
    }
  }
};

void main()
{
  struct link header;
  snglyst sllObj;
  int choice;
  // clrscr();
  do
  {
    cout << "\n 1. create linked list";
    cout << "\n 2. insert at beginning of the list";
    cout << "\n 3. insert at the end of the list";
    cout << "\n 4. insert at the middle of the list";
    cout << "\n 5. delete the first node";
    cout << "\n 6. delete the last node";
    cout << "\n 7. delete the desired node";
    cout << "\n 8. display linked list";
    cout << "\n 9 exit";
    cout << "\n-------";
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      sllObj.create_linked_list(&header);
      break;
    case 2:
      sllObj.insert_at_beg(&header);
      break;
    case 3:
      sllObj.insert_at_end(&header);
      break;
    case 4:
      sllObj.insert_in_the_middle(&header);
      break;
    case 5:
      sllObj.delete_first_node(&header);
      break;
    case 6:
      sllObj.delete_last_node(&header);
      break;
    case 7:
      sllObj.delete_desired_node(&header);
      break;
    case 8:
      sllObj.display_linked_list(&header);
      break;
    case 9:
      cout << "\n END OF PROGRAM";
    }
  } while (choice != 9);
  getch();
}
