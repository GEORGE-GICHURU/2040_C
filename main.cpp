#include <iostream>
using namespace std;

char board[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
char player = "X";

void drawBoard()
{
    cout << "Tic Tac Toe Game" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl
         << endl;
    cout << "      |        |       " << endl;
}
