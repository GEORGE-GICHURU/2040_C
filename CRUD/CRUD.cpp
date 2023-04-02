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

void readStudent()
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

void updateStudent()
{
    string name;
    cout << "Enter name of student to update: ";
    getline(cin, name);

    ifstream infile("students.txt");
    ofstream outfile("update.txt");
    string line;
    bool found = false;
    while (getline(infile, line))
    {
        Student s;
        size_t pos = line.find(",");
        s.name = line.substr(0, pos);
        if (s.name == name)
        {
            found = true;
            cout << "Enter new age: ";
            cin >> s.age;
            cin.ignore();
            cout << "Enter new major: ";
            getline(cin, s.major);
            outfile << s.name << "," << s.age << "," << s.major << endl;
        }
        else
        {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    if (!found)
    {
        cout << "Student not found." << endl;
    }
    else
    {
        remove("students.txt");
        rename("update.txt", "students.txt");
        cout << "Student updated." << endl;
    }
}

void deleteStudent()
{
    string name;
    cout << "Enter the name of the student to delete: ";
    getline(cin, name);

    ifstream infile("students.txt");
    ofstream outfile("update.txt");
    string line;
    bool found = false;
    while (getline(infile, line))
    {
        Student s;
        size_t pos = line.find(",");
        s.name = line.substr(0, pos);
        if (s.name == name)
        {
            found = true;
        }
        else
        {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    if (!found)
    {
        cout << "Student not found.";
    }
    else
    {
        remove("students.txt");
        rename("update.txt", "students.txt");
        cout << "Student has been deleted." << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "1. Create student" << endl;
        cout << "2. Read student" << endl;
        cout << "3. Update student" << endl;
        cout << "4. Delete student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {data
        case 1:
            createStudent();
            break;

        case 2:
            readStudent();
            break;

        case 3:
            updateStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}