# MarkSheet-CPP: Advanced Student Grade Management System

## Project Overview

Welcome to **MarkSheet-CPP**, a robust and efficient console-based application meticulously crafted in **C++** for comprehensive student academic record management. Developed as a **Programming Fundamentals** project for **HITEC University Taxila**, this system empowers educational institutions to streamline the process of recording, retrieving, updating, and deleting student marks and grades with unparalleled ease and accuracy.

Designed for practicality and reliability, MarkSheet-CPP centralizes critical academic data, minimizes manual overhead, and ensures data integrity through persistent file storage. It's an essential tool for effective academic administration.

---

## Key Features

This system is engineered with a rich set of functionalities to handle all your mark sheet management needs:

-  **Add New Student Records**: Seamlessly input and store complete profiles for new students, including their name, registration number, semester, and marks for up to five subjects.

-  **Display Individual Student Marks Sheet**: Instantly retrieve and present a detailed, formatted mark sheet for any student using their unique registration number, complete with subject-wise marks, total obtained marks, percentage, and calculated grade.

-  **Update Student Records**: Easily modify existing student information, such as name, semester, and subject marks, ensuring records are always current and accurate.

-  **Delete Student Records**: Securely remove outdated or incorrect student entries from the database with a simple registration number lookup.

-  **View All Students' Records**: Generate a consolidated, table-formatted overview of all registered students, displaying their registration numbers, subject marks, calculated percentages, and final grades.

-  **Automatic Grade Calculation**: The system automatically computes grades (**A+** to **F**) based on predefined percentage criteria, ensuring consistent and fair evaluation.

-  **Percentage Calculation**: Accurately calculates the overall percentage for each student based on their total marks obtained out of a maximum of 500.

-  **File-Based Data Management**: All student data is persistently stored in `students.txt`, guaranteeing that records are saved across program executions and are readily available.

-  **Navigable Menu System**: A user-friendly, menu-driven interface provides intuitive navigation through all system functionalities.

-  **Robust Error Handling**: Includes basic error handling for scenarios like non-existent registration numbers or file access issues, providing a stable user experience.

---

##  Technologies Used

- **C++**: The core programming language powering the application logic.
- **File I/O (`fstream`)**: Utilized for persistent storage and retrieval of student data from `students.txt`.
- **`iostream`**: For standard input/output operations.
- **`string`**: For efficient handling of text data like names and subjects.
- **`iomanip`**: For precise formatting of output, such as percentages.
