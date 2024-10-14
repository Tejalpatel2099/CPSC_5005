
#ifndef LAB2_UPDATED_BOOKLIST_H
#define LAB2_UPDATED_BOOKLIST_H


#include <iostream>
#include <string>
using namespace std;


// declaration of book list class
class BookList {

public:
 // definition of book struct to hold book information
    struct Book {
        int isbnNumber;
        string authorName;
        string titleOfBook;
        string year;
    };
    BookList(int);                           // Constructor
    ~BookList();                          // Destructor
    BookList(const BookList &);              // Copy constructor


    void add(int isbnNumbers, string authorName, string titleOfBook,
             string year);        // method to add element to array

    string get(int) const;                     // find element in array;
    int getIsbnNumber(int) const;                 // find element in array;
                                                   // return index
                                                      // where found or -1 if
                                                     // not found
    bool empty() const;                  // determines if list is empty or not

    int size() const;                    // number of elements in array

    string to_string() const;            // returns string representation of

private:

    Book *list;                          // Pointer to the array
    int capacity;                         // capacity of array
    int numElements;                      // Number of elements
    void resize();                        // resize array (when full)

};

#endif //LAB2_UPDATED_BOOKLIST_H