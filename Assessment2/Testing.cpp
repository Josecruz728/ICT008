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

void displayArray(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].displayBookDetails();
    }
}

int main() {
    cout << "TEST APPLICATION - BOOK CLASS AND SORTING FUNCTION" << endl;
    cout << "==================================================" << endl;

    cout << "\n1. Correct Book Information Initialisation" << endl;
    cout << "==================================================" << endl;

    Book book1, book2, book3;

    book1.setBookDetails("C++ Basics", "John Smith", "101", true, "12/01/2024");
    book2.setBookDetails("Data Structures", "Jane Doe", "102", true, "05/03/2023");
    book3.setBookDetails("Algorithms", "Mark Lee", "103", false, "18/07/2022");

    book1.displayBookDetails();
    book2.displayBookDetails();
    book3.displayBookDetails();

    cout << "\n2. Incorrect Book Information Initialisation" << endl;
    cout << "==================================================" << endl;

    Book wrongBook1, wrongBook2, wrongBook3;

    // These records contain incorrect or invalid information for testing purposes.
    wrongBook1.setBookDetails("", "Peter Brown", "ABC", true, "wrong-date");
    wrongBook2.setBookDetails("Invalid Book", "", "10X", false, "35/15/2024");
    wrongBook3.setBookDetails("No ISBN Book", "Unknown Author", "", true, "2024");

    wrongBook1.displayBookDetails();
    wrongBook2.displayBookDetails();
    wrongBook3.displayBookDetails();

    cout << "\n3. Sorting Test - Ascending Order Array" << endl;
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

    cout << "\n4. Sorting Test - Descending Order Array" << endl;
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

    cout << "\n5. Sorting Test - Mixed Order Array" << endl;
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

////testing that the Github repository is updated -----Done Jose Cruz


////verifying that the Github repository is public and can be opened from another PC or device ---- Done Jose Cruz
