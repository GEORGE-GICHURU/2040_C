#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';

void drawBoard()
{
    cout << "Tic Tac Toe Game" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl
         << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl
         << endl;
}

void playerTurn()
{
    int choice;
    cout << "Player " << player << ", enter a number: ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        cout << "Invalid move, try again." << endl;
        playerTurn();
    }
    else
    {
        board[row][col] = player;
    }
}

bool gameEnd()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }

    // Check if board is full
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O')
            {
                count++;
            }
        }
    }
    if (count == 9)
    {
        return true;
    }

    return false;
}

void switchPlayer()
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

int main()
{
    while (!gameEnd())
    {
        drawBoard();
        playerTurn();
        switchPlayer();
    }

    drawBoard();
    if (gameEnd() && player == 'X')
    {
        cout << "Player O wins!" << endl;
    }
    else if (gameEnd() && player == 'O')
    {
        cout << "Player X wins!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }

    return 0;
}