#include <iostream>
# include "Date.h"
using namespace std;

Date::Date ()
{
    month = 0;
    day = 0;
    year = 0;
}

Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::setDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;

}
void Date::getDate() const{

    cout << month <<"/" << day <<"/" << year << endl;

}

string Date::getSeason() const
{
    if((month > 3 || (month==3 && day>=21)) && (month<6 || (month==6 &&
    day<21)))
        return "Spring";

    else if((month >6 || (month==6 && day>=21)) && (month<9 || (month==9 &&
    day<23)))
        return "Summer";

    else if((month>9 || (month==9 && day>=23)) && (month<12 || (month==12 &&
    day<22)))
        return "Fall";

    else
        return "Winter";

}