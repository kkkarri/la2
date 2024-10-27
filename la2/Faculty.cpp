#include "Faculty.h"
#include "Student.h"
using namespace std; 

// Конструктор класу Faculty
Faculty::Faculty(string name, int cr)
    : facultyName(name), credits(cr), studentCount(0) {}

// Реєстрація студента на факультет
void Faculty::enrollStudent(Student* student) {
    if (studentCount < 10) {
        enrolledStudents[studentCount++] = student;
        cout << student->getFirstName() << " " << student->getLastName() << " has enrolled in " << facultyName << endl;
    }
    else {
        cout << "Faculty is full. Cannot enroll " << student->getFirstName() << " " << student->getLastName() << endl;
    }
}

// Виведення інформації про факультет
void Faculty::displayFacultyInfo() const {
    cout << "Faculty: " << facultyName << ", Credits: " << credits << endl;
    for (int i = 0; i < studentCount; i++) {
        enrolledStudents[i]->showInfo();
    }
}

// Запис даних у файл
void Faculty::writeToDisk(ofstream& outFile) const {
    outFile << facultyName << " " << credits << " " << studentCount << endl;
    for (int i = 0; i < studentCount; i++) {
        enrolledStudents[i]->writeToDisk(outFile);
    }
}

// Читання даних з файлу
void Faculty::readFromDisk(ifstream& inFile) {
    inFile >> facultyName >> credits >> studentCount;
    for (int i = 0; i < studentCount; i++) {
        enrolledStudents[i] = new Student("", "", 0, "");
        enrolledStudents[i]->readFromDisk(inFile);
    }
}