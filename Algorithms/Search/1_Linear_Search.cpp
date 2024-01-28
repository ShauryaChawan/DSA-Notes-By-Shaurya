// #include<iostream.h>
// #include<conio.h>
#include <iostream>
using namespace std;

class BinarySearch
{
private:
    int *arr;
    int size;

public:
    BinarySearch(int s)
    {
        size = s;
        arr = new int[size];
    }

    ~BinarySearch()
    {
        delete[] arr;
    }

    void createList()
    {
        cout << "Enter " << size << " sorted elements for the list:" << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    int search(int key)
    {
        int left = 0;
        int right = size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == key)
            {
                return mid; // Element found, return its index
            }

            if (arr[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1; // Element not found
    }

    void displayList()
    {
        cout << "List: ";
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
    int size, key;
    cout << "Enter the size of the sorted list: ";
    cin >> size;

    BinarySearch binarySearch(size);
    binarySearch.createList();
    binarySearch.displayList();

    cout << "Enter the element to search: ";
    cin >> key;
    int result = binarySearch.search(key);

    if (result != -1)
    {
        cout << "Element " << key << " found at index " << result << "." << endl;
    }
    else
    {
        cout << "Element " << key << " not found in the list." << endl;
    }

    return 0;
}
