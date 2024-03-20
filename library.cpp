#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    Book* next;
};

Book* top = nullptr;

// Function to add a book to the library
void addBook(string title) {
    Book* newBook = new Book;
    newBook->title = title;
    newBook->next = top;
    top = newBook;
    cout << "Book added successfully.\n";
}

// Function to remove the last added book from the library
void removeBook() {
    if (top == nullptr) {
        cout << "Library is empty.\n";
        return;
    }
    Book* temp = top;
    top = top->next;
    delete temp;
    cout << "Last book removed successfully.\n";
}

// Function to display all books in the library
void displayBooks() {
    if (top == nullptr) {
        cout << "Library is empty.\n";
        return;
    }
    Book* current = top;
    cout << "Books in the library:\n";
    while (current != nullptr) {
        cout << current->title << endl;
        current = current->next;
    }
}

// Function to search for a book by its title
void searchBook(string title) {
    Book* current = top;
    while (current != nullptr) {
        if (current->title == title) {
            cout << "Book found in the library.\n";
            return;
        }
        current = current->next;
    }
    cout << "Book not found in the library.\n";
}

// Function to delete all books from the library
void clearLibrary() {
    while (top != nullptr) {
        Book* temp = top;
        top = top->next;
        delete temp;
    }
    cout << "Library cleared successfully.\n";
}

int main() {
    int choice;
    string title;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a book\n";
        cout << "2. Remove last added book\n";
        cout << "3. Display all books\n";
        cout << "4. Search for a book\n";
        cout << "5. Clear library\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the title of the book: ";
                cin.ignore();
                getline(cin, title);
                addBook(title);
                break;
            case 2:
                removeBook();
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                cout << "Enter the title of the book to search: ";
                cin.ignore();
                getline(cin, title);
                searchBook(title);
                break;
            case 5:
                clearLibrary();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
