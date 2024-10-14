// Name:- Tejal Patel
// Date :- 04/16/2024
// file :- p1.cpp
// purpose :-
#include <iostream>
#include "BookList.h"
#include "MemberList.h"
#include "RatingList.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//Function to print welcome message
void printWelcomeMessage();

// function to print main menu
// Modify:- none
// out: none
void printMainMenu(BookList *bookList, MemberList *memberList, RatingList
*ratingList);

// To print GoodBye message
void printGoodByeMessage();

// function to read books from input file
// modify:- none
// out:- none
void readBooksFromInputFile(BookList *list, string basicString, int isbnNumber);

// function to read ratings from input file
// modify:- none
// in:- memberlist, ratinglist
// out :- none
void readRatingsFromInputFile(MemberList *memberList, RatingList *ratingList,
                              string fileName, int accountNumber);

// function to rate a book
// modify:- none
// out:- none
void rateBook(BookList *bookList, MemberList *memberList, RatingList
*ratingList, int accountNumber);


// function to print main menu
// input:- book list, member list, rating list, account number
// out:- none
void printMemberMenu(BookList *bookList, MemberList *memberList, RatingList
*ratingList, int accountNumber);

// function to display account ratings
// modify:- none
// out :- none
void displayAccountRatings(BookList *bookList, MemberList *memberList,
                           RatingList *ratingList, int accountNumber);

// function to display recommendations
// modify:- none
// out :- none
void displayRecommendations(BookList *bookList, MemberList *memberList,
                            RatingList *ratingList, int accountNumber);


int main()
{
    const int SIZE = 100;                        //  hold SIZE
    int accountNumber = 1;                       // initialize accountNumber
    string booksFile = "books.txt";              // file name booksFile
    string ratingsFile = "ratings.txt";          // To hold ratingsFile
    int isbnCounter = 1;                         //initalize isbnCounter
    ifstream myFile;                             // holds myFile
    string line;                                 //  holds line

    BookList bookList(SIZE);

    MemberList memberList(SIZE);

    RatingList ratingList(SIZE, SIZE);

    printWelcomeMessage();  // prints welcome message

    cout << endl;
    cout << "Enter books file: ";
    cin >> booksFile;
    cout << "Enter rating file: ";
    cin >> ratingsFile;

    readBooksFromInputFile(&bookList, booksFile, isbnCounter);

    cout << endl;
    cout << "# of books: " << bookList.size() << endl;

    readRatingsFromInputFile(&memberList, &ratingList, ratingsFile,
                             accountNumber);

    cout << "# of memberList: " << memberList.size() << "\n" << endl;

    printMainMenu(&bookList, &memberList, &ratingList);

    printGoodByeMessage();

}
 // function to print welcome message
void printWelcomeMessage()
{
    cout << endl;
    cout << "Welcome to the Book Recommendation Program." << endl;
    cout << "This program keeps the track of information regarding Book "
            "Recommendation.\nAlso provides many functionalities to the "
            " user like Add a new member, Add a new book, Rate book, \nView "
            "ratings and See recommendations after user successfully logged in";
    cout << "" << endl;

}

// function to print main menu
void printMainMenu(BookList *bookList, MemberList *memberList, RatingList
*ratingList)
{
    int menu;                                      // To hold menu
    string memberName;                             // To hold memberName
    string authorName;                             // To hold authorName
    string newBookTitle;                           // To hold newBookTitle
    string year;                                   // To hold year
    int accountNumber;                             // To hold accountNumber
    while (1)
    {
        cout << endl;
        cout << "************** MENU **************" << endl;
        cout << "* 1. Add a new member            *" << endl;
        cout << "* 2. Add a new book              *" << endl;
        cout << "* 3. Login                       *" << endl;
        cout << "* 4. Quit                        *" << endl;
        cout << "**********************************" << endl;

        cout << "\nEnter a menu option: ";
        cin >> menu;
        cout << endl;

        switch (menu) {
            case 1:
                cout << "Enter the name of the new member: ";
                cin >> memberName;
                memberList->add(memberName, (memberList->size()),
                                true);
                break;

            case 2:
                cout << "Enter the author of the new book: ";
                cin.ignore();
                getline(cin, authorName);

                cout << "Enter the title of the new book: ";
                getline(cin, newBookTitle);

                cout << "Enter the year (or range of years) of the new book: ";
                cin >> year;

                bookList->add(bookList->size()+1, authorName,
                              newBookTitle,year);

                cout << bookList->size() << ", " << authorName << ", "
                     << newBookTitle
                     << ", " << year << " was added." << endl;
                break;

            case 3:
                cout << "Enter member account: ";
                cin >> accountNumber;
                cout << memberList->getMemberName((accountNumber)) + ", you "
                                                                     "are "
                                                                     "logged "
                                                                     "in! \n";
                printMemberMenu(bookList, memberList, ratingList,
                                accountNumber);
                break;

            case 4:
                printGoodByeMessage();
                exit(1);
        }
    }
}

