#ifndef P1_MEMBERLIST_H
#define P1_MEMBERLIST_H


#include <iostream>
#include <string>
using namespace std;


class MemberList {
public:
    MemberList(int);  // constructor
    ~MemberList();    // destructor

    MemberList(const MemberList &);  // copy constructor

    //method to add new member to list
    void add(string name, int account,bool displayFlag);


    bool empty() const;                  // to check if list is empty or not

    int size() const;                    // number of elements in array

    string to_string() const;

    // method to get name of a member by account number
    string getMemberName(int memberAccount) const ;

    // method to get account number by index
    int getAccountNumber(int i) const ;

private:
    struct Member {
        string memberName;
        int memberAccount;

    };
    Member*list;                          // Pointer to the array
    int capacity;                         // capacity of array
    int numElements;                      // Number of elements
    void resize();

};


#endif //P1_MEMBERLIST_H