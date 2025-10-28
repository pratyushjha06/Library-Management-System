#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;

public:
    // Basic operations
    void addBook(const Book &book);
    void addMember(const Member &member);

    // Search
    Book* findBook(int id);
    Member* findMember(int id);

    // Book issue/return
    void issueBook(int bookId, int memberId);
    void returnBook(int bookId, int memberId);

    // Display all
    void displayBooks() const;
    void displayMembers() const;
};

#endif // LIBRARY_H
