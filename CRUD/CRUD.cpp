#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int age;
    string major;
};

void createStudent()
{
    Student s;
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter major: ";
    getline(cin, s.major);

    ofstream outfile("students.txt", ios::app);
}