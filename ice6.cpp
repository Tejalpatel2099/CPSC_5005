
#include "DynamicList.h"
#include <iostream>
using namespace std;

template<typename T>
void prDynamicListState(const DynamicList<T> &);
void printIndex(int, int);

int main() {
    const int SIZE = 5;
    DynamicList<int> numbers(SIZE);

    // print List state
    prDynamicListState(numbers);

    // populate array
    for (int x = 1; x <= SIZE; x++)
        numbers.add(x);

    // print List state again
    prDynamicListState(numbers);

    // find value 5 and 20
    int val = 5;
    int index = numbers.get(val);
    printIndex(val, index);
    index = numbers.get(SIZE);
    printIndex(SIZE, index);

    DynamicList<int> numbers2(numbers); // calls the copy constructor
    DynamicList<int> numbers3(SIZE);    // calls constructor
    numbers3 = numbers;        // calls the overloaded = operator

    // the destructor is automatically called when the IntList object
    // goes out of range; you cannot and should not call the destructor!

    return 0;
}
template<typename T>
void prDynamicListState(const DynamicList<T> &obj) {
    if (obj.empty())
        cout << "List is empty";
    else
        cout << "List is not empty";
    cout << " and has a size of " << obj.size() << endl;
}

void printIndex(int val, int index) {
    if (index == -1)
        cout << val << " not found!" << endl;
    else
        cout << val << " found at index " << index << endl;
}
