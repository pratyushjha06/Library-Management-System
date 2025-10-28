#include "Library.h"
#include <iostream>

void Library::addBook(const Book &book)
{
    books.push_back(book);
}

void Library::addMember(const Member &member)
{
    members.push_back(member);
}

Book *Library::findBook(int id)
{
    for (auto &book : books)
    {
        if (book.getID() == id)
            return &book;
    }
    return nullptr;
}

Member *Library::findMember(int id)
{
    for (auto &member : members)
    {
        if (member.getID() == id)
            return &member;
    }
    return nullptr;
}

void Library::issueBook(int bookId, int memberId)
{
    Book *book = findBook(bookId);
    Member *member = findMember(memberId);

    if (!book)
    {
        std::cout << "Book not found!\n";
        return;
    }
    if (!member)
    {
        std::cout << "Member not found!\n";
        return;
    }
    if (book->getStatus())
    {
        std::cout << "Book already issued!\n";
        return;
    }

    book->issueBook(); 
    member->issueBook();
    std::cout << "Book issued successfully to " << member->getName() << "!\n";
}

void Library::returnBook(int bookId, int memberId)
{
    Book *book = findBook(bookId);
    Member *member = findMember(memberId);

    if (!book || !member)
    {
        std::cout << "Invalid book or member ID!\n";
        return;
    }

    if (!book->getStatus())
    {
        std::cout << "Book was not issued!\n";
        return;
    }

    book->returnBook(); 
    member->returnBook();
    std::cout << "Book returned successfully!\n";
}

void Library::displayBooks() const
{
    std::cout << "\n--- Books in Library ---\n";
    for (const auto &b : books)
        b.display();
}

void Library::displayMembers() const
{
    std::cout << "\n--- Members in Library ---\n";
    for (const auto &m : members)
        m.display();
}
