# Library Book Management System – ICT0008 Assessment 2

## Overview
This project was developed as part of ICT0008 – Advanced Programming Skills. The objective is to create a simple C++ application for a community library to manage books.

The system allows users to view books, sort them by ISBN, and borrow books based on availability.

---

## Features
- Book class with attributes:
  - Title
  - Author
  - ISBN
  - Availability
  - Date Added

- Book operations:
  - Set book details
  - Display book information
  - Borrow book
  - Return book

- LibrarySystem class:
  - Stores and manages an array of books
  - Displays all books
  - Searches books by ISBN
  - Sorts books using Bubble Sort
  - Processes borrowing requests

- Main application:
  - Displays book list
  - Accepts user input (ISBN)
  - Handles borrowing logic
  - Terminates when "0" is entered

---

## Object-Oriented Design
The system follows object-oriented principles:

- **Book class**: Represents individual books
- **LibrarySystem class**: Manages the collection of books and system operations
- **MainApplication (main function)**: Controls program flow and user interaction

---

## Sorting Algorithm
The system uses **Bubble Sort** to sort books by ISBN.

### Reason for Selection:
Bubble Sort was chosen because:
- It is simple to implement
- It is suitable for small datasets (only 5 books)
- It is easy to understand for demonstration purposes

Other algorithms considered:
- Insertion Sort
- Quick Sort

Quick Sort is recommended for future scalability due to its higher performance.

---

## Application Workflow
1. Initialise 5 books
2. Sort books by ISBN
3. Display all books
4. Prompt user to enter ISBN
5. Borrow book if available
6. Show error if:
   - Book is already borrowed
   - ISBN is not found
7. Exit program when user enters "0"

---

## Repository Contents
- C++ source code (Book and LibrarySystem implementation)
- Visual Studio solution files
- Version control history (GitHub commits)

---

## Version Control
GitHub was used to manage the project. The repository includes commit history showing the development process, updates, and improvements.

---

## Conclusion
The application meets the requirements of the assessment. It demonstrates the use of object-oriented programming, basic sorting algorithms, and user interaction through a simple and functional system.

Future improvements may include:
- Input validation
- Dynamic data structures
- More efficient sorting algorithms
