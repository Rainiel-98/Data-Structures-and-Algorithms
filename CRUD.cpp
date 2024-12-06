#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    int year;
};

vector<Book> library;

// Function to display the details of a single book
void displayBook(const Book& book) {
    cout << "Title: " << book.title << "\n";
    cout << "Author: " << book.author << "\n";
    cout << "ISBN: " << book.isbn << "\n";
    cout << "Year: " << book.year << "\n";
    cout << "-----------------------------\n";
}

void addBook() {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter ISBN: ";
    cin >> newBook.isbn;
    cout << "Enter year of publication: ";
    cin >> newBook.year;
    library.push_back(newBook);
    cout << "Book added successfully!\n";
}

void listBooks() {
    if (library.empty()) {
        cout << "No books available in the library.\n";
        return;
    }
    for (size_t i = 0; i < library.size(); ++i) {
        cout << "Book #" << i + 1 << "\n";
        displayBook(library[i]);
    }
}

void updateBook() {
    string isbn;
    cout << "Enter ISBN of the book to update: ";
    cin >> isbn;
    for (auto& book : library) {
        if (book.isbn == isbn) {
            cout << "Updating details for the book: \n";
            displayBook(book);
            cout << "Enter new title (leave blank to keep unchanged): ";
            cin.ignore();
            string newTitle;
            getline(cin, newTitle);
            if (!newTitle.empty()) book.title = newTitle;
            
            cout << "Enter new author (leave blank to keep unchanged): ";
            string newAuthor;
            getline(cin, newAuthor);
            if (!newAuthor.empty()) book.author = newAuthor;
            
            cout << "Enter new year of publication (0 to keep unchanged): ";
            int newYear;
            cin >> newYear;
            if (newYear != 0) book.year = newYear;
            
            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n";
}

void deleteBook() {
    string isbn;
    cout << "Enter ISBN of the book to delete: ";
    cin >> isbn;
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->isbn == isbn) {
            library.erase(it);
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n";
}

void menu() {
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. List Books\n";
        cout << "3. Update Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
