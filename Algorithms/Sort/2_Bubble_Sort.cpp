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

void BubbleSort(int arr[], int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; ++i)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

void displayList(int arr[], int size)
{
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

    BubbleSort(arr, size);

    cout << "After Bubble Sort: ";
    displayList(arr, size);

    free(arr);

    return 0;
}
