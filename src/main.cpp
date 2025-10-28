#include "Library.h"
#include <iostream>
using namespace std;

int main()
{
    Library lib;
    int choice;

    while (true)
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Display All Members\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting... Thank you!\n";
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            lib.addBook(Book(id, title, author));
            cout << "Book added successfully!\n";
            break;
        }

        case 2:
        {
            int id;
            string name;
            cout << "Enter Member ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Member Name: ";
            getline(cin, name);
            lib.addMember(Member(id, name));
            cout << "Member added successfully!\n";
            break;
        }

        case 3:
        {
            int bookId, memberId;
            cout << "Enter Book ID to issue: ";
            cin >> bookId;
            cout << "Enter Member ID: ";
            cin >> memberId;
            lib.issueBook(bookId, memberId);
            break;
        }

        case 4:
        {
            int bookId, memberId;
            cout << "Enter Book ID to return: ";
            cin >> bookId;
            cout << "Enter Member ID: ";
            cin >> memberId;
            lib.returnBook(bookId, memberId);
            break;
        }

        case 5:
            lib.displayBooks();
            break;

        case 6:
            lib.displayMembers();
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
