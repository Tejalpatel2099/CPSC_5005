
#ifndef P1_RATINGLIST_H
#define P1_RATINGLIST_H



#include <string>
#include <iostream>
using namespace std;

class RatingList {

public:
    RatingList(int rows,int columns);      //constructor
    ~RatingList();              // Destructor



       // method to add or update a rating in list
    void addOrUpdate(int isbnNumber, int accountNumber, int ratingValue);

    string to_string(int rows,int columns) const;

    int  getRating(int accountNumber,int isbnNumber) const;


    bool empty() const;                  //to check if list is empty or not

    int size() const;                    // number of elements in array



private:
    struct Rating {
        int isbnNumber;
        int accountNumber;
        int ratingValue;

    };
    Rating *list;                     // Pointer to the array
    int **ratingsArray;             // 2D array to store ratings
    int col;                         // columns of 2d array
    int row;                         // rows of 2d array
    int capacity;
    int numElements;                      // Number of elements

    void resize();                        // resize array (when full)


};


#endif //P1_RATINGLIST_H