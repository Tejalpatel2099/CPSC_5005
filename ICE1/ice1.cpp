//Name:- Tejal Patel
#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date d;
    d.setDate(1,1,2012);
    d.getDate();
    cout << d.getSeason() << endl;
    cout << endl;

    d.setDate(3,10,1996);
    d.getDate();
    cout << d.getSeason() << endl;
    cout << endl;

    d.setDate(6,20,2015);
    d.getDate();
    cout << d.getSeason() << endl;
    cout << endl;

    d.setDate(9,22,2000);
    d.getDate();
    cout << d.getSeason() << endl;
    cout << endl;

    d.setDate(12,25,1980);
    d.getDate();
    cout << d.getSeason() << endl;
    cout << endl;

    d.setDate(11,22,2001);
    d.getDate();
    cout << d.getSeason() << endl;
    cout << endl;

    d.setDate(10,31,2017);
    d.getDate();
    cout << d.getSeason() << endl;
    cout << endl;

    d.setDate(9,23,2011);
    d.getDate();
    cout << d.getSeason() << endl;
    cout << endl;


}
