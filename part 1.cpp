#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Student {
    string firstName;
    string lastName;
    int age;
    int group;
    string sport;
    vector<string> clubs;
};

vector<Student> students;
struct club {
    string name;
    int capacity=60;
    int maleCount=0;
    int femaleCount=0;
};
struct sport {
    string name;
    int capacity=20;
    int maleCount=0;
    int femaleCount=0;
};
void addStudent() {
    Student newStudent;
    cout << "Enter student's first name: ";
    cin >> newStudent.firstName;
    cout << "Enter student's last name: ";
    cin >> newStudent.lastName;
    cout << "Enter student's age: ";
    cin >> newStudent.age;
    cout << "Enter student's group: ";
    cin >> newStudent.group;

    students.push_back(newStudent);
}

void viewStudents() {
    for (const auto& student : students) {
    cout << student.firstName << " " << student.lastName << " - Age: " << student.age << " - Group: " << student.group << std::endl;
    }
}

void viewClubsSocieties() {

    cout << "Club/Societies Activities: Journalism Club, Red Cross Society, AISEC, Business Club, Computer Science Club" << std::endl;
}

void viewSports() {
    cout << "Sporting Activities: Rugby, Athletics, Swimming, Soccer" << endl;
}

void viewGroupedStudents() {
    for (const auto& student : students) {
        cout << student.firstName << " " << student.lastName << " - Group: " << student.group << " - Sport: " << student.sport;
        cout << " - Clubs: ";
        for (const auto& club : student.clubs) {
            cout << club << ", ";
        }
        cout << std::endl;
    }
}

void saveDataToFile() {
    ofstream file("student_data.csv");
    for (const auto& student : students) {
        file << student.firstName << "," << student.lastName << "," << student.age << "," << student.group << std::endl;
    }
    file.close();
    cout << "Data saved to student_data.csv" << endl;
}
