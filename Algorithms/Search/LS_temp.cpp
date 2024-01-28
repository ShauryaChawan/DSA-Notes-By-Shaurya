#include <iostream.h>
#include <conio.h>

#define MAX 5

// Name: Shaurya
// Roll. no : 12

class search
{
public:
  int a[MAX];
  void insert()
  {
    cout << "\nYou can enter Max 5 elements.\n";
    for (int i = 0; i < MAX; i++)
    {
      cout << "Enter " << i + 1 << " element: ";
      cin >> a[i];
    }
    cout << "\nData Entered : ";
    for (int j = 0; j < MAX; j++)
    {
      cout << "\t" << a[j];
    }
  }

  void linearsearch(int key)
  {
    int flag = 0;
    for (int i = 0; i < MAX; i++)
    {
      if (key == a[i])
      {
        cout << "\nThe key " << key << " found at position " << i + 1 << ".";
        flag = 1;
      }
    }
    if (flag == 0)
    {
      cout << "\nThe key " << key << " was not found!!";
    }
  }
};

void main()
{
  int val;
  clrscr();
  cout << "\n<< ------ Shaurya - 012 : Linear Search ---->>";
  search shaurya012LinearSearch;
  shaurya012LinearSearch.insert();
  cout << "\nEnter the value to be searched: ";
  cin >> val;
  shaurya012LinearSearch.linearsearch(val);
  getch();
}
