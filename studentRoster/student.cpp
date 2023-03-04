//
//  student.cpp
//  studentRoster
//
//  Course Title: Scripting and Programming - Applications - C867
//  Programming Language: c++
//  Name: Scott Sullivan

#include <iostream>
#include "student.hpp"

using namespace std;

// PRINT Student Information
string Student::print() {
    string descriptionString = "";

    descriptionString += studID + "\t";
    descriptionString += "First Name: " + fName + "\t";
    descriptionString += "Last Name: " + lName + "\t";
    descriptionString += "Age: " + to_string(studentAge) + "\t";
    string daysToCompleteString = "";
    for (int j = 0; j < 3; j++){
        daysToCompleteString += to_string( daysToCompleteCourse[j] );
        if (j < 2) {
            daysToCompleteString += ", ";
        }
    }
    descriptionString += "daysInCourse: " + daysToCompleteString + "\t";
    if (degree == SOFTWARE) {
        descriptionString += "Degree Program: Software\n";
    } else if (degree == NETWORK) {
        descriptionString += "Degree Program: Network\n";
    } else {
        descriptionString += "Degree Program: Security\n";
    }
    return descriptionString;
}


//Constructors
Student::Student() {
    
}
Student::~Student() {
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram) {
    studID = studentID;
    fName = firstName;
    lName = lastName;
    e_mail = email;
    studentAge = age;
    for (int i = 0; i < MAX_COURSES; i++) {
        daysToCompleteCourse[i] = daysToComplete[i];
    }
    degree = degreeProgram;
}

// GETTER AND SETTERS
void Student::SetStudentID(string studentID) {
    studID = studentID;
}
string Student::GetStudentID() {
    return studID;
}
void Student::SetFirstName(string firstName) {
    fName = firstName;
}
string Student::GetFirstName() {
    return fName;
}
void Student::SetLastName(string lastName) {
    lName = lastName;
}
string Student::GetLastName() {
    return lName;
}
void Student::SetEmail(string email) {
    e_mail = email;
}
string Student::GetEmail() {
    return e_mail;
}
void Student::SetStudentAge(int age) {
    studentAge = age;
}
int Student::GetStudentAge() {
    return studentAge;
}
void Student::SetDaysToCompleteCourse(int daysToComplete[]) {
    for (int i = 0; i < MAX_COURSES; i++) {
        daysToCompleteCourse[i] = daysToComplete[i];
    }
}
int* Student::GetDaysToCompleteCourse() {
    static int tmp[3];
    tmp[0] = daysToCompleteCourse[0];
    tmp[1] = daysToCompleteCourse[1];
    tmp[2] = daysToCompleteCourse[2];
    return tmp;
}


void Student::SetDegree(DegreeProgram degreeProgram) {
    if (degreeProgram == SECURITY) {
        degree = SECURITY;
    } else if (degreeProgram == NETWORK) {
        degree = NETWORK;
    } else {
        degree = SOFTWARE;
    }
//    degree = degreeProgram;
}
DegreeProgram Student::GetDegree() {
    return degree;
    
}
