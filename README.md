# Library Management System 📚

This project is a **Library Management System** implemented in C++. It enables library administrators to manage books, register members, lend books to members, and track book availability.

---

## Features ✨

1. **Add Books**  
   Add a new book to the library with details such as:
   - Title
   - Author
   - Unique Book ID

2. **Add Members**  
   Register new library members with details such as:
   - Name
   - Unique Member ID

3. **Lend Books**  
   - Lend a book to a member.
   - Ensure the book is available before lending.
   - Track which member borrowed which book.

4. **Display Books**  
   - View a list of all books in the library, along with their availability status.

5. **Display Members**  
   - View all registered members and the books they have borrowed.

---

## How to Use 🛠️

### Prerequisites:
- A C++ compiler (e.g., `g++`)

### Steps:
1. Clone this repository or copy the code into your project.
2. Compile the program:
   ```bash
   g++ library_management.cpp -o library_management


---

## How It Works 🛠️

1. **Add Book**: Allows users to add new books with title, author, and a unique ID.
2. **Add Member**: Enables the registration of new members with a name and unique ID.
3. **Lend Book**: Assigns an available book to a registered member.
4. **Display Books**: Shows a list of all books with their availability status.
5. **Display Members**: Lists all members along with the books they have borrowed.

---

## Notes 📋

- This program uses a menu-driven interface.
- Ensure unique IDs for books and members to avoid conflicts.
- Borrowed books are marked as "Not Available
