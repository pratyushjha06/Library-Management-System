# 📚 Library Management System (C++ Project)

A console-based Library Management System built using **Object-Oriented Programming (OOP) in C++**.  

The system allows efficient management of books, members, book issuing, returning, and report generation — all through a simple text-based interface.

---

## 🚀 Features

✅ Add new Books and Members  
✅ Issue and Return Books  
✅ Display all Books and Members  
✅ Prevent duplicate Book or Member IDs  
✅ Generate summarized Library Reports  
✅ List all currently issued Books  
✅ Save and Load data automatically from text files (`data/` folder)  
✅ Error Handling and Input Validation  
✅ Improved console formatting and colorized output for better user experience

---

## 🏗️ Project Structure

Library-Management-System/
│
├── include/
│ ├── Book.h
│ ├── Member.h
│ ├── Person.h
│ └── Library.h
│
├── src/
│ ├── Book.cpp
│ ├── Member.cpp
│ ├── Person.cpp
│ ├── Library.cpp
│ └── main.cpp
│
├── data/
│ ├── books.txt
│ └── members.txt
│
├── bin/
│ ├── library_system.exe
│ ├── test_boox.exe
│ ├── test_library.exe
│ └── test_member.exe
│
└── README.md

---

## ⚙️ How to Compile and Run

### 🧩 Prerequisites

Make sure you have:

- **g++ compiler** (MinGW or GCC)

- **Command Prompt / Terminal** access

- **VS Code** or any text editor

### 🛠️ Compile Command

In your project root directory, run:

```bash
g++ -Iinclude src/main.cpp src/Book.cpp src/Member.cpp src/Person.cpp src/Library.cpp -o bin/library_system
```


This will create an executable file in the `bin` folder.



---

### ▶️ Run the Program

After successful compilation, run:

```bash
bin\library_system.exe
```



You will see a menu like this:

```markdown
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Add Member
3. Issue Book
4. Return Book
5. Display All Books
6. Display All Members
7. Generate Library Report
8. List All Issued Books
0. Exit
Enter your choice:

```



---

## 💾 Data Storage

All books and members are stored persistently in:

```bash
data/books.txt
data/members.txt

```

Data is automatically loaded when the program starts and saved when it exits.



---

## 📊 Example Report Output

```markdown
------ Library Report ------
Total Books: 10
Issued Books: 4
Available Books: 6
Total Members: 5
Top Member (Most Books Issued): Riya Sharma (3 books)
-----------------------------

```



---

## 🧠 Concepts Used

- Classes and Objects

- Encapsulation

- Inheritance

- Polymorphism

- File Handling (I/O)

- STL Vectors

- Exception & Error Handling

- Basic UI Enhancement (ANSI Color Codes)



---

### 🛡 Error Handling & Validation

✅ Prevents adding duplicate IDs for books or members  
✅ Handles empty file or list conditions gracefully  
✅ Validates invalid book/member IDs during issue and return  
✅ Displays clear and colorful error or success messages



---

### 🎨 Color Output Support

Color-coded console output improves readability:

- 🟢 **Success Messages** — Green

- 🔴 **Error Messages** — Red

- 🟡 **Menu Options** — Yellow

- ⚪ **Normal Text** — White

> ⚠️ Windows CMD might not support ANSI colors by default.  
> You can enable it using:
> 
> `reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1`
> 
> Or use **Windows Terminal** / **VS Code Terminal**, which supports colors natively.



---

## 🧩 Future Improvements

- Add a search feature for books and members

- Add date tracking for issue/return operations

- Add a fine system for late returns

- Implement password-protected admin login

- Introduce a graphical UI (using Qt or web interface)



---

## 👨‍💻 Author

**Pratyush Jha**  
*B.Tech Student | CSE 2nd Year*  
📅 *Project Year:* 2025  
📍 *Institution:* Delhi Technical Campus, IP University

> **© 2025 Pratyush Jha — All Rights Reserved**  
> This project is created for educational purposes only.  


