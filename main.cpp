#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int bookId, string bookTitle, string bookAuthor,
         bool isIssued = false) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        issued = isIssued;
    }
};

class Library {
private:
    vector<Book> books;
    const string filename = "book_data.txt";

    int findBookIndex(int id) {
        for (int i = 0; i < (int)books.size(); i++) {
            if (books[i].id == id)
                return i;
        }
        return -1;
    }

    string readText(string prompt) {
        string value;
        while (true) {
            cout << prompt;
            getline(cin, value);

            if (value.find_first_not_of(" \t\r\n")
                != string::npos)
                return value;

            cout << "Input cannot be empty. Try again.\n";
        }
    }

    int readInteger(string prompt) {
        string line;
        int value;
        char extra;

        while (true) {
            cout << prompt;
            getline(cin, line);
            stringstream input(line);

            if ((input >> value) && !(input >> extra))
                return value;

            cout << "Invalid input. Enter a whole number.\n";
        }
    }

    string lowerCase(string text) {
        transform(text.begin(), text.end(), text.begin(),
            [](unsigned char c) {
                return static_cast<char>(tolower(c));
            });
        return text;
    }

    void displayBook(const Book& book) {
        cout << "\nBook ID: " << book.id
             << "\nTitle: " << book.title
             << "\nAuthor: " << book.author
             << "\nStatus: "
             << (book.issued ? "Issued" : "Available")
             << "\n-----------------------------\n";
    }

public:
    Library() {
        loadData();
    }

    void saveData() {
        ofstream file(filename);

        if (!file) {
            cout << "Error: Could not save book data.\n";
            return;
        }

        for (const Book& book : books) {
            file << book.id << '|'
                 << book.title << '|'
                 << book.author << '|'
                 << book.issued << '\n';
        }

        file.close();
    }

    void loadData() {
        ifstream file(filename);
        if (!file)
            return;

        string line;

        while (getline(file, line)) {
            stringstream record(line);
            string idText, title, author, issuedText;
            int id;
            int issued;

            if (!getline(record, idText, '|') ||
                !getline(record, title, '|') ||
                !getline(record, author, '|') ||
                !getline(record, issuedText))
                continue;

            stringstream idInput(idText);
            stringstream issuedInput(issuedText);

            if (!(idInput >> id) ||
                !(issuedInput >> issued) ||
                (issued != 0 && issued != 1) ||
                id <= 0 ||
                title.find('|') != string::npos ||
                author.find('|') != string::npos)
                continue;

            if (findBookIndex(id) == -1)
                books.emplace_back(id, title, author,
                                   issued == 1);
        }

        file.close();
    }

    void addBook() {
        int id = readInteger("Enter Book ID: ");

        if (id <= 0) {
            cout << "Book ID must be positive.\n";
            return;
        }

        if (findBookIndex(id) != -1) {
            cout << "This Book ID already exists.\n";
            return;
        }

        string title = readText("Enter Book Title: ");
        string author = readText("Enter Author Name: ");

        if (title.find('|') != string::npos ||
            author.find('|') != string::npos) {
            cout << "The character | is not allowed.\n";
            return;
        }

        books.emplace_back(id, title, author);
        saveData();
        cout << "Book added successfully!\n";
    }

    void viewBooks() {
        if (books.empty()) {
            cout << "No books are currently recorded.\n";
            return;
        }

        for (const Book& book : books)
            displayBook(book);
    }

    void searchBook() {
        cout << "\n1. Search by Title\n";
        cout << "2. Search by Author\n";

        int choice = readInteger("Choose search method: ");

        if (choice != 1 && choice != 2) {
            cout << "Invalid search choice.\n";
            return;
        }

        string query = lowerCase(
            readText(choice == 1
                ? "Enter title or title keyword: "
                : "Enter author name or keyword: "));

        bool found = false;

        for (const Book& book : books) {
            string field = lowerCase(
                choice == 1 ? book.title : book.author);

            if (field.find(query) != string::npos) {
                displayBook(book);
                found = true;
            }
        }

        if (!found)
            cout << "No matching book found.\n";
    }

    void updateBook() {
        int id = readInteger("Enter Book ID to update: ");
        int index = findBookIndex(id);

        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }

        string title = readText("Enter new title: ");
        string author = readText("Enter new author: ");

        if (title.find('|') != string::npos ||
            author.find('|') != string::npos) {
            cout << "The character | is not allowed.\n";
            return;
        }

        books[index].title = title;
        books[index].author = author;

        saveData();
        cout << "Book information updated successfully!\n";
    }

    void deleteBook() {
        int id = readInteger("Enter Book ID to delete: ");
        int index = findBookIndex(id);

        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }

        if (books[index].issued) {
            cout << "Return this book before deleting it.\n";
            return;
        }

        books.erase(books.begin() + index);
        saveData();
        cout << "Book deleted successfully!\n";
    }

    void issueBook() {
        int id = readInteger("Enter Book ID to issue: ");
        int index = findBookIndex(id);

        if (index == -1) {
            cout << "Book not found.\n";
        } else if (books[index].issued) {
            cout << "This book is already issued.\n";
        } else {
            books[index].issued = true;
            saveData();
            cout << "Book issued successfully!\n";
        }
    }

    void returnBook() {
        int id = readInteger("Enter Book ID to return: ");
        int index = findBookIndex(id);

        if (index == -1) {
            cout << "Book not found.\n";
        } else if (!books[index].issued) {
            cout << "This book was not issued.\n";
        } else {
            books[index].issued = false;
            saveData();
            cout << "Book returned successfully!\n";
        }
    }

    void run() {
        int choice;

        do {
            cout << "\n================================\n";
            cout << "   LIBRARY MANAGEMENT SYSTEM\n";
            cout << "================================\n";
            cout << "1. Add Book\n";
            cout << "2. View Books\n";
            cout << "3. Search Book\n";
            cout << "4. Update Book Information\n";
            cout << "5. Delete Book\n";
            cout << "6. Issue Book\n";
            cout << "7. Return Book\n";
            cout << "8. Save Data\n";
            cout << "9. Load Data\n";
            cout << "0. Exit\n";
            cout << "================================\n";

            choice = readInteger("Enter your choice: ");

            switch (choice) {
                case 1: addBook(); break;
                case 2: viewBooks(); break;
                case 3: searchBook(); break;
                case 4: updateBook(); break;
                case 5: deleteBook(); break;
                case 6: issueBook(); break;
                case 7: returnBook(); break;
                case 8:
                    saveData();
                    cout << "Save operation completed.\n";
                    break;
                case 9:
                    loadData();
                    cout << "Load operation completed.\n";
                    break;
                case 0:
                    saveData();
                    cout << "Data saved. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Select 0-9.\n";
            }

        } while (choice != 0);
    }
};

int main() {
    Library library;
    library.run();
    return 0;
}