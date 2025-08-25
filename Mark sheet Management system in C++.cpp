#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store student information
struct Student {
    string name;
    string registrationNumber;
    int semester;
    string subjects[5];
    int marks[5];
};

// Function prototypes
void addNewStudent();  // Add a new student record
void displayIndividualStudent(); // Display an individual student's record
void deleteStudent(); // Delete a student record
void updateStudentRecord(); // Update a student's record
void displayAllStudents(); // Display all students' records
string calculateGrade(double percentage); // Calculate grade based on percentage

int main() {
    int choice;
    do {
    		cout << "---------------------------------------------------------------" << endl;
    		cout << "\t\tHITEC University Taxila" << endl;
    		cout << "\tStudent Marks Sheet Management System" << endl;
    		cout << "----------------------------------------------------------------" << endl;
    		cout << "1. Enter New Student Data" << endl;
    		cout << "2. Display Individual Student Marks Sheet" << endl;
    		cout << "3. Delete Student" << endl;
    		cout << "4. Update Student Record" << endl;
    		cout << "5. Show All Students Records" << endl;
    		cout << "6. Exit" << endl;
    		cout << "-------------------------------------------------------" << endl;

        cout << "Enter the choice: ";
        cin >> choice;
        // Switch case to handle different choices
        switch (choice) {
            case 1:
                addNewStudent(); // Call function to add a new student
                break;
            case 2:
                displayIndividualStudent(); // Call function to display an individual student's record
                break;
            case 3:
                deleteStudent(); // Call function to delete a student's record
                break;
            case 4:
                updateStudentRecord(); // Call function to update a student's record
                break;
            case 5:
                displayAllStudents(); // Call function to display all students' records
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl; // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again." << endl; // Invalid choice
        }
    } while (choice != 6);

    return 0;
}

void addNewStudent() { // Function to add a new student record
    ofstream outFile("students.txt", ios::app | ios::out); // Open a file and append a new student's information

    // Get input for a new student's name, registration number, semester, subjects, and marks
    Student newStudent;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter registration number: ";
    getline(cin, newStudent.registrationNumber);
    cout << "Enter semester number: ";
    cin >> newStudent.semester;

    for (int i = 0; i < 5; i++) {
        cout << "Enter Subject " << i + 1 << " name: ";
        cin.ignore();
        getline(cin, newStudent.subjects[i]);
        cout << "Enter marks for " << newStudent.subjects[i] << ": ";
        cin >> newStudent.marks[i];
    }

    // Write the student's information to the file
    outFile << newStudent.name << " " << newStudent.registrationNumber << " " << newStudent.semester << " ";
    for (int i = 0; i < 5; i++) {
        outFile << newStudent.subjects[i] << " " << newStudent.marks[i] << " ";
    }
    outFile << endl;
    outFile.close(); // Close the file
    cout << "Record Added" << endl; // Display a message indicating the record has been added
}

void displayIndividualStudent() {
    ifstream inFile("students.txt", ios::in); // Open the file to read student records

    if (!inFile) {
        cout << "Unable to open file." << endl;
        return;
    }

    string registrationNumber;
    bool found = false;
    Student currentStudent;
    cin.ignore(); // Clear input buffer before taking input
    cout << "Enter Student Registration Number: "; // Ask for the registration number to search for
    getline(cin, registrationNumber);

    while (inFile >> currentStudent.name >> currentStudent.registrationNumber >> currentStudent.semester) {
        if (currentStudent.registrationNumber == registrationNumber) {
            found = true; // Read the file line by line and look for a matching registration number
            // If found, display the student's information and marks
            cout << "-------------------------------------------------------" << endl;
            cout << "HITEC University Taxila" << endl;
            cout << "Student Marks Sheet" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "Name: " << currentStudent.name << endl;
            cout << "Registration Number: " << currentStudent.registrationNumber << endl;
            cout << "Semester Number: " << currentStudent.semester << endl;
            cout << "-------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Subject Name\tMarks" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------" << endl;
            int totalMarks = 0;
            for (int i = 0; i < 5; ++i) {
                inFile >> currentStudent.subjects[i] >> currentStudent.marks[i];
                cout << setw(18) << left << currentStudent.subjects[i] << currentStudent.marks[i] << endl;
                totalMarks += currentStudent.marks[i];
            }
            // Calculate total marks, percentage, and grade
            double percentage = (static_cast<double>(totalMarks) / 500) * 100;
            cout << "-------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Total Marks: 500" << endl;
            cout << "Obtained Marks: " << totalMarks << endl;
            cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
            cout << "GPA on basis of total marks: " << calculateGrade(percentage) << endl;
            cout << "-------------------------------------------------------------------------------------------------------------" << endl;
            break;
        }
    }
    if (!found) {
        cout << "The desired registration number is not present in the student list." << endl;
    }
    inFile.close(); // Close the file
}

