#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    int bookID;
    std::string title;
    std::string author;
    bool isIssued;

public:
    // Constructors
    Book();
    Book(int id, const std::string &t, const std::string &a);

    // Getters
    int getID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getStatus() const;

    // Setters / Actions
    void setID(int id);
    void setTitle(const std::string &t);
    void setAuthor(const std::string &a);
    void issueBook();
    void returnBook();

    // Utility
    void display() const;
};

#endif // BOOK_H
