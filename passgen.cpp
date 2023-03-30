#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    srand(time(NULL));    // seed the random number generator with the current time;
    string password = ""; // initialize an empty string for the passcode

    // generate a random password of length 8
    for (int i = 0; i < 8; i++)
    {
        int randomNum = rand() % 94 + 33;               // generate a random number between 33 and 126
        char randomChar = static_cast<char>(randomNum); // convert the random number to a character
        password += randomChar;                         // add the character to the password string
    }

    cout << "Your password is." << password << endl; // display the generated password

    return 0;
}