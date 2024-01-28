// #include<iostream.h>
// #include<conio.h>
// #include<stdlib.h>
#include <iostream>
using namespace std;

void createList(int arr[], int size)
{
  cout << "Enter " << size << " elements for the array:" << endl;
  for (int i = 0; i < size; ++i)
  {
    cout << "Element " << i + 1 << ": ";
    cin >> arr[i];
  }
}

void SelectionSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    int minIndex = i;

    for (int j = i + 1; j < size; ++j)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }

    if (minIndex != i)
    {
      // Swap arr[i] and arr[minIndex]
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

void displayList(int arr[], int size)
{
  cout << "Sorted Array: ";
  for (int i = 0; i < size; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  // clrscr();
  int size;
  cout << "Enter the size of the Array: ";
  cin >> size;

  int *arr = (int *)malloc(size * sizeof(int));

  cout << "You can only enter 5 elements !!" << endl;
  createList(arr, size);

  cout << "Original Array: ";
  displayList(arr, size);

  SelectionSort(arr, size);

  cout << "After Bubble Sort: ";
  displayList(arr, size);

  free(arr);

  return 0;
}
