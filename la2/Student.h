#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std; // Додаємо using namespace std

class Faculty; // Попереднє оголошення класу Faculty

class Student {

    string firstName;
    string lastName;
    int age;
    string studentID;
    double gpa;
    bool expelled;
    static int totalStud;//підрахунок студентів

public:
    Student();//без парамертрів
    Student(string fn, string ln, int a, string id);//з параметрами
    Student(const Student& others);//копіювальний
    ~Student();
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    void setGPA(double newGPA);
    double getGPA() const;
    void expel();
    void reEnroll();
    void showInfo() const;

    void interactWithFaculty(const Faculty& faculty) const;
    void interactWithStudent(const Student& student);

    void writeToDisk(ofstream& outFile) const;
    void readFromDisk(ifstream& inFile);

    static int getTotalStudent() { return totalStud; }
};
#endif // STUDENT_H
