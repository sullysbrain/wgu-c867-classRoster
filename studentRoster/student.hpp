//
//  student.hpp
//  studentRoster
//
//  Course Title: Scripting and Programming - Applications - C867
//  Programming Language: c++
//  Name: Scott Sullivan

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <string>
#include "degree.h"

using std::string;

class Student
{
    public:
        // CONSTRUCTOR - default settings
        Student();
        Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram);
        ~Student();
    
        // GETTER AND SETTERS
        void SetStudentID(string studentID);
        string GetStudentID();
        
        void SetFirstName(string firstName);
        string GetFirstName();

        void SetLastName(string lastName);
        string GetLastName();
        
        void SetEmail(string email);
        string GetEmail();
        
        void SetStudentAge(int age);
        int GetStudentAge();
        
    // ORIGINAL
//        void SetDaysToCompleteCourse(int* daysToCompleteCourse);
//        int* GetDaysToCompleteCourse();
        void SetDaysToCompleteCourse(int* daysToCompleteCourse);
        int *GetDaysToCompleteCourse();

        void SetDegree(DegreeProgram degreeProgram);
        DegreeProgram GetDegree();
    
        string print();
    
    private:
        const int MAX_COURSES = 3;
        
        string studID;
        string fName;
        string lName;
        string e_mail;
        int studentAge;
        int daysToCompleteCourse[3];
        DegreeProgram degree;

};


#endif /* student_hpp */
