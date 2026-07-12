# Library Management System (LMS) in C

A console-based Library Management System built in the C programming language. It manages core library operations such as adding books, issuing and returning books, tracking users, and automatically calculating fines for late returns.


📖 Table of Contents


Introduction
Features
Menu Structure

Main Menu
Submenus



Issue & Return System

Issue Book Process
Return Book Process
Fine Calculation Rule



Data Structures

Book Record
Issue Record



Data Storage
Getting Started
Future Improvements
Conclusion



Introduction

The Library Management System (LMS) is a console-based application developed in C. It helps manage library operations like adding books, issuing books, returning books, and tracking users. The system automatically handles important dates such as issue date, due date, and return date, and also calculates fines for late returns.


Features

The Book Management Module allows the librarian to:


*Add new books
*Update book details
*Delete books
*Search books
*View all books
*Issue books to users
*Return books
*View issued books
*Save data to files



Menu Structure

Main Menu

+----------------------------------------+
|         Book Management Menu           |
|----------------------------------------|
| 1. Add New Book                        |
| 2. Update Book Details                 |
| 3. Remove Book                         |
| 4. Search Book                         |
| 5. View All Books                      |
| 6. Issue Book                          |
| 7. Return Book                         |
| 8. List Issued Books                   |
| 9. Save                                |
| 10. Exit                               |
+----------------------------------------+

OptionDescriptionAdd New BookAdd a new book to the systemUpdate Book DetailsEdit existing book informationRemove BookDelete a book recordSearch BookFind books using ID, name, or authorView All BooksDisplay all available booksIssue BookIssue a book and generate issue & due datesReturn BookReturn book and calculate fine if lateList Issued BooksShow all issued booksSaveSave all data to filesExitClose the system

Submenus

Update Book Details


A. By Book ID
B. By Book Name
C. Back to Main Menu


Remove Book


A. By Book ID
B. By Book Name
C. Back to Main Menu


Search Book


A. By Book ID
B. By Book Name
C. By Author Name
D. Back to Main Menu



Issue & Return System

Issue Book Process


Select book and user
Check availability
Record:

Book ID
User ID
User Name
Issue Date (auto-generated)
Due Date (usually 7 days from issue date)



Reduce book quantity
Save issue record


Return Book Process


Find record using Book ID and User ID
Record Return Date automatically
Compare Return Date with Due Date
If late, calculate fine
Update Fine Amount
Increase book quantity
Mark book as returned


Fine Calculation Rule

Example: ₹5 per day late

Fine Amount = Number of Late Days × 5

List Issued Books

Displays the following for each issued book:


Book ID
Book Title
User ID
User Name
Issue Date
Due Date
Return Date
Fine Amount



Data Structures

Book Record

FieldDescriptionBook IDUnique ID of bookTitleBook nameAuthorAuthor nameQuantityAvailable copies

Issue Record

FieldDescriptionIssue IDUnique issue record IDBook IDIssued book IDUser IDBorrower IDUser NameBorrower nameIssue DateDate of issueDue DateLast return dateReturn DateActual return dateFine AmountLate return fine


Data Storage


Books File – Stores all book details
Issued Books File – Stores issue and return history



Getting Started

Prerequisites


A C compiler (e.g., gcc)


Compiling & Running

bashgcc library_management.c -o library_management
./library_management


Replace library_management.c with your actual source file name.




Future Improvements

Ideas to make the project better and more advanced:


Improve Data Structure

Use struct properly for Book and Issue records
Use arrays or linked lists for better storage management



Add Login System

Add Admin Login (username & password)
Restrict access to authorized users only



Improve Date Handling

Automatically calculate due dates using real date functions
Prevent invalid date entries



Better Search Feature

Allow partial search (e.g., typing only part of a book name)
Add case-insensitive search



Fine System Enhancements

Add different fine rules:

₹5/day for normal books
₹10/day for reference books






Reports Feature

Most issued books
Overdue books list
Total fine collected



File Handling Improvement

Use separate files for Books, Users, and Issued records
Ensure data is not lost after program closes



Input Validation

Prevent invalid inputs like negative quantity or wrong IDs
Handle errors properly



User-Friendly Interface

Improve menu design
Add clear success/failure messages






Conclusion

This Library Management System helps manage books efficiently using C programming. With features like issue/return tracking, due dates, and fine calculation, it simulates a real-world library system. Implementing the suggested improvements can make it more powerful and professional.
