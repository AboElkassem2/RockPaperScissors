#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ROCK 1
#define PAPER 2
#define SCISSORS 3
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
    for (int rounds = 1; rounds <= 5; rounds++)
    {
        player = getplayerChoice();
        npc = getComputerChoice();
        cout << "computer choose >> " << npc << endl;
        if (player == npc)
        {
            cout << "---------------------" << endl;
            cout << " its a draw go again" << endl;
            cout << "---------------------" << endl;
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
        }
    }
    /*
    Displaying The Final Score
    */

    if (playerScore > npcScore)
    {

        cout << "Player Wins :> \n";
        cout << "...............\n";
    }
    else if (npcScore > playerScore)
    {

        cout << "You lose Try Again :<\n";
        cout << ".....................\n";
    }
    else
    {

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
    cout << "In 5 Rounds See Who Wins\n";
    cout << "---------------------------" << endl;
    cout << "Rock, paper, scissors \n";
    cout << "choose between the following " << endl;
    cout << " [1] Rock " << endl;
    cout << " [2] Paper " << endl;
    cout << " [3] Scissors " << endl;
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
        cout << "Invalid Input Try Again" << endl;
        cout << ">> ";
        cin >> choice;
    }
    return choice;
}