// #include<iostream.h>
// #include<conio.h>
#include <iostream>
using namespace std;

void createList(int arr[], int size)
{
    cout << "Enter " << size << " elements for the list:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void InsertionSort(int arr[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = arr[step];
        int j = step - 1;

        // Compare key with each element on the left of
        // it until an element smaller than it is found.
        // For descending order, change key<array[j]
        // to key>array[j].
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void displayList(int arr[], int size)
{
    cout << "Sorted List: ";
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

    InsertionSort(arr, size);

    cout << "After Bubble Sort: ";
    displayList(arr, size);

    free(arr);

    // getch();

    return 0;
}
