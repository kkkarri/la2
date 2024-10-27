#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std; 

class Faculty 
{
private:
    string facultyName;
    int credits;
    Student* enrolledStudents[10]; // масив
    int studentCount; // Кількість записаних студентів

public:
    Faculty();//без параметрів
    Faculty(string name, int cr);//з параметрами
    Faculty(const Faculty& others);//копіювальний 

    void enrollStudent(Student* student);
    void displayFacultyInfo() const;

    void writeToDisk(ofstream& outFile) const;
    void readFromDisk(ifstream& inFile);

    string getFacultyName() const { return facultyName; } // Додано для доступу до назви факультету
};
