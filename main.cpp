#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
#define ROCK 1
#define PAPER 2
#define SCISSORS 3
//------Text coloring--------
void reset(void);
void red();
void yellow(void);

//-------Function Deceleration------
void menu();
int getComputerChoice();
int getplayerChoice();

int main()
{
    /*
    seeding the rand func in GetComputerChoice
    */
    srand((unsigned int)time(NULL));
    menu();
    int player;
    int npc;
    int playerScore = 0;
    int npcScore = 0;

    /*
    making the game 5 rounds
    and checking for a winner.
    */
    for (int rounds = 1; rounds <= 3; rounds++)
    {
        player = getplayerChoice();
        npc = getComputerChoice();
        cout << "computer choose >> " << npc << endl;
        Sleep(600);
        if (player == npc)
        {
            cout << "---------------------" << endl;
            cout << " its a draw go again" << endl;
            cout << "---------------------" << endl;
            cout << ">> ";
        }

        else if ((player == ROCK && npc == SCISSORS) || (player == PAPER && npc == ROCK) ||
                 (player == SCISSORS && npc == PAPER))

        {
            cout << "---------------------" << endl;
            cout << "player wins Congrats" << endl;
            cout << "---------------------" << endl;
            playerScore++;
            cout << "current Player Score is >> " << playerScore << endl;
            cout << "current Computer Score is >> " << npcScore << endl;
            cout << ">> ";
        }
        else if ((npc == ROCK && player == SCISSORS) || (npc == PAPER && npc == ROCK) ||
                 (npc == SCISSORS && player == PAPER))
        {
            cout << "---------------------" << endl;
            cout << "you lose try again" << endl;
            cout << "---------------------" << endl;
            npcScore++;
            cout << "current Player Score is >> " << playerScore << endl;
            cout << "current Computer Score is >> " << npcScore << endl;
            cout << ">> ";
        }
    }
    /*
    Displaying The Final Score
    */
    red();
    cout << "\n~~~~~~~~~\n";
    cout << "GAME OVER \n";
    cout << "~~~~~~~~~~~\n";

    reset();
    Sleep(500);
    if (playerScore > npcScore)
    {
        yellow();
        cout << "Player Wins :> \n";
        cout << "...............\n";
    }
    else if (npcScore > playerScore)
    {
        yellow();
        cout << "You lose Try Again :<\n";
        cout << ".....................\n";
    }
    else
    {
        yellow();
        cout << "Its A Tie" << endl;
        cout << "................\n";
    }

    return 0;
}
/*
generating random numbers
*/
int getComputerChoice()
{
    return (rand() % 3) + 1;
}
/*
For displaying player options
*/
void menu()
{
    reset();
    cout << "In 5 Rounds See Who Wins\n";
    cout << "Rock, paper, scissors \n";
    yellow();
    cout << "Loading \n";
    cout << "---------------------\n";
    Sleep(1000);
    reset();
    cout << "Choose between the following " << endl;
    cout << "[1] Rock " << endl;
    cout << "[2] Paper " << endl;
    cout << "[3] Scissors " << endl;
    cout << ">> ";
}
/*
getting the player choice and validating it.
*/
int getplayerChoice()
{
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 3)
    {
        Sleep(700);
        red();
        cout << "Invalid Input Try Again" << endl;
        reset();
        cout << ">> ";
        cin >> choice;
    }
    return choice;
}
/*
For Text coloring.
Reseting to light blue color as the main program color.
*/
void reset(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 9);
}
void red(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 12);
}
void yellow(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 14);
}
