#include "Book.h"

// Default constructor
Book::Book() : bookID(0), title(""), author(""), isIssued(false) {}

// Parameterized constructor
Book::Book(int id, const std::string &t, const std::string &a)
    : bookID(id), title(t), author(a), isIssued(false) {}

// Getters
int Book::getID() const { return bookID; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
bool Book::getStatus() const { return isIssued; }

// Setters / Actions
void Book::setID(int id) { bookID = id; }
void Book::setTitle(const std::string &t) { title = t; }
void Book::setAuthor(const std::string &a) { author = a; }

void Book::issueBook() {
    isIssued = true;
}

void Book::returnBook() {
    isIssued = false;
}

// Utility
void Book::display() const {
    std::cout << "Book ID: " << bookID << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Status: " << (isIssued ? "Issued" : "Available") << "\n";
}
