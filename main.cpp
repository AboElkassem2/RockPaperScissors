#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ROCK 1;
#define PAPER 2;
#define SCISSORS 3;
void Menu();
int GetComputerChoice();
int GetplayerChoice();
int Winner();
int main()
{
    srand((unsigned int)time(NULL));
    Menu();
    GetplayerChoice();
    GetComputerChoice();
    cout << GetComputerChoice << " " << GetplayerChoice;

    return 0;
}

int GetComputerChoice()
{
    return (rand() % 3) + 1;
}
void Menu() // For displaying player options
{
    cout << "Rock, paper, scissors \n";
    cout << "choose between the following " << endl;
    cout << " [1] Rock " << endl;
    cout << " [2] Paper " << endl;
    cout << " [3] Scissors " << endl;
}
int GetplayerChoice() // getting the user input "player"
{
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 3)
    {
        cout << " invalid input please try again" << endl;
        return 1;
    }
    else
    {
        return choice;
    }
}