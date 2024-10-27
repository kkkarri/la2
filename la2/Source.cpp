#include <iostream>
#include <time.h>
#include "Student.h"
#include "Faculty.h"
using namespace std;

// ������� ���� ������ �����
void calculateGPA(const Student& student) {
    cout << "GPA of " << student.getFirstName() << " " << student.getLastName() << ": " << student.getGPA() << endl;
}

// ������������� �������
void calculateGPA(Student* student) {
    cout << "GPA of " << student->getFirstName() << " " << student->getLastName() << ": " << student->getGPA() << endl;
}

// �������, ��� ������� �ᒺ�� �����
Student createStudent(string fn, string ln, int a, string id) {
    return Student(fn, ln, a, id);
}

int main()
{
	srand(time(0));//��������� ���������� �����
	
	//��������� ��������
    Student student1("JASON", "BULL", 29, "S404L");
    Student student2("JANIFER", "ENISTON", 21, "W485U");
    Student student3("JOHNNY", "DEPP", 42, "H675J");

    // ��������� ����������
    Faculty faculty("Faculty: Math", 3);

    // ��������� �������� �� ���������
    faculty.enrollStudent(&student1);
    faculty.enrollStudent(&student2);
    faculty.enrollStudent(&student3);

    // ��������� ���������� ��� ���������
    faculty.displayFacultyInfo();

    // ������� �������� � �����������
    student1.interactWithFaculty(faculty);
    student2.interactWithFaculty(faculty);
    student3.interactWithFaculty(faculty);

    // ������� �������� �� �����
    student1.interactWithStudent(student2);
    student2.interactWithStudent(student3);
    student3.interactWithStudent(student1);

    // ����� ����� � ����
    ofstream outFile("students.txt");
    faculty.writeToDisk(outFile);
    outFile.close();

    // ������� ����� � �����
    ifstream inFile("students.txt");
    Faculty readFaculty(" Math", 3);
    readFaculty.readFromDisk(inFile);
    inFile.close();

    // ��������� ���������� ��� ��������� ���� ������� � �����
    readFaculty.displayFacultyInfo();

    // ������ ������� calculateGPA
    calculateGPA(student1);
    calculateGPA(&student2);

    // ��������� �ᒺ��� ����� �� ��������� ������� createStudent
    Student student4 = createStudent("JENNY", "HARRIS", 25, "T123L");

    // ��������� ���������� ��� ��������
    student4.showInfo();

    return 0;
}