#include <iostream>
using namespace std;

int sumR(int);
int sumR(int, int);
int findMinR(int [], int);
int findSumR(int [], int);

int main()
{
    const int SIZE = 4;
    int arr[] = {2, 4, 1, 5};

    cout << "array contents: ";
    for (int i : arr)
        cout << i << " ";
    cout << "\narray size: " << SIZE << endl;

    cout << "\nrecursive tests:\n";
    cout << "sum(5) = " << sumR(5) << endl;
    cout << "sum(5, 7) = " << sumR(5, 7) << endl;
    cout << "findMin(a, 4) = " << findMinR(arr, SIZE) << endl;
    cout << "findSum(a, 4) = " << findSumR(arr, SIZE) << endl;

}


int sumR(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumR(n - 1);
}


int sumR(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    return sumR(a + 1, b) + a;

}

int findMinR(int a[], int n)
{
    if (n == 1) {
        return a[0];
    }
    int minRest = findMinR(a, n -1);
    if(a [n-1] < minRest)
    {
        return a [n-1];
    }
    return minRest;
}


    int findSumR(int a[], int n)
    {
        if (n == 1)
        {
            return a[0];
        }
        return a[n - 1] + findSumR(a, n - 1);
}

