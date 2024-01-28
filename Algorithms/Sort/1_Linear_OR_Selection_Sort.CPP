// #include<iostream.h>
// #include<conio.h>
// #include<stdlib.h>
#include <iostream>
using namespace std;

class SelectionSort
{
private:
    int *arr;
    int size;

public:
    SelectionSort(int s)
    {
        size = s;
        arr = (int *)malloc(size * sizeof(int));
    }

    ~SelectionSort()
    {
        free(arr);
    }

    void createList()
    {
        cout << "Enter " << size << " elements for the list:" << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    void sort()
    {
        for (int i = 0; i < size - 1; ++i)
        {
            int minIndex = i;

            for (int j = i + 1; j < size; ++j)
            {
                // To sort in descending order, 
                // change > to < in this line.
                // Select the minimum element in each loop.
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

    void displayList()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // clrscr();

    int size;
    cout << "Enter the size of the list: ";
    cin >> size;

    SelectionSort selectionSort(size);
    selectionSort.createList();

    cout << "Original List: ";
    selectionSort.displayList();

    selectionSort.sort();

    cout << "List after Selection Sort: ";
    selectionSort.displayList();

    // getch();

    return 0;
}