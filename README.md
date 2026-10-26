# Devixo-Solution-Internship___Task-2
Devixo-Solutions---C++ Internship___Task-2

# 📚 Library Management System
### Devixo-Solutions-Internship___Task 2 | C++

A console-based **Library Management System** developed in C++ as part of the Devixo Solutions internship. The project demonstrates object-oriented programming, menu-driven interaction, vector-based data management, input validation, and file handling.

---

## 📌 Table of Contents

- [Project Overview](#-project-overview)
- [Objectives](#-objectives)
- [Features](#-features)
- [Technologies Used](#-technologies-used)
- [Programming Concepts](#-programming-concepts)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
- [How to Use](#-how-to-use)
- [Data Storage and File Handling](#-data-storage-and-file-handling)
- [Input Validation](#-input-validation)
- [Testing](#-testing)
- [Limitations](#-limitations)
- [Future Improvements](#-future-improvements)
- [Internship Information](#-internship-information)
- [Author](#-author)

---

## 📖 Project Overview

The Library Management System provides a simple way to manage book records through an interactive command-line interface.

Users can add new books, display all available records, search for books by title or author, update book information, delete records, issue books, and process book returns.

The application stores book records in a text file so that the data can be loaded when the program starts, provided the file is available in the program's working directory.

This project was developed to apply fundamental C++ programming techniques to a practical, menu-driven application.

## 🎯 Objectives

The main objectives of this project are to:

- Apply classes and objects to organize book records and library operations.
- Use constructors to initialize book objects.
- Implement multiple functions for modular program design.
- Manage collections of books using vectors.
- Implement file handling to save and load records.
- Develop an interactive menu-driven console application.
- Validate user input and handle common invalid entries.
- Implement book searches by both title and author.

## ✨ Features

| Feature | Description |
|---|---|
| Add Book | Adds a book using a unique positive ID, title, and author. |
| View Books | Displays the stored book records and their issue status. |
| Search Book | Searches for matching titles or author names. |
| Update Book | Updates the title and author of an existing book. |
| Delete Book | Deletes an existing book that has not been issued. |
| Issue Book | Marks an available book as issued. |
| Return Book | Changes an issued book's status to available. |
| Save Data | Saves book records to a text file. |
| Load Data | Loads saved book records from the text file. |
| Input Validation | Handles invalid menu choices, non-numeric integer inputs, and duplicate IDs. |

### ⭐ Bonus Feature

The application supports searching by **both book title and author**, including case-insensitive keyword matching.

For example, searching for `discrete` can find a book titled `Discrete Mathematics`, regardless of the capitalization of the search term.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Standard Library:** `iostream`, `vector`, `string`, `fstream`, `sstream`, `algorithm`, and `cctype`
- **Data Structure:** `vector<Book>`
- **Data Storage:** Text file (`book_data.txt`)
- **Development Environment:** Code Utility Online Compiler

## 🧠 Programming Concepts

### 1. Classes and Objects

The program uses two main classes:

- **`Book`** — represents a book with an ID, title, author, and issue status.
- **`Library`** — manages book records and provides the library operations.

### 2. Constructors

The `Book` constructor initializes the attributes of each book object. The `Library` constructor loads saved data when a library object is created.

### 3. Functions

Separate member functions handle operations such as adding, viewing, searching, updating, deleting, issuing, returning, saving, and loading books.

### 4. Vectors

A `vector<Book>` stores the book objects. It supports adding new records and removing records dynamically as required.

### 5. File Handling

The program uses file streams, including `ifstream` and `ofstream`, to read and write book records.

### 6. Menu-Driven Programming

A loop and a `switch` statement display the menu and execute the operation selected by the user.

### 7. Input Validation

The program validates integer input, checks for positive and duplicate book IDs, rejects empty titles and author names, and prevents deletion of an issued book.

### 8. Searching and String Processing

The program uses string operations and case normalization to search for title or author keywords without case sensitivity.

## 📁 Project Structure

The repository is organized as follows:

```text
Devixo-Library-Management-System/
│
├── main.cpp
├── README.md
├── book_data.txt
└── screenshots/
    ├── main-menu.png
    ├── book-operations.png
    └── search-results.png
```

**Note:** The screenshots folder is optional. Include it only if you upload genuine screenshots. Include `book_data.txt` only if you intend to provide sample records; otherwise, the application can create the file when it saves data.

## 🚀 Getting Started

### Prerequisites

You need a C++ compiler that supports the standard library and file input/output.

Examples include:

- GCC / G++
- Code::Blocks
- Visual Studio
- A compatible online C++ compiler

### Installation

1. Clone or download this repository.
2. Open the project directory.
3. Open `main.cpp` in your preferred C++ editor or compiler.
4. Compile and execute the program.

### Compile Using G++

If G++ is installed, run:

```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o library
```

On Windows, run:

```bash
library.exe
```

On Linux or macOS, run:

```bash
./library
```

Alternatively, paste the contents of `main.cpp` into a compatible online C++ compiler and run it.

## 🖥️ How to Use

After starting the application, the main menu presents the available operations.

```text
================================
   LIBRARY MANAGEMENT SYSTEM
================================
1. Add Book
2. View Books
3. Search Book
4. Update Book Information
5. Delete Book
6. Issue Book
7. Return Book
8. Save Data
9. Load Data
0. Exit
================================
Enter your choice:
```

### Example Workflow

1. Select **Add Book** and enter the book ID, title, and author.
2. Select **View Books** to display stored records.
3. Select **Search Book** to search by title or author.
4. Select **Update Book Information** to edit a record.
5. Select **Issue Book** to mark an available book as issued.
6. Select **Return Book** to make an issued book available again.
7. Select **Save Data** to write records to the text file.
8. Select **Exit** to save the records and close the application.

## 💾 Data Storage and File Handling

The application stores book records in `book_data.txt`.

Each record uses a pipe-separated format:

```text
101|Maths|Zeeshan Bashir|0
102|C++ Programming OPP |Zeeshan Bashir|1
```

The fields represent:

1. Book ID
2. Book title
3. Author name
4. Issue status (`0` = available, `1` = issued)

When the program starts, the `Library` constructor calls the data-loading function. Book records are saved when operations modify the library, and the program also saves data when the user exits.

**Important:** The text file is created in the program's working directory. Some online compilers use temporary storage, so file persistence across separate executions depends on the compiler's environment.

## 🛡️ Input Validation

The application includes checks to improve reliability:

- Rejects invalid integer input.
- Rejects non-positive book IDs.
- Prevents duplicate book IDs.
- Rejects empty titles and author names.
- Prevents deleting an issued book.
- Prevents issuing an already issued book.
- Prevents returning a book that is not issued.
- Reports when a requested book cannot be found.
- Rejects the pipe character (`|`) in titles and author names because it separates fields in the data file.

## 🧪 Testing

The program was tested through its interactive menu.

| Test | Expected Behaviour |
|---|---|
| Add a book | The new record is added successfully. |
| View books | Stored records are displayed. |
| Search by title | Matching titles are displayed. |
| Search by author | Matching authors are displayed. |
| Update book | The selected record is updated. |
| Delete book | An eligible record is removed. |
| Issue book | Available book status changes to issued. |
| Return book | Issued book status changes to available. |
| Save data | Records are written to the text file. |
| Load data | Saved records are loaded. |
| Invalid menu input | An error message is displayed. |
| Duplicate book ID | The duplicate record is rejected. |

*Testing note: Restart-based file persistence should be reported as verified only after confirming that saved records remain available in a subsequent execution in the same persistent environment.*

## ⚠️ Limitations

- The application is console-based and does not have a graphical user interface.
- Book records are stored in a local text file rather than a database.
- The application does not manage member accounts, borrowing dates, or overdue fines.
- The data-file format reserves the pipe character as a field separator.
- File persistence depends on the execution environment and working directory.

## 🔮 Future Improvements

Potential extensions include:

- A graphical user interface.
- Database integration using SQLite or MySQL.
- Library member registration and management.
- Borrowing dates, due dates, and overdue fines.
- Sorting and filtering book records.
- More robust recovery from malformed data files.
- Improved reporting and administrative features.

## 🎓 Internship Information

- **Organization:** Devixo Solutions
- **Task Number:** Task 02
- **Project:** Library Management System
- **Language:** C++

This project was developed to demonstrate practical C++ programming skills, object-oriented design, data structures, input validation, and file handling in accordance with the internship task requirements.

## 👩‍💻 Author

**Ayesha Raheela**  
BS Computer Science Student

GitHub: [(https://github.com/ayesharaheela1410-zr/Devixo-Solution-Internship___Task-2/edit/main/README.md)](https://github.com/)
