#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std; // ������ using namespace std

class Faculty; // �������� ���������� ����� Faculty

class Student {

    string firstName;
    string lastName;
    int age;
    string studentID;
    double gpa;
    bool expelled;
    static int totalStud;//��������� ��������

public:
    Student();//��� ����������
    Student(string fn, string ln, int a, string id);//� �����������
    Student(const Student& others);//�����������
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
