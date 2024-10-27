#include "Student.h"
#include "Faculty.h" // ϳ�������� Faculty.h

using namespace std; // ������ using namespace std

// ����������� ����� Student
Student::Student(string fn, string ln, int a, string id)
    : firstName(fn), lastName(ln), age(a), studentID(id), gpa(3.8), expelled(false) {}

// ������������ GPA
void Student::setGPA(double newGPA) {
    gpa = newGPA;
}

// ��������� GPA
double Student::getGPA() const {
    return gpa;
}

// ³���������� ��������
void Student::expel() {
    expelled = true;
    cout << firstName << " " << lastName << " has been expelled due to low grades." << endl;
}

// �������� ��������� ��������
void Student::reEnroll() {
    expelled = false;
    cout << firstName << " " << lastName << " has re-enrolled." << endl;
}

// ��������� ���������� ��� ��������
void Student::showInfo() const {
    cout << "Student: " << firstName << " " << lastName << ", Age: " << age
        << ", ID: " << studentID << ", GPA: " << fixed << setprecision(2) << gpa
        << (expelled ? " (Expelled)" : "") << endl;
}

// ������� � �����������
void Student::interactWithFaculty(const Faculty& faculty) const {
    cout << firstName << " is interacting with the faculty: " << faculty.getFacultyName() << endl;
}

// ������� � ����� ���������
void Student::interactWithStudent(const Student& student) {
    cout << firstName << " is interacting with student: " << student.firstName << " " << student.lastName << endl;
}

// ����� ����� � ����
void Student::writeToDisk(ofstream& outFile) const {
    outFile << firstName << " " << lastName << " " << age << " " << studentID << " " << gpa << " " << expelled << endl;
}

// ������� ����� � �����
void Student::readFromDisk(ifstream& inFile) {
    inFile >> firstName >> lastName >> age >> studentID >> gpa;
    int expelledInt;
    inFile >> expelledInt;
    expelled = (expelledInt != 0);
}