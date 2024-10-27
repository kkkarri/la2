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
    Student* enrolledStudents[10]; // �����
    int studentCount; // ʳ������ ��������� ��������

public:
    Faculty();//��� ���������
    Faculty(string name, int cr);//� �����������
    Faculty(const Faculty& others);//����������� 

    void enrollStudent(Student* student);
    void displayFacultyInfo() const;

    void writeToDisk(ofstream& outFile) const;
    void readFromDisk(ifstream& inFile);

    string getFacultyName() const { return facultyName; } // ������ ��� ������� �� ����� ����������
};
