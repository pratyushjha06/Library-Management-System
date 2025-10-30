#include "Library.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// ---------------- Basic Operations ----------------

void Library::addBook(const Book &book) {
    for (const auto &b : books) {
        if (b.getID() == book.getID()) {
            cout << "\033[1;31mError:\033[0m Book ID already exists!\n";
            return;
        }
    }
    books.push_back(book);
    cout << "\033[1;32mBook added successfully!\033[0m\n";
}

void Library::addMember(const Member &member) {
    for (const auto &m : members) {
        if (m.getID() == member.getID()) {
            cout << "\033[1;31mError:\033[0m Member ID already exists!\n";
            return;
        }
    }
    members.push_back(member);
    cout << "\033[1;32mMember added successfully!\033[0m\n";
}

// ---------------- Search ----------------

Book* Library::findBook(int id) {
    for (auto &book : books) {
        if (book.getID() == id)
            return &book;
    }
    return nullptr;
}

Member* Library::findMember(int id) {
    for (auto &member : members) {
        if (member.getID() == id)
            return &member;
    }
    return nullptr;
}

// ---------------- Book Issue / Return ----------------

void Library::issueBook(int bookId, int memberId) {
    Book* book = findBook(bookId);
    Member* member = findMember(memberId);

    if (!book) {
        cout << "\033[1;31mBook not found!\033[0m\n";
        return;
    }
    if (!member) {
        cout << "\033[1;31mMember not found!\033[0m\n";
        return;
    }
    if (book->getStatus()) {
        cout << "\033[1;33mBook already issued!\033[0m\n";
        return;
    }

    book->issueBook();
    member->issueBook();
    cout << "\033[1;32mBook issued successfully to " << member->getName() << "!\033[0m\n";
}

void Library::returnBook(int bookId, int memberId) {
    Book* book = findBook(bookId);
    Member* member = findMember(memberId);

    if (!book || !member) {
        cout << "\033[1;31mInvalid book or member ID!\033[0m\n";
        return;
    }

    book->returnBook();
    member->returnBook();
    cout << "\033[1;32mBook returned successfully by " << member->getName() << "!\033[0m\n";
}

// ---------------- Display ----------------

void Library::displayBooks() const {
    if (books.empty()) {
        cout << "\033[1;33mNo books available in the library.\033[0m\n";
        return;
    }

    cout << "\n\033[1;36m------ Book List ------\033[0m\n";
    for (const auto &book : books)
        book.display();
}

void Library::displayMembers() const {
    if (members.empty()) {
        cout << "\033[1;33mNo members registered in the library.\033[0m\n";
        return;
    }

    cout << "\n\033[1;36m------ Member List ------\033[0m\n";
    for (const auto &member : members)
        member.display();
}

// ---------------- Save & Load Data ----------------

void Library::saveData() {
    ofstream bookFile("data/books.txt");
    if (bookFile.is_open()) {
        for (const auto &book : books) {
            bookFile << book.getID() << "," << book.getTitle() << ","
                     << book.getAuthor() << "," << book.getStatus() << "\n";
        }
        bookFile.close();
    } else {
        cout << "\033[1;31mError: Unable to save books!\033[0m\n";
    }

    ofstream memberFile("data/members.txt");
    if (memberFile.is_open()) {
        for (const auto &member : members) {
            memberFile << member.getID() << "," << member.getName() << ","
                       << member.getBooksIssued() << "\n";
        }
        memberFile.close();
    } else {
        cout << "\033[1;31mError: Unable to save members!\033[0m\n";
    }
}

void Library::loadData() {
    ifstream bookFile("data/books.txt");
    if (bookFile.is_open()) {
        books.clear();
        int id; string title, author; bool status;
        while (bookFile >> id) {
            bookFile.ignore(1, ',');
            getline(bookFile, title, ',');
            getline(bookFile, author, ',');
            bookFile >> status;
            books.emplace_back(id, title, author);
            if (status) books.back().issueBook();
        }
        bookFile.close();
    }

    ifstream memberFile("data/members.txt");
    if (memberFile.is_open()) {
        members.clear();
        int id, issued; string name;
        while (memberFile >> id) {
            memberFile.ignore(1, ',');
            getline(memberFile, name, ',');
            memberFile >> issued;
            members.emplace_back(id, name);
            for (int i = 0; i < issued; ++i)
                members.back().issueBook();
        }
        memberFile.close();
    }
}

// ---------------- Reports ----------------

void Library::generateReport() const {
    int totalBooks = books.size();
    int issuedBooks = 0, availableBooks = 0;

    for (const auto &book : books) {
        if (book.getStatus()) issuedBooks++;
        else availableBooks++;
    }

    int totalMembers = members.size();
    const Member* topMember = nullptr;
    int maxIssued = -1;

    for (const auto &m : members) {
        if (m.getBooksIssued() > maxIssued) {
            maxIssued = m.getBooksIssued();
            topMember = &m;
        }
    }

    cout << "\n\033[1;36m------ Library Report ------\033[0m\n";
    cout << "Total Books: " << totalBooks << "\n";
    cout << "Issued Books: " << issuedBooks << "\n";
    cout << "Available Books: " << availableBooks << "\n";
    cout << "Total Members: " << totalMembers << "\n";

    if (topMember)
        cout << "Top Member: " << topMember->getName()
             << " (" << topMember->getBooksIssued() << " books)\n";
    else
        cout << "No members found.\n";

    cout << "\033[1;36m-----------------------------\033[0m\n";
}

void Library::listIssuedBooks() const {
    cout << "\n\033[1;36m----- Issued Books -----\033[0m\n";
    bool anyIssued = false;
    for (const auto &book : books) {
        if (book.getStatus()) {
            book.display();
            anyIssued = true;
        }
    }
    if (!anyIssued)
        cout << "\033[1;33mNo books are currently issued.\033[0m\n";
    cout << "\033[1;36m-----------------------------\033[0m\n";
}
