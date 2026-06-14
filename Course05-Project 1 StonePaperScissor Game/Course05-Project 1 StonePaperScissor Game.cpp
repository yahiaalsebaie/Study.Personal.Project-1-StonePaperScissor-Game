#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
//Project 1 StonePaperScissor Game
enum enPlayer { Player = 1, Computer = 2 };
enum enRoundResult { player = 1, computer = 2, draw = 3 };
enum enChoice { Stone = 1, Paper = 2, Scissor = 3 };

int RandomNumber(int From, int To)
{
    int random = rand() % (To - From + 1) + From;
    return random;
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

int ReadNumberInRange(int From, int To)
{
    int Number = 0;
    do
    {
        cin >> Number;
        if (Number < From || Number > To)
            cout << "\nInvalid Input!\n";
    } while (Number < From || Number > To);

    return Number;
}
int ReadNumberInRange(int From, int To, string Message, string InValidInputMessage = "")
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
        if (Number < From || Number > To)
        {
            cout << "\nInvalid Input!\n";
            cout << InValidInputMessage;
        }
    } while (Number < From || Number > To);

    return Number;
}
short playerWonCount = 0, computerWonCount = 0, drawCount = 0;
enRoundResult WWhoonTheRound(enChoice PlayerChoice, enChoice ComputerChoice)
{
    if (PlayerChoice == ComputerChoice)
    {
        drawCount++;
        system("color 3F"); //Blue
        return   enRoundResult::draw;
    }
    else if (PlayerChoice == enChoice::Paper && ComputerChoice == enChoice::Stone
        || (PlayerChoice == enChoice::Scissor && ComputerChoice == enChoice::Paper)
        || (PlayerChoice == enChoice::Stone && ComputerChoice == enChoice::Scissor))
    {
        playerWonCount++;
        system("color 2F"); //Green
        return   enRoundResult::player;
    }
    else
    {
        computerWonCount++;
        system("color 4F"); //Red
        return   enRoundResult::computer;
    }
}

string ConvertEnumNumberToText(enChoice choice)
{
    return choice == enChoice::Paper ? "Paper" : (choice == enChoice::Scissor) ? "Scissor" : "Stone";
}
string ConvertEnumNumberToText(enPlayer Player)
{
    return Player == enPlayer::Player ? "Player" : "Computer";
}
string ConvertEnumNumberToText(enRoundResult RoundResult)
{
    return RoundResult == enRoundResult::computer ? "\aComputer" : (RoundResult == enRoundResult::player) ? "Player" : "Draw";
}

void PrintRoundResult(enChoice PlayerChoice, enChoice ComputerChoice, short RoundNumber, enRoundResult WWhoinTheRound)
{
    cout << "\n----------------Round[" << RoundNumber << "]----------------\n";
    cout << "Player Choice   : " << ConvertEnumNumberToText(PlayerChoice) << endl;
    cout << "Computer Choice : " << ConvertEnumNumberToText(ComputerChoice) << endl;
    cout << "Round Winner    : [" << ConvertEnumNumberToText(WWhoinTheRound) << "]." << endl;
    cout << "----------------------------------------\n";
}

void RoundBegins(short WhoManyRounds)
{
    enChoice PlayerChoice, ComputerChoice;



    playerWonCount = 0, computerWonCount = 0, drawCount = 0;
    for (short i = 1; i <= WhoManyRounds; i++)
    {
        cout << "\nRound [" << i << "] begins:\n";

        cout << "\nYour Choice : [1]:Stone , [2]:Paper , [3]:Scissor >> ";
        PlayerChoice = (enChoice)ReadNumberInRange(1, 3, "", "\nYour Choice : [1]:Stone , [2]:Paper , [3]:Scissor >> ");
        ComputerChoice = (enChoice)RandomNumber(1, 3);
        PrintRoundResult(PlayerChoice, ComputerChoice, i, WWhoonTheRound(PlayerChoice, ComputerChoice));
    }

}
string Tabs(short NumberOfTabs = 3)
{
    string tabs = "";
    for (short i = 1; i <= NumberOfTabs; i++)
        tabs += "\t";
    return tabs;
}
void SWhoGameOverScreen()
{
    cout << Tabs() << "--------------------------------------------------------------\n";
    cout << Tabs(6) << "G a m e  O v e r \n";
    cout << Tabs() << "--------------------------------------------------------------\n";
}
void DisplayWinnerColor()
{
    playerWonCount == computerWonCount ? system("color 3F") : playerWonCount > computerWonCount ? system("color 2F") : system("color 4F");
}

string WWhoonTheGame()
{
    return    playerWonCount == computerWonCount ? "No Winner" : playerWonCount > computerWonCount ? "Player Wins" : "Computer Wins";
}
void DisplayBackgroundColorBack(HANDLE hConsole)
{
    playerWonCount == computerWonCount ? SetConsoleTextAttribute(hConsole, 63) : playerWonCount > computerWonCount ? SetConsoleTextAttribute(hConsole, 47) : SetConsoleTextAttribute(hConsole, 79);
}
void GameResults(short WhoManyRounds)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    DisplayWinnerColor();
    cout << Tabs() << "---------------[Game Results]---------------------------------" << endl;

    cout << Tabs() << "Game Rounds        : " << to_string(WhoManyRounds) << "\n";

    SetConsoleTextAttribute(hConsole, 160);
    cout << Tabs() << "Player won times   : " << playerWonCount;
    DisplayBackgroundColorBack(hConsole);
    cout << "\n";

    SetConsoleTextAttribute(hConsole, 192);
    cout << Tabs() << "Computer won times : " << computerWonCount;
    DisplayBackgroundColorBack(hConsole);
    cout << "\n";

    SetConsoleTextAttribute(hConsole, 176);
    cout << Tabs() << "Draw times         : " << drawCount;
    DisplayBackgroundColorBack(hConsole);
    cout << "\n";


    cout << Tabs() << "Final Winner       : [" << WWhoonTheGame() << "]." << endl;
    cout << Tabs() << "--------------------------------------------------------------\n";
}
void StartGame()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    char PlayAgain = 'y';
    do
    {
        system("cls");
        system("color 0F");

        short WhoManyRounds = (short)ReadNumberInRange(1, 10, "Who Many Rounds 1 to 10 ? : ");
        RoundBegins(WhoManyRounds);
        SWhoGameOverScreen();
        GameResults(WhoManyRounds);

        cout << "\nDo You want to play again ? [Y/N] : ";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}
int main() {
    srand((unsigned)time(NULL));

    StartGame();
    return 0;
}