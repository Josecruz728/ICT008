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
    }

    string getISBN() {
        return isbn;
    }

    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].getISBN() > books[j + 1].getISBN()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

// 🔹 HardcopyBook (Inheritance)
class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    void setShelfNumber(string shelf) {
        shelfNumber = shelf;
    }

    void displayBookDetails() {
        Book::displayBookDetails();
        cout << "Shelf Number: " << shelfNumber << endl;
        cout << "-----------------------------" << endl;
    }
};

// 🔹 EBook (Inheritance)
class EBook : public Book {
private:
    string licenseExpiryDate;

public:
    void setLicenseExpiryDate(string date) {
        licenseExpiryDate = date;
    }

    void displayBookDetails() {
        Book::displayBookDetails();
        cout << "License Expiry Date: " << licenseExpiryDate << endl;
        cout << "-----------------------------" << endl;
    }
};

void displayArray(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].displayBookDetails();
        cout << "-----------------------------" << endl;
    }
}

int main() {

    cout << "TEST APPLICATION - BOOK SYSTEM WITH INHERITANCE AND SORTING" << endl;
    cout << "============================================================" << endl;

    // 🔹 1. Correct Data
    cout << "\n1. Correct Book Information Initialisation" << endl;
    cout << "==================================================" << endl;

    Book book1, book2, book3;

    book1.setBookDetails("C++ Basics", "John Smith", "101", true, "12/01/2024");
    book2.setBookDetails("Data Structures", "Jane Doe", "102", true, "05/03/2023");
    book3.setBookDetails("Algorithms", "Mark Lee", "103", false, "18/07/2022");

    book1.displayBookDetails(); cout << "-----------------------------" << endl;
    book2.displayBookDetails(); cout << "-----------------------------" << endl;
    book3.displayBookDetails(); cout << "-----------------------------" << endl;

    // 🔹 2. Incorrect Data
    cout << "\n2. Incorrect Book Information Initialisation" << endl;
    cout << "==================================================" << endl;

    Book wrongBook1, wrongBook2, wrongBook3;

    wrongBook1.setBookDetails("", "Peter Brown", "ABC", true, "wrong-date");
    wrongBook2.setBookDetails("Invalid Book", "", "10X", false, "35/15/2024");
    wrongBook3.setBookDetails("No ISBN Book", "Unknown Author", "", true, "2024");

    wrongBook1.displayBookDetails(); cout << "-----------------------------" << endl;
    wrongBook2.displayBookDetails(); cout << "-----------------------------" << endl;
    wrongBook3.displayBookDetails(); cout << "-----------------------------" << endl;

    // 🔥 3. Inheritance Testing (CLAVE PARA TU NOTA)
    cout << "\n3. Inheritance Testing - HardcopyBook" << endl;
    cout << "==================================================" << endl;

    HardcopyBook hardcopy;
    hardcopy.setBookDetails("Clean Code", "Robert C. Martin", "201", true, "10/02/2024");
    hardcopy.setShelfNumber("B12");
    hardcopy.displayBookDetails();

    cout << "\n4. Inheritance Testing - EBook" << endl;
    cout << "==================================================" << endl;

    EBook ebook;
    ebook.setBookDetails("Digital Transformation", "Thomas Siebel", "202", true, "22/08/2023");
    ebook.setLicenseExpiryDate("30/12/2026");
    ebook.displayBookDetails();

    // 🔹 5. Sorting Tests
    cout << "\n5. Sorting Test - Ascending Order Array" << endl;
    cout << "==================================================" << endl;

    Book ascendingBooks[3];
    ascendingBooks[0].setBookDetails("C++ Basics", "John Smith", "101", true, "12/01/2024");
    ascendingBooks[1].setBookDetails("Data Structures", "Jane Doe", "102", true, "05/03/2023");
    ascendingBooks[2].setBookDetails("Algorithms", "Mark Lee", "103", false, "18/07/2022");

    cout << "\nBefore Sorting:" << endl;
    displayArray(ascendingBooks, 3);

    Book::sortBookData(ascendingBooks, 3);

    cout << "\nAfter Sorting:" << endl;
    displayArray(ascendingBooks, 3);

    cout << "\n6. Sorting Test - Descending Order Array" << endl;
    cout << "==================================================" << endl;

    Book descendingBooks[3];
    descendingBooks[0].setBookDetails("Algorithms", "Mark Lee", "103", false, "18/07/2022");
    descendingBooks[1].setBookDetails("Data Structures", "Jane Doe", "102", true, "05/03/2023");
    descendingBooks[2].setBookDetails("C++ Basics", "John Smith", "101", true, "12/01/2024");

    cout << "\nBefore Sorting:" << endl;
    displayArray(descendingBooks, 3);

    Book::sortBookData(descendingBooks, 3);

    cout << "\nAfter Sorting:" << endl;
    displayArray(descendingBooks, 3);

    cout << "\n7. Sorting Test - Mixed Order Array" << endl;
    cout << "==================================================" << endl;

    Book mixedBooks[3];
    mixedBooks[0].setBookDetails("Data Structures", "Jane Doe", "102", true, "05/03/2023");
    mixedBooks[1].setBookDetails("Algorithms", "Mark Lee", "103", false, "18/07/2022");
    mixedBooks[2].setBookDetails("C++ Basics", "John Smith", "101", true, "12/01/2024");

    cout << "\nBefore Sorting:" << endl;
    displayArray(mixedBooks, 3);

    Book::sortBookData(mixedBooks, 3);

    cout << "\nAfter Sorting:" << endl;
    displayArray(mixedBooks, 3);

    cout << "\nTest completed successfully." << endl;

    return 0;
}
