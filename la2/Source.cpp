#include <iostream>
#include <time.h>
#include "Student.h"
#include "Faculty.h"
using namespace std;
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

    return 0;
}