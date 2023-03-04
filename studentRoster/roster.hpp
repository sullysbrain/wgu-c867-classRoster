//
//  roster.hpp
//  studentRoster
//
//  Course Title: Scripting and Programming - Applications - C867
//  Programming Language: c++
//  Name: Scott Sullivan

#ifndef roster_hpp
#define roster_hpp

#include "student.hpp"
#include "degree.h"
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Roster
{
    
    public:
        static const int MAX_STUDENTS = 5;
        int numStudents = 0;
        Student *classRosterArray[MAX_STUDENTS];
        
        Roster();
        ~Roster();
    
        void add(string studID, string fName, string lName, string e_mail, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
    
    private:
        int currentIndex = -1;
        void parseData();

};



#endif /* roster_hpp */
