#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // Read the usernames and passwords from a text file
    ifstream infile("users.txt");
    map<string, string> users;
    string username, password;
    while (infile >> username >> password)
    {
        users[username] = password;
    }

    // prompt the user to enter their username and password
    cout << "Enter your username";
    cin >> username;
    cout << "Enter your password";
    cin >> password;
}