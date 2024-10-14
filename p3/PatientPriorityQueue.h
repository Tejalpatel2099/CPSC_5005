//Author:- Tejal Patel
//date:-11/12/2023
//file:- PatientPriorityQueue.h
// Implementation, specification for patientpriorotyqueue class
//also includes different functions such as peek, remove, size and heapify

#ifndef P3_UPDATED_PATIENTPRIORITYQUEUE_H
#define P3_UPDATED_PATIENTPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include "Patient.h"
#include <sstream>

using namespace std;

class PatientPriorityQueue {
public :

    PatientPriorityQueue(int n);                        // constructor
    ~PatientPriorityQueue();                          // destructor

    void add(Patient);
    // Adds the patient to the priority queue

    Patient peek() const;
    // Returns the highest priority patient without removing it.

    void remove();
    // Removes the highest priority patient from the queue and returns it

    int size();
    // Returns the number of patients still waiting.

    string to_string();
    // Returns the string representation of the object in heap (or level) order.

private:
    vector<Patient> patients;                              // Vector

    int heapSize;                                          // To hold heapSize
    int capacity;                                          // To hold capacity

    void heapify( int i);
    // Function to heapify the tree
    // precondition: Priority queue should be not empty
    // postcondition: Balances queue in heap order


};
PatientPriorityQueue::PatientPriorityQueue(int n) {
    capacity = n;
}

PatientPriorityQueue::~PatientPriorityQueue() {
    patients.clear();
}

void PatientPriorityQueue::add(Patient newPatient) {
    patients.push_back(newPatient);
    heapSize=patients.size();
    if(heapSize>1){
        for (int i = (heapSize-1) / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

}

Patient PatientPriorityQueue::peek() const {
    return patients[0];
}


void PatientPriorityQueue::remove() {

    int size = patients.size();

    Patient temp("","",-1);

    if(size>1) {
        temp = patients[size - 1];
        patients[size - 1] = patients[0];
        patients[0] = temp;
        patients.pop_back();

        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }
    else
    {
        patients.pop_back();
    }
    heapSize--;
}

int PatientPriorityQueue::size() {
    return (int) patients.size();
}


string PatientPriorityQueue::to_string() {
    std::stringstream ss;

    for(long unsigned int i=0; i < patients.size(); i++)
        ss << patients.at(i).to_string() << '\n';

    return ss.str();

}

// Function to heapify the tree
void PatientPriorityQueue :: heapify( int i) {
    int size =patients.size();

    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && patients[largest] < patients[l])
        largest = l;
    if (r < size && patients[largest] < patients[r])
        largest = r;

    // Swap and continue heapify if root is not large
    if (largest != i) {
        Patient temp("","",-1);
        temp = patients[largest];
        patients[largest]=patients[i];
        patients[i] = temp;

        heapify(largest);
    }
}

#endif //P3_UPDATED_PATIENTPRIORITYQUEUE_H