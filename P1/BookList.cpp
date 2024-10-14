
#include "BookList.h"
#include <sstream>

// constructor initialize a book list object with capacity
BookList::BookList(int cap)
{
    list = new Book[cap];
    capacity = cap;
    numElements = 0;
}

BookList::~BookList()
{
    delete[] list; // delete dynamically allocated array
}
// copy constructor which create  copy of book list object
BookList::BookList(const BookList &obj)
{
    // assign numElements and capacity from object
    capacity = obj.capacity;
    numElements = obj.numElements;

    // allocate memory based on new capacity
    list = new Book[capacity];

    // copy over elements from object
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}

// Method to add a new book to list
void BookList::add(int isbnNumber, string authorName, string titleOfBook,
                   string year)
{
    Book book = {isbnNumber, authorName, titleOfBook, year};

    if (numElements >= capacity)
        resize();
    list[numElements] = book;
    numElements++;
}

// method to check if list is empty
bool BookList::empty() const
{
    return numElements == 0;
}
 // method to get number of elements in list
int BookList::size() const
{
    return numElements;
}

void BookList::resize()
{

    capacity *= 2;   // double the capacity (update)

    // create new array based on updated capacity
    Book *tempArr = new Book[capacity];

    // copy old array values to new array
    for (int i = 0; i < numElements; i++)
        tempArr[i] = list[i];

    // delete old array
    delete[] list;

    // reassign old array to new array
    list = tempArr;
}

// method to convert book list to string representation
string BookList::to_string() const
{
    stringstream ss;
    for (int i = 0; i < numElements; i++)
        ss << list[i].isbnNumber << ", " << list[i].authorName << ", "
           << list[i].titleOfBook << ", " << list[i].year << "\n";
    return ss.str();
}

string BookList::get(int i) const
{
    stringstream ss;
    ss << list[i].isbnNumber << ", " << list[i].authorName << ", "
       << list[i].titleOfBook << ", " << list[i].year;
    return ss.str();
}


int BookList::getIsbnNumber(int i) const
{
    return list[i].isbnNumber;
}