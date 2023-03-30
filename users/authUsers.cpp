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

    // check if the entered username and password match any of the usernames and passwords in the map
    if (users.count(username) && users[username] == password)
    {
        cout << "Authentication is successfull!!!" << endl;
        // allow the user to acces the system
    }
    else
    {
        cout << "Authentication failed. Please try again." << endl;
        // Deny access to the system
    }

    return 0;
}