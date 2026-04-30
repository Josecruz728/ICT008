#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdd;

public:
    void setBookDetails(string t, string a, string i, bool av, string d) {
        title = t;
        author = a;
        isbn = i;
        availability = av;
        dateAdd = d;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "-----------------------------" << endl;
    }

    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        availability = true;
    }

    string getISBN() {
        return isbn;
    }
};

// Phase 2 class: Hardcopy book inherits from Book
class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    void setShelfNumber(string shelf) {
        shelfNumber = shelf;
    }

    void displayHardcopyBookDetails() {
        Book::displayBookDetails();
        cout << "Shelf Number: " << shelfNumber << endl;
        cout << "-----------------------------" << endl;
    }
};

// Phase 2 class: E-book inherits from Book
class EBook : public Book {
private:
    string licenseExpiryDate;

public:
    void setLicenseExpiryDate(string date) {
        licenseExpiryDate = date;
    }

    void displayEBookDetails() {
        Book::displayBookDetails();
        cout << "License Expiry Date: " << licenseExpiryDate << endl;
        cout << "-----------------------------" << endl;
    }
};

class LibrarySystem {
private:
    Book books[5];
    int bookCount;

public:
    LibrarySystem() {
        bookCount = 5;
    }

    void initialiseBooks() {
        books[0].setBookDetails("C++ Basics", "John Smith", "102", true, "12/01/2024");
        books[1].setBookDetails("Data Structures", "Jane Doe", "101", true, "05/03/2023");
        books[2].setBookDetails("Algorithms", "Mark Lee", "105", true, "18/07/2022");
        books[3].setBookDetails("OOP Concepts", "Anna White", "103", true, "21/09/2024");
        books[4].setBookDetails("Programming Logic", "David Brown", "104", true, "10/11/2021");
    }

    void displayAllBooks() {
        cout << endl;
        cout << "Library Book List" << endl;
        cout << "=============================" << endl;

        for (int i = 0; i < bookCount; i++) {
            books[i].displayBookDetails();
        }
    }

    int findBookByISBN(string isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getISBN() == isbn) {
                return i;
            }
        }
        return -1;
    }

    void borrowBookByISBN(string isbn) {
        int index = findBookByISBN(isbn);

        if (index == -1) {
            cout << "Error: ISBN not found." << endl;
        }
        else {
            if (books[index].borrowBook()) {
                cout << "Book borrowed successfully." << endl;
                cout << "Updated book details:" << endl;
                books[index].displayBookDetails();
            }
            else {
                cout << "Error: This book is already borrowed." << endl;
            }
        }
    }

    void sortBooksByISBN() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].getISBN() > books[j + 1].getISBN()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    LibrarySystem librarySystem;
    librarySystem.initialiseBooks();
    librarySystem.sortBooksByISBN();

    string inputISBN;

    while (true) {
        librarySystem.displayAllBooks();

        cout << "Enter ISBN to borrow a book (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program terminated." << endl;
            break;
        }

        librarySystem.borrowBookByISBN(inputISBN);
    }

    return 0;
}