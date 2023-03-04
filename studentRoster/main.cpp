//
//  main.cpp
//  studentRoster
//
//  Course Title: Scripting and Programming - Applications - C867
//  Programming Language: c++
//  Name: Scott Sullivan


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "student.hpp"
#include "roster.hpp"
#include "degree.h"
using namespace std;

void printMyInfo() {
    cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: c++" << endl;
    cout << "WGU ID: 010547531   Name: Scott Sullivan" << endl;
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    printMyInfo();
    
    // Add each student to classRoster (constructor parses and adds each student.
    Roster classRoster;
    classRoster.printAll();
    classRoster.printInvalidEmails();
    
    //loop through classRosterArray and for each element:
    for (int i = 0; i < classRoster.numStudents; i++) {
        string studentID = classRoster.classRosterArray[i]->GetStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    };
    
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
