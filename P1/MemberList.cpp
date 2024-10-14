
#include "MemberList.h"
#include <sstream>

MemberList::MemberList(int cap)
{
    list = new Member[cap];
    capacity = cap;
    numElements = 0;
}

MemberList::~MemberList()
{
    delete[] list;
}

MemberList::MemberList(const MemberList &obj)
{
    // assign numElements and capacity (from obj)
    capacity = obj.capacity;
    numElements = obj.numElements;

    // allocate memory based on new capacity
    list = new Member[capacity];

    // copy over elements (from obj)
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}
 // method to add a new member to list
void MemberList::add(string memberName, int memberAccount,bool displayFlag)
{
    Member member = {memberName, memberAccount};

    if (numElements >= capacity)
        resize();
    list[numElements] = member;
    numElements++;
    if(displayFlag)
        cout << memberName << " (account #: " << memberAccount+1 << ") was added."
             << endl;

}
// to check if list is empty
bool MemberList::empty() const
{
    return numElements == 0;
}

int MemberList::size() const
{
    return numElements;
}

void MemberList::resize()
{
    // update capacity
    capacity *= 2;

    // create new array based on updated capacity
    Member *tempArr = new Member[capacity];

    // copy old array values to new array
    for (int i = 0; i < numElements; i++)
        tempArr[i] = list[i];

    // delete old array
    delete[] list;

    // reassign old array to new array
    list = tempArr;
}

string MemberList::to_string() const
{
    stringstream ss;
    for (int i = 0; i <numElements; i++)
        ss << list[i].memberName << " (account #: " << list[i].memberAccount
           << " was added.)"<<"\n";
    return ss.str();
}

string MemberList::getMemberName(int memberAccount) const
{
    return this->list[(memberAccount-1)].memberName ;
}

int MemberList::getAccountNumber(int i) const {
    return this->list[i].memberAccount;
}