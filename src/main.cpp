#include "Library.h"
#include <iostream>
using namespace std;

int main() {
    Library lib;
    lib.loadData();

    int choice;
    while (true) {
        cout << "\n\033[1;36m========== LIBRARY MANAGEMENT SYSTEM ==========\033[0m\n";
        cout << "\033[1;33m1.\033[0m Add Book\n";
        cout << "\033[1;33m2.\033[0m Add Member\n";
        cout << "\033[1;33m3.\033[0m Issue Book\n";
        cout << "\033[1;33m4.\033[0m Return Book\n";
        cout << "\033[1;33m5.\033[0m Display All Books\n";
        cout << "\033[1;33m6.\033[0m Display All Members\n";
        cout << "\033[1;33m7.\033[0m Generate Library Report\n";
        cout << "\033[1;33m8.\033[0m List All Issued Books\n";
        cout << "\033[1;31m0.\033[0m Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\033[1;31mInvalid input! Please enter a number.\033[0m\n";
            continue;
        }

        if (choice == 0) {
            lib.saveData();
            cout << "\033[1;32mExiting... Data saved successfully. Thank you!\033[0m\n";
            break;
        }

        switch (choice) {
            case 1: {
                int id; string title, author;
                cout << "Enter Book ID: "; cin >> id; cin.ignore();
                cout << "Enter Book Title: "; getline(cin, title);
                cout << "Enter Author Name: "; getline(cin, author);
                lib.addBook(Book(id, title, author));
                break;
            }
            case 2: {
                int id; string name;
                cout << "Enter Member ID: "; cin >> id; cin.ignore();
                cout << "Enter Member Name: "; getline(cin, name);
                lib.addMember(Member(id, name));
                break;
            }
            case 3: {
                int bookId, memberId;
                cout << "Enter Book ID to issue: "; cin >> bookId;
                cout << "Enter Member ID: "; cin >> memberId;
                lib.issueBook(bookId, memberId);
                break;
            }
            case 4: {
                int bookId, memberId;
                cout << "Enter Book ID to return: "; cin >> bookId;
                cout << "Enter Member ID: "; cin >> memberId;
                lib.returnBook(bookId, memberId);
                break;
            }
            case 5: lib.displayBooks(); break;
            case 6: lib.displayMembers(); break;
            case 7: lib.generateReport(); break;
            case 8: lib.listIssuedBooks(); break;

            default:
                cout << "\033[1;31mInvalid choice! Please try again.\033[0m\n";
        }
    }

    return 0;
}
