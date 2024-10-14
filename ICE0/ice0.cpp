//Name:- Tejal Patel
// Date:- 03/27/2024
// File:- ice0.cpp
//Purpose:-  The purpose of this assignment is to create a basic calculator
// program in c++ which can perform operations like addition, subtraction,
// multiplication and division.
// Output:- The final output of the program is giving the addition of 2
// numbers as per users choice, subtraction, division and multiplication  of
// two  numbers as per input taken from the users.

# include <iostream>
using namespace std;

double addition(double x, double y);
double subtraction(double x, double y);
double multiplication(double x, double y);
double division(double x, double y);

int main() {
    int choice;
    double num1, num2;

    cout << "Welcome to the Calculator Program!" << endl;

    do {

        cout << "\n 1.Addition\n 2.Subtraction\n 3. Multiplication\n 4. "
                "Division\n 5. "
                "Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter two numbers for addition: ";
                cin >> num1 >> num2;
                cout << "Result: " << addition(num1, num2) << endl;
                break;
            case 2:
                cout << "Enter two numbers for subtraction: ";
                cin >> num1 >> num2;
                cout << "Result: " << subtraction(num1, num2) << endl;
                break;
            case 3:
                cout << "Enter two numbers for multiply: ";
                cin >> num1 >> num2;
                cout << "Result: " << multiplication(num1, num2) << endl;
                break;
            case 4:
                cout << "Enter two numbers for divide: ";
                cin >> num1 >> num2;
                if (num2 != 0)
                    cout << "Result: " << division(num1, num2) << endl;
                else
                    cout << "Error: division by zero is not allowed." << endl;
                break;
            case 5:
                cout << "Thank you for using the Calculator Program!" << endl;
                break;
            default:
                cout << "Invalid choice,enter a number between 1 and "
                        "5." << endl;
        }
    } while(choice != 5);

    return 0;
}


double addition(double x, double y) {
    return x + y;
}

double subtraction(double x, double y) {
    return x - y;
}

double multiplication(double x, double y) {
    return x * y;
}

double division(double x, double y) {
    return x / y;
}