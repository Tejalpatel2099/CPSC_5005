#include<iostream>
using namespace std;

int binarysearch(int [] ,int  , int );
int binarysearchR(int [],int ,int ,int );
void printResult(int , int );

int main()
{
    const int SIZE = 8;
    int arr[] = {-2, 0, 1, 3, 4, 7, 11, 15};
    int key , index;

    cout << "Enter a search key: ";
    cin >> key;

    cout << "Binary search (recursive): ";
    index = binarysearch(arr, SIZE, key);
    printResult(key, index);
    return 0;
}

int binarysearch(int arr[], int size, int key)
{
    return binarysearchR(arr, 0, size - 1, key);
}

int binarysearchR(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            return binarysearchR(arr, mid + 1, right, key);
        }
        else {
            return binarysearchR(arr, left, mid - 1, key);
        }
    }
    return -1;
}

void printResult(int key, int index) {
    if (index == -1)
        cout << key << " was not found\n";
    else
        cout << key << " was found at index " << index << endl;
}





