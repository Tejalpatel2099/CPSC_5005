// Name :- Tejal Patel
// Date:- 03/29/2024
//file:- ICE2 p1 interface

#include <iostream>
#include <string>
using namespace std;

//Class represents a book, it stores information such as ISBN, author name,
// title of book and book publication year, and also provides functionality
// to add new books to the system and see recommended books given by members.

class Book {
private:
    int isbnNumber;  // ISBN of book
    string authorName;  // Name of author
    string titleOfBook;  // Title of book
    string year; // year of publication

public:
    Book(){}; // default constructor

    //Parameterized constructor
    Book(int isbnNumber, string authorName, string titleOfBook, string year) {

    }

    //Function to add a new book to the library
    void addNewBook(Book b) {

    }

    // Function to see recommended books for a given member
    void seeRecommendedBook(Member M) {

    }
};