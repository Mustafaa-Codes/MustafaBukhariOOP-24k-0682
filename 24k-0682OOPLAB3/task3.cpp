/*
24k-0682
Syed Mustafa Bukhari
OOP Lab 3
*/
#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string bookList[10];      
    string borrowedBooks[10];  
    int totalBooks;            
    int totalBorrowed;         

public:
    // Constructor
    Library() : totalBooks(0), totalBorrowed(0) {}

    //  add a book
    void addBook(const string& book) {
        if (totalBooks < 10) {
            // Check  duplicates
            for (int i = 0; i < totalBooks; i++) {
                if (bookList[i] == book) {
                    cout << "Book \"" << book << "\" already exists in the library.\n";
                    return;
                }
            }
            bookList[totalBooks++] = book;
            cout << "Added book: " << book << endl;
        } else {
            cout << "Library is full! Cannot add more books.\n";
        }
    }

    //  borrow a book
    void borrowBook(const string& book) {
        if (totalBorrowed >= 10) {
            cout << "Cannot borrow more books. Borrowing limit reached!\n";
            return;
        }

        for (int i = 0; i < totalBooks; i++) {
            if (bookList[i] == book) {
                borrowedBooks[totalBorrowed++] = book;

                // Shift books to maintain order
                for (int j = i; j < totalBooks - 1; j++) {
                    bookList[j] = bookList[j + 1];
                }
                totalBooks--;

                cout << "Borrowed book: " << book << endl;
                return;
            }
        }
        cout << "Book \"" << book << "\" is not available in the library.\n";
    }

    // return a book
    void returnBook(const string& book) {
        if (totalBooks >= 10) {
            cout << "Library is full! Cannot return the book.\n";
            return;
        }

        for (int i = 0; i < totalBorrowed; i++) {
            if (borrowedBooks[i] == book) {
                bookList[totalBooks++] = book;

                // Shift borrowed books to maintain order
                for (int j = i; j < totalBorrowed - 1; j++) {
                    borrowedBooks[j] = borrowedBooks[j + 1];
                }
                totalBorrowed--;

                cout << "Returned book: " << book << endl;
                return;
            }
        }
        cout << "Book \"" << book << "\" was not borrowed from this library.\n";
    }

    //  display available books
    void displayAvailableBooks() const {
        cout << "\nAvailable Books in the Library:\n";
        if (totalBooks == 0) {
            cout << "No books available.\n";
        } else {
            for (int i = 0; i < totalBooks; i++) {
                cout << "- " << bookList[i] << endl;
            }
        }
    }

    //  display borrowed books
    void displayBorrowedBooks() const {
        cout << "\nBorrowed Books:\n";
        if (totalBorrowed == 0) {
            cout << "No books are currently borrowed.\n";
        } else {
            for (int i = 0; i < totalBorrowed; i++) {
                cout << "- " << borrowedBooks[i] << endl;
            }
        }
    }
};


int main() {
    Library hamzasLibrary;

    // Add books
    hamzasLibrary.addBook("C++ Programming");
    hamzasLibrary.addBook("Data Structures");
    hamzasLibrary.addBook("Algorithms");

    // Display available books
    hamzasLibrary.displayAvailableBooks();

    // Borrow a book
    hamzasLibrary.borrowBook("Data Structures");
    hamzasLibrary.displayAvailableBooks();
    hamzasLibrary.displayBorrowedBooks();

    // Return a book
    hamzasLibrary.returnBook("Data Structures");
    hamzasLibrary.displayAvailableBooks();
    hamzasLibrary.displayBorrowedBooks();

    return 0;
}
