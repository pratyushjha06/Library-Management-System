#include "Library.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// ---------------- Basic Operations ----------------

void Library::addBook(const Book &book) {
    books.push_back(book);
}

void Library::addMember(const Member &member) {
    members.push_back(member);
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
        std::cout << "Book not found!\n";
        return;
    }
    if (!member) {
        std::cout << "Member not found!\n";
        return;
    }
    if (book->getStatus()) {
        std::cout << "Book already issued!\n";
        return;
    }

    book->issueBook();
    member->issueBook();
    std::cout << "Book issued successfully to " << member->getName() << "!\n";
}

void Library::returnBook(int bookId, int memberId) {
    Book* book = findBook(bookId);
    Member* member = findMember(memberId);

    if (!book || !member) {
        std::cout << "Invalid book or member ID!\n";
        return;
    }

    book->returnBook();
    member->returnBook();
    std::cout << "Book returned successfully by " << member->getName() << "!\n";
}

// ---------------- Display ----------------

void Library::displayBooks() const {
    std::cout << "\n------ Book List ------\n";
    for (const auto &book : books)
        book.display();
}

void Library::displayMembers() const {
    std::cout << "\n------ Member List ------\n";
    for (const auto &member : members)
        member.display();
}

// ---------------- Save & Load Data (Phase 6) ----------------

void Library::saveData() {
    // Save Books
    std::ofstream bookFile("data/books.txt");
    if (bookFile.is_open()) {
        for (const auto &book : books) {
            bookFile << book.getID() << ","
                     << book.getTitle() << ","
                     << book.getAuthor() << ","
                     << book.getStatus() << "\n";
        }
        bookFile.close();
    } else {
        std::cout << "Error: Could not open data/books.txt for writing!\n";
    }

    // Save Members
    std::ofstream memberFile("data/members.txt");
    if (memberFile.is_open()) {
        for (const auto &member : members) {
            memberFile << member.getID() << ","
                       << member.getName() << ","
                       << member.getBooksIssued() << "\n";
        }
        memberFile.close();
    } else {
        std::cout << "Error: Could not open data/members.txt for writing!\n";
    }
}

void Library::loadData() {
    // Load Books
    std::ifstream bookFile("data/books.txt");
    if (bookFile.is_open()) {
        books.clear();
        int id; std::string title, author; bool status;
        while (bookFile >> id) {
            bookFile.ignore(1, ',');
            std::getline(bookFile, title, ',');
            std::getline(bookFile, author, ',');
            bookFile >> status;
            books.emplace_back(id, title, author);
            if (status) books.back().issueBook();
        }
        bookFile.close();
    }

    // Load Members
    std::ifstream memberFile("data/members.txt");
    if (memberFile.is_open()) {
        members.clear();
        int id, issued; std::string name;
        while (memberFile >> id) {
            memberFile.ignore(1, ',');
            std::getline(memberFile, name, ',');
            memberFile >> issued;
            members.emplace_back(id, name);
            for (int i = 0; i < issued; ++i)
                members.back().issueBook();
        }
        memberFile.close();
    }
}
