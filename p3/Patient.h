//Author: Tejal Patel
//Date:- 11/12/2023
//File:- Patient.h
//Purpose:- Creating patient class with specification and implementation file.
#ifndef P3_UPDATED_PATIENT_H
#define P3_UPDATED_PATIENT_H
#include <iostream>
#include <sstream>
using namespace std;

class Patient
{
public:
    Patient(string, string, int);
    Patient & operator = (const Patient &t);
    // is used to assign patient to specific index or priority in priority queue
    // precondition:- None
    // postcondition:- assign patient to correct index

    bool operator < (const Patient &t);
    // to compare prioroty code of patient and arrival order
    // precondition :- none
    // postcondition:- returns true if current patient priority is less than
    // operands priority

    bool operator == (const Patient &t);
    // to compare priority code of patient and also arrival order

    string to_string();

    Patient & updatePriority (const Patient &t);
    // it is use for updating the priority

private:
    string name;            // holds name
    string priorityCode;    // holds priorityCode
    int arrivalOrder=0;      // holds arrivalOrder
};

Patient::Patient(string patientName, string patientPriorityCode, int
patientArrivalOrder)
{
    name = patientName;
    priorityCode = patientPriorityCode;
    arrivalOrder = patientArrivalOrder;
}
Patient & Patient::operator = (const Patient &t)
{
    if(this != &t)
    {
        this->name = t.name;
        this->arrivalOrder=t.arrivalOrder;
        this->priorityCode=t.priorityCode;
    }
    return *this;
}
int getPriority(string priority)
{
    if (priority == "immediate") return 1;
    if (priority== "emergency") return 2;
    if (priority == "urgent") return 3;
    if (priority == "minimal") return 4;

    return -1;
}
bool Patient::operator < (const Patient &t)
{
    int p1=getPriority(this->priorityCode);
    int p2= getPriority(t.priorityCode);

    if(p1==p2)
    {
        return (this->arrivalOrder>t.arrivalOrder);
    }
    else if(p1>p2)
        return true;
    else
        return false;
}
bool Patient::operator == (const Patient &t)
{
    return (this->arrivalOrder>t.arrivalOrder);
}
string Patient::to_string()
{
    stringstream ss;
    ss << "\t" <<arrivalOrder <<"\t\t" << priorityCode <<"\t\t" << name;
    return ss.str();
}
Patient &Patient::updatePriority(const Patient &t)
{
    if(this != &t)
    {
        this->name = t.name;
        this->arrivalOrder=t.arrivalOrder;
    }
    return *this;
}
#endif //P3_UPDATED_PATIENT_H