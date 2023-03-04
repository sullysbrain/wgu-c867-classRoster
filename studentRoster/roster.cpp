//
//  roster.cpp
//  studentRoster
//
//  Course Title: Scripting and Programming - Applications - C867
//  Programming Language: c++
//  Name: Scott Sullivan

#include "roster.hpp"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//Constructor
Roster::Roster(){
    cout << "Parsing data" << endl;
    this->parseData();
}

Roster::~Roster() {
    cout << endl;
    cout << "Roster Destructor executed." << endl;
    cout << endl;
}
void Roster::parseData() {
    
    // Load Initial Array with Data
    string rawStringArray[MAX_STUDENTS];
    string rawString[MAX_STUDENTS] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Scott,Sullivan,ssul210@wgu.edu,47,7,11,13,SOFTWARE"};
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        rawStringArray[i] = rawString[i];
    }
    
    // Parse raw string to lines, then array of attributes for each line
    currentIndex = -1;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        string rawStudentString = rawStringArray[i];
        vector<string> parsedArray;
        stringstream myStream(rawStudentString);
        
        while(myStream.good()) {
            string parsed;
            getline(myStream, parsed, ','); //get element from comma delimiated string
            parsedArray.push_back(parsed);
        }
        
        // Load parsed array data into variables to prepare for Student creation
        string studentid = parsedArray[0];
        string fName = parsedArray[1];
        string lName = parsedArray[2];
        string email = parsedArray[3];
        int age = std::stoi(parsedArray[4]);
        int daysInCourse1 = std::stoi(parsedArray[5]);
        int daysInCourse2 = std::stoi(parsedArray[6]);
        int daysInCourse3 = std::stoi(parsedArray[7]);
        DegreeProgram degree;
        if (parsedArray[8] == "NETWORK" ){
            degree = NETWORK;
        } else if (parsedArray[8] == "SECURITY" ) {
            degree = SECURITY;
        } else {
            degree = SOFTWARE;
        }
        
        // Add student to roster
        this->add(studentid, fName, lName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
    }
    cout << numStudents << " students added." << endl;
    cout << endl;
}

void Roster::add(string studID, string fName, string lName, string e_mail, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
    cout << "ADDING " << fName << " " << lName << endl;
    int daysToCompleteArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    currentIndex ++;
    numStudents ++;
    this->classRosterArray[currentIndex] = new Student(studID, fName, lName, e_mail, studentAge, daysToCompleteArray, degree);
}

void Roster::remove(string studentID) {
    bool didFind = false;
    for (int i = 0; i < numStudents; ++i) {
        // if StudentID is found, remove pointer and replace with following pointers
        // then reset the number of students to one less
        if ( (classRosterArray[i]->GetStudentID() ) == studentID) {
            cout << "Removing Student:\n" << classRosterArray[i]->print() << endl;
            didFind = true;
            for (int j = i; j < numStudents; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            numStudents = numStudents - 1;
            break;
        }
    }
    if (!didFind) {
        cout << "Cannot remove student with ID " << studentID << ". Student not found." << endl;
    }
}

void Roster::printAll() {
//    int numStudents = sizeof(classRosterArray)/sizeof(classRosterArray[0]);
    cout << "Printing All " << numStudents << " students:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << this->classRosterArray[i]->print();
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    int average = 0;
    bool didFind = false;
    for (int i = 0; i < numStudents; ++i) {
        // if StudentID is found, print average days
        if ( (classRosterArray[i]->GetStudentID() ) == studentID) {
            int totalDays = 0;
            for (int j = 0; j < 3; j++){
                int* ptr = this->classRosterArray[i]->GetDaysToCompleteCourse();
                totalDays += ptr[j];
            }
            average = (totalDays / 3);
            cout << "Average days per course for student " << classRosterArray[i]->GetStudentID();
            cout << " is: " << average << " days." << endl;
            didFind = true;
            break;
        }
    }
    if (!didFind) {
        cout << "Student not found." << endl;
    }
}

void Roster::printInvalidEmails() {
//    cout << "Printing Invalid emails:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        // retrieve and test email to see if it is in a valid format
        // IE: includes @ sign and period ('.') --  not include a space (' ').
        string tmpEmail = this->classRosterArray[i]->GetEmail();
        char ampersandChar = '@';
        char spaceChar = ' ';
        char period = '.';
        if ( !( tmpEmail.find(ampersandChar) != string::npos )) {
            cout << "EMAIL NOT VALID: " << this->classRosterArray[i]->GetEmail() << " -- NO @ symbol!" << endl;
        }
        if ( !( tmpEmail.find(period) != string::npos )) {
            cout << "EMAIL NOT VALID: " << this->classRosterArray[i]->GetEmail() << " -- NO Period!" << endl;
        }
        if ( tmpEmail.find(spaceChar) != string::npos ) {
            cout << "EMAIL NOT VALID: " <<  this->classRosterArray[i]->GetEmail() << " -- Contains space!" << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    bool didFind = false;
    if (degreeProgram == SECURITY) {
        cout << "\nStudents taking SECURITY:\n";
    } else if (degreeProgram == NETWORK) {
        cout << "\nStudents taking NETWORK:\n";
    } else {
        cout << "\nStudents taking SOFTWARE:\n";
    }
    for (int i = 0; i < numStudents; ++i) {
        // if StudentID is found, print average days
        DegreeProgram tmpDegree = this->classRosterArray[i]->GetDegree();
        if ( tmpDegree == degreeProgram) {
            cout << this->classRosterArray[i]->print();
            didFind = true;
        }
    }
    if (!didFind) {
        cout << "No students with this degree." << endl;
    }
    cout << endl;
}
