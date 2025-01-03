#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a book
struct Book {
    string title;
    string author;
    int id;
    bool isAvailable;

    Book(string title, string author, int id)
        : title(title), author(author), id(id), isAvailable(true) {}
};

// Define a structure to represent a member
struct Member {
    string name;
    int id;
    vector<Book*> borrowedBooks;

    Member(string name, int id) : name(name), id(id) {}
};

// Function prototypes
void addBook(vector<Book>& library);
void addMember(vector<Member>& members);
void lendBook(vector<Book>& library, vector<Member>& members);
void displayBooks(const vector<Book>& library);
void displayMembers(const vector<Member>& members);

// Main function
int main() {
    vector<Book> library;
    vector<Member> members;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Lend Book\n";
        cout << "4. Display Books\n";
        cout << "5. Display Members\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                addMember(members);
                break;
            case 3:
                lendBook(library, members);
                break;
            case 4:
                displayBooks(library);
                break;
            case 5:
                displayMembers(members);
                break;
            case 6:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 6." << endl;
        }
    } while (choice != 6);

    return 0;
}

// Function to add a new book to the library
void addBook(vector<Book>& library) {
    string title, author;
    int id;

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter book ID: ";
    cin >> id;

    for (const auto& book : library) {
        if (book.id == id) {
            cout << "Book with this ID already exists. Try again." << endl;
            return;
        }
    }

    library.emplace_back(title, author, id);
    cout << "Book added successfully!" << endl;
}

// Function to add a new member to the library
void addMember(vector<Member>& members) {
    string name;
    int id;

    cout << "Enter member name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter member ID: ";
    cin >> id;

    for (const auto& member : members) {
        if (member.id == id) {
            cout << "Member with this ID already exists. Try again." << endl;
            return;
        }
    }

    members.emplace_back(name, id);
    cout << "Member added successfully!" << endl;
}

// Function to lend a book to a member
void lendBook(vector<Book>& library, vector<Member>& members) {
    int memberId, bookId;
    cout << "Enter member ID: ";
    cin >> memberId;
    cout << "Enter book ID: ";
    cin >> bookId;

    Member* member = nullptr;
    for (auto& m : members) {
        if (m.id == memberId) {
            member = &m;
            break;
        }
    }

    if (!member) {
        cout << "Member not found." << endl;
        return;
    }

    Book* book = nullptr;
    for (auto& b : library) {
        if (b.id == bookId) {
            book = &b;
            break;
        }
    }

    if (!book) {
        cout << "Book not found." << endl;
        return;
    }

    if (!book->isAvailable) {
        cout << "Book is already lent out." << endl;
        return;
    }

    book->isAvailable = false;
    member->borrowedBooks.push_back(book);
    cout << "Book successfully lent to " << member->name << "." << endl;
}

// Function to display all books in the library
void displayBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "No books in the library." << endl;
        return;
    }

    cout << "\nLibrary Books:\n";
    for (const auto& book : library) {
        cout << "Title: " << book.title
             << ", Author: " << book.author
             << ", ID: " << book.id
             << (book.isAvailable ? " (Available)" : " (Not Available)") << endl;
    }
}

// Function to display all members in the library
void displayMembers(const vector<Member>& members) {
    if (members.empty()) {
        cout << "No members registered." << endl;
        return;
    }

    cout << "\nLibrary Members:\n";
    for (const auto& member : members) {
        cout << "Name: " << member.name << ", ID: " << member.id << "\nBorrowed Books: ";
        if (member.borrowedBooks.empty()) {
            cout << "None" << endl;
        } else {
            for (const auto& book : member.borrowedBooks) {
                cout << book->title << " (ID: " << book->id << "), ";
            }
            cout << endl;
        }
    }
}
