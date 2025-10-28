#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"

class Member : public Person {
private:
    int booksIssued;

public:
    Member();
    Member(int id, const std::string &name);

    void issueBook();
    void returnBook();

    int getBooksIssued() const;
    void display() const override; // Polymorphism
};

#endif // MEMBER_H