void printMemberMenu(BookList *bookList, MemberList *memberList, RatingList
*ratingList, int accountNumber)
{
    while (1)
    {
        int menu;                                   //  holds menu
        string memberName;                          // this hold memberName
        string authorName;                          //  holds authorName
        string newBookTitle;                        // holds newBookTitle
        string year;                                // To hold year

        cout << endl;
        cout << "************** MENU **************" << endl;
        cout << "* 1. Add a new member            *" << endl;
        cout << "* 2. Add a new book              *" << endl;
        cout << "* 3. Rate book                   *" << endl;
        cout << "* 4. View ratings                *" << endl;
        cout << "* 5. See recommendations         *" << endl;
        cout << "* 6. Logout                      *" << endl;
        cout << "**********************************" << endl;

        cout << "\nEnter a menu option: ";
        cin >> menu;
        cout << endl;
        switch (menu) {
            case 1:
                cout << "Enter the name of the new member: ";
                cin >> memberName;
                memberList->add(memberName, (memberList->size()),
                                true);
                break;

            case 2:
                cout << "Enter the author of the new book: ";
                cin.ignore();
                getline(cin, authorName);

                cout << "Enter the title of the new book: ";

                getline(cin, newBookTitle);
                cout << "Enter the year (or range of years) of the new book: ";
                cin >> year;

                bookList->add(bookList->size()+1, authorName,
                              newBookTitle,year);

                cout << bookList->size() << ", " << authorName << ", "
                     << newBookTitle << ", " << year << " was added." << endl;
                break;

            case 3://Rate a book
                rateBook(bookList, memberList, ratingList, accountNumber);
                break;

            case 4:// view Ratings
                displayAccountRatings(bookList, memberList, ratingList,
                                      accountNumber);
                break;

            case 5:// See Recommendations
                displayRecommendations(bookList, memberList, ratingList,
                                       accountNumber);
                break;

            case 6: // logout
                printMainMenu(bookList, memberList, ratingList);
                exit(1);

            default:
                cout << "Please enter a valid input";
                break;
        }
    }
}
void rateBook(BookList *bookList,MemberList *memberList,RatingList *ratingList,
              int accountNumber)
{
    int isbn;                                     // To hold ISBN
    char choice;                                  // To hold choice

    cout << "Enter the ISBN for the book you'd like to rate: ";
    cin >> isbn;

    for (int i = 0; i < bookList->size(); i++)
    {
        int r;
        if (bookList->getIsbnNumber(i) == isbn)
        {
            r = ratingList->getRating(accountNumber, (bookList->getIsbnNumber
                    (i)));
            if (r == 0)
            {
                int rating;
                cout << "Enter your rating: ";
                cin >> rating;

                ratingList->addOrUpdate(isbn, accountNumber,
                                        rating);
                cout << "Your new rating for " << bookList->get
                        (i) << " => rating: " << ratingList->getRating
                        (accountNumber, isbn)
                     << endl;

            }
            else
            {
                cout << "Your current rating for " << bookList->get
                        (i) << " => rating: " << ratingList->getRating
                        (accountNumber, isbn)
                     << endl;

                cout << "Would you like to re-rate this book (y/n)? ";
                cin >> choice;

                if (choice == 'Y'|| choice == 'y' ){
                    int newRating = 0;
                    cout << "Enter your rating: ";
                    cin >> newRating;


                    ratingList->addOrUpdate(isbn,
                                            accountNumber, newRating);
                    cout << "Your new rating for " << bookList->get
                            (i) << " => rating: " << ratingList->getRating
                            (accountNumber, bookList->getIsbnNumber(i))
                         << endl;
                    break;
                }
                else{
                    printMemberMenu(bookList,memberList,ratingList,
                                    accountNumber);
                }

            }
        }
    }
}