void deleteStudent() { // Function to delete a student record
    ifstream inFile("students.txt"); // Open the file to read student records
    ofstream tempFile("temp.txt"); // Create a temporary file to store records temporarily
    string registrationNumber;
    bool found = false;
    Student currentStudent;
    cout << "Enter Student Registration Number to delete its record: "; // Ask for the registration number to delete the corresponding record
    cin >> registrationNumber;

    while (inFile >> currentStudent.name >> currentStudent.registrationNumber >> currentStudent.semester) {
        if (currentStudent.registrationNumber == registrationNumber) {
            found = true;
            cout << "The student is now deleted from the students list." << endl;
        } else {
            tempFile << currentStudent.name << " " << currentStudent.registrationNumber << " " << currentStudent.semester << " ";
            for (int i = 0; i < 5; ++i) {
                tempFile << currentStudent.subjects[i] << " " << currentStudent.marks[i] << " ";
            }
            tempFile << endl;
        }
    }
    if (!found) {
        cout << "The desired registration number is not present in the student list." << endl;
    }
    inFile.close(); // Close both files
    tempFile.close();
    remove("students.txt"); // Remove the original file and rename the temp file to the original filename
    rename("temp.txt", "students.txt");
}

// Function to update a student's record
void updateStudentRecord() {
    ifstream inFile("students.txt"); // Open the file to read student records
    ofstream tempFile("temp.txt"); // Create a temporary file to store updated records temporarily
    string registrationNumber;
    bool found = false;
    Student currentStudent;
    cout << "Enter Student Registration Number to update its record: ";
    cin >> registrationNumber;

    while (inFile >> currentStudent.name >> currentStudent.registrationNumber >> currentStudent.semester) {
        if (currentStudent.registrationNumber == registrationNumber) {
            found = true;
            cout << "Update data for " << registrationNumber << endl;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, currentStudent.name);
            cout << "Enter semester number: ";
            cin >> currentStudent.semester;

            // Write updated records to the temp file
            tempFile << currentStudent.name << " " << currentStudent.registrationNumber << " " << currentStudent.semester << " ";
            for (int i = 0; i < 5; ++i) {
                cout << "Enter Subject " << i + 1 << " name: ";
                cin.ignore();
                getline(cin, currentStudent.subjects[i]);
                cout << "Enter Subject " << i + 1 << " marks: ";
                cin >> currentStudent.marks[i];
                tempFile << currentStudent.subjects[i] << " " << currentStudent.marks[i] << " ";
            }
            tempFile << endl;
            cout << "The record is now updated." << endl;
        } else {
            tempFile << currentStudent.name << " " << currentStudent.registrationNumber << " " << currentStudent.semester << " ";
            for (int i = 0; i < 5; ++i) {
                tempFile << currentStudent.subjects[i] << " " << currentStudent.marks[i] << " ";
            }
            tempFile << endl;
        }
    }
    if (!found) {
        cout << "The desired registration number is not present in the student list." << endl;
    }
    inFile.close(); // Close both files
    tempFile.close();
    remove("students.txt"); // Remove the original file and rename the temp file to the original filename
    rename("temp.txt", "students.txt");
}

void displayAllStudents() { // Function to display all students' records
    ifstream inFile("students.txt");
    if (!inFile.is_open()) { // Open the file to read student records
        cout << "No records found." << endl;
        return;
    }

    cout << "-------------------------------------------------------------------------------------------------------------" << endl; // Display a header for the table of all student records
    cout << "\t\t\tHITEC University All Students Result" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Registration No. Sub1 | Marks | Sub2 | Marks | Sub3 | Marks | Sub4 | Marks | Sub5 | Marks | %age | Grade" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;

    Student currentStudent;
    while (inFile >> currentStudent.name >> currentStudent.registrationNumber >> currentStudent.semester) {
        int totalMarks = 0;
        for (int i = 0; i < 5; ++i) {
            inFile >> currentStudent.subjects[i] >> currentStudent.marks[i];
            totalMarks += currentStudent.marks[i];
        }
        double percentage = (static_cast<double>(totalMarks) / 500) * 100;
        string grade = calculateGrade(percentage);

        cout << currentStudent.registrationNumber << "       ";
        for (int i = 0; i < 5; ++i) {
            cout << currentStudent.subjects[i] << " | " << currentStudent.marks[i] << "  | ";
        }
        cout << fixed << setprecision(2) << percentage << "% | " << grade << endl;
    }
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    inFile.close(); // Close the file
}

// Function to calculate the grade based on percentage
string calculateGrade(double percentage) {
    if (percentage >= 90) // Calculate the grade based on the provided percentage
        return "A+";
    else if (percentage >= 85)
        return "A";
    else if (percentage >= 80)
        return "B+";
    else if (percentage >= 75)
        return "B";
    else if (percentage >= 70)
        return "B-";
    else if (percentage >= 65)
        return "C+";
    else if (percentage >= 60)
        return "C";
    else if (percentage >= 55)
        return "C-";
    else if (percentage >= 50)
        return "D";
    else
        return "F";
}
