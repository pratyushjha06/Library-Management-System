#include "Member.h"
#include <iostream>

Member::Member() : Person(), booksIssued(0) {}

Member::Member(int id, const std::string &name)
    : Person(id, name), booksIssued(0) {}

void Member::issueBook() {
    booksIssued++;
}

void Member::returnBook() {
    if (booksIssued > 0)
        booksIssued--;
}

int Member::getBooksIssued() const {
    return booksIssued;
}

void Member::display() const {
    std::cout << "Member Details:\n";
    Person::display(); // call base class display
    std::cout << "Books Issued: " << booksIssued << "\n";
}
