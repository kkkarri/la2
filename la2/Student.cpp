#include "Student.h"
#include "Faculty.h" 
using namespace std; 

//ініціалізація статистичного поля
int Student::totalStud = 0;

// Конструктор класу Student(без параметрів)
Student::Student() : firstName(""), lastName(""), age(0), studentID(""), gpa(0.0), expelled(false)
{
    totalStud++;
}

// Конструктор класу Student(з параметрами)
Student::Student(string fn, string ln, int a, string id) : firstName(fn), lastName(ln), age(a), studentID(id), gpa(3.8), expelled(false)
{
    totalStud++;
}

// Конструктор класу Student(копіювальний)
Student::Student(const Student& other) : firstName(other.firstName), lastName(other.lastName), age(other.age), studentID(other.studentID), gpa(other.gpa), expelled(other.expelled)
{
    totalStud++;
}

// Деструктор
Student::~Student() {
    totalStud--;
}

// Встановлення GPA
void Student::setGPA(double newGPA) {
    gpa = newGPA;
}

// Отримання GPA
double Student::getGPA() const {
    return gpa;
}

// Відрахування студента
void Student::expel() {
    expelled = true;
    cout << firstName << " " << lastName << " has been expelled due to low grades." << endl;
}

// Повторна реєстрація студента
void Student::reEnroll() {
    expelled = false;
    cout << firstName << " " << lastName << " has re-enrolled." << endl;
}

// Виведення інформації про студента
void Student::showInfo() const {
    cout << "Student: " << firstName << " " << lastName << ", Age: " << age
        << ", ID: " << studentID << ", GPA: " << fixed << setprecision(2) << gpa
        << (expelled ? " (Expelled)" : "") << endl;
}

// Взаємодія з факультетом
void Student::interactWithFaculty(const Faculty& faculty) const {
    cout << firstName << " is interacting with the faculty: " << faculty.getFacultyName() << endl;
}

// Взаємодія з іншим студентом
void Student::interactWithStudent(const Student& student) {
    cout << firstName << " is interacting with student: " << student.firstName << " " << student.lastName << endl;
}

// Запис даних у файл
void Student::writeToDisk(ofstream& outFile) const {
    outFile << firstName << " " << lastName << " " << age << " " << studentID << " " << gpa << " " << expelled << endl;
}

// Читання даних з файлу
void Student::readFromDisk(ifstream& inFile) {
    inFile >> firstName >> lastName >> age >> studentID >> gpa;
    int expelledInt;
    inFile >> expelledInt;
    expelled = (expelledInt != 0);
}