void displayAccountRatings(BookList *bookList, MemberList *memberList,RatingList
*ratingList, int accountNumber)
{

    cout << memberList->getMemberName((accountNumber)) << "'s ratings... \n";

    for (int i = 0; i < bookList->size(); i++) {
        cout << bookList->get(i) << " => rating: " << ratingList->getRating
                ((accountNumber), (bookList->getIsbnNumber(i))) << endl;
    }
}

void displayRecommendations(BookList *bookList, MemberList *memberList,
                            RatingList *ratingList, int accountNumber)
{
    int bestRatingMatch = 0;                    // To hold bestRatingMatch
    int bestRatingMatchAccount = 0;           // To hold bestRatingMatchAccount
    int bookCounter = 1;                        // To hold bookCounter
    int memberCounter = 1;                      // To hold memberCounter
    int matchCounter = 0;                       // To hold matchCounter
    int memberRating = 0;                       // To hold memberRating
    int accountRating = 0;                      // To hold accountRating

    while (memberCounter <= memberList->size()) {
        if (memberCounter != accountNumber) {
            while (bookCounter <= bookList->size()) {
                accountRating = (ratingList->getRating(accountNumber,
                                                       bookList->getIsbnNumber
                                                               (bookCounter)));

                memberRating = (ratingList->getRating(memberCounter,
                                                      bookList->getIsbnNumber(
                                                              bookCounter)));

                if (accountRating >= -5 && accountRating <= 5 &&
                    memberRating >= -5 && memberRating <= 5)
                    matchCounter += (accountRating * memberRating);
                bookCounter++;
            }

            if (bestRatingMatch < matchCounter)
            {
                bestRatingMatch = matchCounter;
                bestRatingMatchAccount = memberCounter;
            }
        }

        bookCounter = 0;
        memberCounter++;
        matchCounter = 0;
    }

    cout << "\nYou have similar taste in books as " <<
         memberList->getMemberName((bestRatingMatchAccount)) << "!" << endl;

    int rating = 0;                                // To hold rating
    stringstream likedBooks;                       // To hold likedBooks
    stringstream mostLikedBooks;                   // To hold mostLikedBooks

    for (int i = 1; i <= bookList->size(); i++)
    {
        rating = ratingList->getRating(bestRatingMatchAccount, i);

        if (rating == 3 && ratingList->getRating(accountNumber,i) == 0)
        {
            likedBooks << bookList->get(i-1) << endl;
        } else if (rating == 5 && ratingList->getRating(accountNumber,i) == 0)
        {
            mostLikedBooks << bookList->get(i-1) << endl;
        }
        rating = 0;
    }
    cout << endl;
    cout << endl;
    cout << "Here are the books they really liked: " << endl;
    cout << mostLikedBooks.str();
    cout << endl;
    cout << endl;
    cout << "And here are the books they liked: " << endl;
    cout << likedBooks.str();
}

void readBooksFromInputFile(BookList *list, string booksFile, int isbnCounter)
{
    string line = "";
    int counter = 0;
    ifstream myfile(booksFile);
    string arr[3];
    if (myfile.is_open())
    {
        while (getline(myfile, line, '\n'))
        {
            istringstream ss(line);
            string token;

            while (getline(ss, token, ','))
            {
                arr[counter] = token;
                ++counter;
            }

            list->add(isbnCounter, arr[0],arr[1],
                      arr[2]);
            isbnCounter++;
            counter = 0;                    //resetting counter for next line
        }
    }
    myfile.close();
}

void readRatingsFromInputFile(MemberList *memberList, RatingList *ratingList,
                              string fileName, int accountNumber)
{
    string line = "";
    int counter = 0;
    int bookCounter = 1;
    ifstream myfile(fileName);
    string arr[3];
    if (myfile.is_open()) {
        while (getline(myfile, line, '\n'))
        {
            string token;
            if (counter % 2 == 0)
            {
                memberList->add(line, accountNumber, false);
            }
            else
            {
                istringstream ss(line);
                string token;

                while (getline(ss, token, ' '))
                {
                    ratingList->addOrUpdate(bookCounter, accountNumber,
                                            stoi(token));
                    bookCounter++;
                }
                bookCounter=1;
                accountNumber++;
            }
            counter++;
        }
    }
    myfile.close();
}

void printGoodByeMessage()
{
    cout << "\nThank you for using the Book Recommendation Program!"
         << endl;
}