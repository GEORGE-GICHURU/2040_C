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
    outfile << s.name << "," << s.age << "," << s.major << endl;
    outfile.close();
}

void readStudents()
{
    ifstream infile("students.txt");
    string line;
    while (getline(infile, line))
    {
        Student s;
        size_t pos = line.find(",");
        s.name = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(",");
        s.age = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        s.major = line;
        cout << "Name: " << s.name << ", Age:" << s.age << ", Major" << s.major << endl;
    }

    infile.close();
}