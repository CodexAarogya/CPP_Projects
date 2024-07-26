#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
char positions[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string player1;
string player2;
int turn, test_draw;
bool draw;
char playerChoice = 'x';
int row, coln;
void intro(void)
{
    for (int i = 0; i < 101; i++)
        cout << "~";
    cout << endl
         << "~";
    cout << setw(50) << " TIC - TAC - TOE " << setw(50);
    cout << " ~";
    cout << endl
         << "~";
    for (int i = 0; i < 99; i++)
        cout << "~";
    cout << "~" << endl;
    cout << "Designed by: Aarogya " << endl;
    cout << "For more projects : Follow CodexAarogya on github.com." << endl;
    for (int i = 0; i < 101; i++)
        cout << "_";
    cout << endl;
}
void initialData(void)
{
    cout << "Enter Name of Player 1: ";
    getline(cin, player1);
    cout << "Enter Name of Player 2: ";
    getline(cin, player2);
    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}
void mainStructure(void)
{
    cout << endl;
    cout << "     |      |      " << endl;
    cout << "  " << positions[0][0] << "  |   " << positions[0][1] << "  |   " << positions[0][2] << "  " << endl;
    cout << "_____|______|______" << endl;
    cout << "     |      |      " << endl;
    cout << "  " << positions[1][0] << "  |   " << positions[1][1] << "  |   " << positions[1][2] << "  " << endl;
    cout << "_____|______|______" << endl;
    cout << "     |      |      " << endl;
    cout << "  " << positions[2][0] << "  |   " << positions[2][1] << "  |   " << positions[2][2] << "  " << endl;
    cout << "     |      |      " << endl
         << endl;
    cout << "____________________________________________" << endl;
}
void gameBody(void)
{
    int choice;

    if (playerChoice == 'x')
    {
        cout << endl;
        cout << player1 << "'s Turn ::" << endl;
        cout << "Choose the position : ";
        cin >> choice;
        cout << endl
             << "---------------------------------------------------------" << endl;
    }
    if (playerChoice == 'O')
    {
        cout << player2 << "'s Turn ::" << endl;
        cout << "Choose the position : ";
        cin >> choice;
        cout << endl
             << "---------------------------------------------------------" << endl;
    }
    switch (choice)
    {
    case 1:
    {
        row = 0;
        coln = 0;
        break;
    }
    case 2:
    {
        row = 0;
        coln = 1;
        break;
    }
    case 3:
    {
        row = 0;
        coln = 2;
        break;
    }
    case 4:
    {
        row = 1;
        coln = 0;
        break;
    }
    case 5:
    {
        row = 1;
        coln = 1;
        break;
    }
    case 6:
    {
        row = 1;
        coln = 2;
        break;
    }
    case 7:
    {
        row = 2;
        coln = 0;
        break;
    }
    case 8:
    {
        row = 2;
        coln = 1;
        break;
    }
    case 9:
    {
        row = 2;
        coln = 2;
        break;
    }
    default:
    {
        cout << "Invalid Position !!" << endl;
        abort();
    }
    }

    if (playerChoice == 'x' && positions[row][coln] != 'x' && positions[row][coln] != 'O')
    {
        positions[row][coln] = 'x';
        playerChoice = 'O';
    }
    else if (playerChoice == 'O' && positions[row][coln] != 'x' && positions[row][coln] != 'O')
    {
        positions[row][coln] = 'O';
        playerChoice = 'x';
    }
    else
    {
        cout << endl
             << "---------------------------------------------------------" << endl;
        cout << "Space " << choice << " is already occupied !!" << endl;
        cout << "---------------------------------------------------------" << endl;
        draw = true;
    }
}
bool checkWinner(void)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (positions[i][0] == positions[i][1] && positions[i][0] == positions[i][2])
            {
                if (positions[i][0] == 'x')
                {
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    cout << player1 << " WINS !!";
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    abort();
                }

                else
                {
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    cout << player2 << " WINS !!";
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    abort();
                }
            }
            else if (positions[0][j] == positions[1][j] && positions[0][j] == positions[2][j])
            {
                if (positions[i][0] == 'x')
                {
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    cout << player1 << " WINS !!";
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    abort();
                }

                else
                {
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    cout << player2 << " WINS !!";
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    abort();
                }
            }
            else if (positions[0][0] == positions[1][1] && positions[0][0] == positions[2][2])
            {
                if (positions[0][0] == 'x')
                {
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    cout << player1 << " WINS !!";
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    abort();
                }

                else
                {
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    cout << player2 << " WINS !!";
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    abort();
                }
            }
            else if (positions[0][2]==positions[1][1] && positions[0][2]== positions[2][0])
            {
                 if (positions[0][2] == 'x')
                {
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    cout << player1 << " WINS !!";
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    abort();
                }

                else
                {
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    cout << player2 << " WINS !!";
                    cout << endl
                         << "---------------------------------------------------------" << endl;
                    abort();
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (positions[i][j] != 'x' && positions[i][j] != 'O')
                return false;
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (positions[i][j] == 'x' && positions[i][j] == 'O' && draw == true)
            {
                cout << " GAME IS DRAW !!!";
                abort();
            }
        }
    }
    return false;
}

int main()
{
    intro();
    cout << endl;
    initialData();
    do
    {
        mainStructure();
        gameBody();
        checkWinner();
    } while (checkWinner != false);
    return 0;
}
