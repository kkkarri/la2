#include <iostream>
#include <time.h>
#include "Student.h"
#include "Faculty.h"
using namespace std;

// Функція поза межами класу
void calculateGPA(const Student& student) {
    cout << "GPA of " << student.getFirstName() << " " << student.getLastName() << ": " << student.getGPA() << endl;
}

// Перевантажена функція
void calculateGPA(Student* student) {
    cout << "GPA of " << student->getFirstName() << " " << student->getLastName() << ": " << student->getGPA() << endl;
}

// Функція, яка повертає об’єкт класу
Student createStudent(string fn, string ln, int a, string id) {
    return Student(fn, ln, a, id);
}

int main()
{
	srand(time(0));//генератор випадкових чисел
	
	//створення студентів
    Student student1("JASON", "BULL", 29, "S404L");
    Student student2("JANIFER", "ENISTON", 21, "W485U");
    Student student3("JOHNNY", "DEPP", 42, "H675J");

    // Створення факультету
    Faculty faculty("Faculty: Math", 3);

    // Реєстрація студентів на факультет
    faculty.enrollStudent(&student1);
    faculty.enrollStudent(&student2);
    faculty.enrollStudent(&student3);

    // Виведення інформації про факультет
    faculty.displayFacultyInfo();

    // Взаємодія студентів з факультетом
    student1.interactWithFaculty(faculty);
    student2.interactWithFaculty(faculty);
    student3.interactWithFaculty(faculty);

    // Взаємодія студентів між собою
    student1.interactWithStudent(student2);
    student2.interactWithStudent(student3);
    student3.interactWithStudent(student1);

    // Запис даних у файл
    ofstream outFile("students.txt");
    faculty.writeToDisk(outFile);
    outFile.close();

    // Читання даних з файлу
    ifstream inFile("students.txt");
    Faculty readFaculty(" Math", 3);
    readFaculty.readFromDisk(inFile);
    inFile.close();

    // Виведення інформації про факультет після читання з файлу
    readFaculty.displayFacultyInfo();

    // Виклик функції calculateGPA
    calculateGPA(student1);
    calculateGPA(&student2);

    // Створення об’єкта класу за допомогою функції createStudent
    Student student4 = createStudent("JENNY", "HARRIS", 25, "T123L");

    // Виведення інформації про студента
    student4.showInfo();

    return 0;
}