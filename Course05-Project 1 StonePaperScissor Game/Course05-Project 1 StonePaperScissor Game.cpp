#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
//Project 1 StonePaperScissor Game
enum enPlayer { Player = 1, Computer = 2 };
enum enWinner { player = 1, computer = 2, draw = 3 };
enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner RoundWinner;
    string WinnerName = "";

};

struct stGameResults
{
    short GameRounds = 0;
    short playerWonCount = 0;
    short computerWonCount = 0;
    short drawCount = 0;
    enWinner GameWinner;
    string WinnerName = "";

};

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
enWinner WhoWonTheRound(enGameChoice PlayerChoice, enGameChoice ComputerChoice)
{
    /*if (PlayerChoice == ComputerChoice)
    {
        return enWinner::draw;
    }

    if ((PlayerChoice == enGameChoice::Paper && ComputerChoice == enGameChoice::Stone) ||
        (PlayerChoice == enGameChoice::Scissor && ComputerChoice == enGameChoice::Paper) ||
        (PlayerChoice == enGameChoice::Stone && ComputerChoice == enGameChoice::Scissor))
    {
        return enWinner::player;
    }
    return enWinner::computer;*/

    //هستخدم المصفوفات 3*3 لتبسيط الحل وتسريعه

    //enum enWinner { player = 1, computer = 2, draw = 3 };
    //enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };
    // -----------------------------------------------------------
    // الاختيار:  Stone(1)   |   Paper(2)  |  Scissor(3)  |
    // -----------------------------------------------------------
    // Stone  |  3 (Draw)   |  2 (Comp)   |  1 (Player)  | 
    // Paper  |  1 (Player) |  3 (Draw)   |  2 (Comp)    | 
    // Scissor|  2 (Comp)   |  1 (Player) |  3 (Draw)    | 
    // -----------------------------------------------------------

    short arrResults[3][3] = {
        {3,2,1}, //Stone
        {1,3,2}, //Paper
        {2,1,3} //Scissor
    };
    return (enWinner)arrResults[PlayerChoice - 1][ComputerChoice - 1];

}

enWinner WhoWonTheGame(short playerWonCount, short computerWonCount)
{
    return    playerWonCount == computerWonCount ? enWinner::draw : playerWonCount > computerWonCount ? enWinner::player : enWinner::computer;
}

string ConvertEnumNumberToText(enGameChoice choice)
{
    //return choice == enGameChoice::Paper ? "Paper" : (choice == enGameChoice::Scissor) ? "Scissor" : "Stone";
    //Using Array
    string arrChoice[3] = { "Stone", "Paper", "Scissor" };
    return arrChoice[choice - 1];
}
string ConvertEnumNumberToText(enPlayer Player)
{
    //   return Player == enPlayer::Player ? "Player" : "Computer";
         //Using Array
    string arrPlayer[2] = { "Player", "Computer" };
    return arrPlayer[Player - 1];
}
string ConvertEnumNumberToText(enWinner RoundResult)
{
    // return RoundResult == enWinner::computer ? "\aComputer" : (RoundResult == enWinner::player) ? "Player" : "Draw";
     //enum enWinner { player = 1, computer = 2, draw = 3 };
    string arrResult[3] = { "Player", "\aComputer", "Draw" };
    return arrResult[RoundResult - 1];

}

void PrintRoundResult(stRoundInfo RoundInfo)
{

    cout << "\n.----------------Round[" << RoundInfo.RoundNumber << "]----------------.\n";
    cout << "Player Choice   : " << ConvertEnumNumberToText(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice : " << ConvertEnumNumberToText(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner    : [" << ConvertEnumNumberToText(RoundInfo.RoundWinner) << "]." << endl;
    cout << ".----------------------------------------.\n";
}
stGameResults FillGameResults(short HowManyRounds, short playerWonCount, short computerWonCount, short drawCount)
{
    stGameResults GameResults;
    GameResults.GameRounds = HowManyRounds;
    GameResults.playerWonCount = playerWonCount;
    GameResults.computerWonCount = computerWonCount;
    GameResults.drawCount = drawCount;
    GameResults.GameWinner = WhoWonTheGame(playerWonCount, computerWonCount);
    GameResults.WinnerName = ConvertEnumNumberToText(GameResults.GameWinner);
    return GameResults;
}
stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo roundInfo;
    short playerWonCount = 0, computerWonCount = 0, drawCount = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        roundInfo.RoundNumber = GameRound;
        cout << "\nYour Choice : [1]:Stone , [2]:Paper , [3]:Scissor >> ";
        roundInfo.PlayerChoice = (enGameChoice)ReadNumberInRange(1, 3, "", "\nYour Choice : [1]:Stone , [2]:Paper , [3]:Scissor >> ");
        roundInfo.ComputerChoice = (enGameChoice)RandomNumber(1, 3);

        roundInfo.RoundWinner = WhoWonTheRound(roundInfo.PlayerChoice, roundInfo.ComputerChoice);

        if (roundInfo.RoundWinner == enWinner::player) {
            playerWonCount++;
            system("color 2F"); // Green
        }
        else if (roundInfo.RoundWinner == enWinner::computer) {
            computerWonCount++;
            system("color 4F"); // Red
        }
        else {
            drawCount++;
            system("color 3F"); // Blue
        }

        PrintRoundResult(roundInfo);
    }

    return FillGameResults(HowManyRounds, playerWonCount, computerWonCount, drawCount);
}

string Tabs(short NumberOfTabs = 3)
{
    string tabs = "";
    for (short i = 1; i <= NumberOfTabs; i++)
        tabs += "\t";
    return tabs;
}
void ShowGameOverScreen()
{
    cout << Tabs() << "--------------------------------------------------------------\n";
    cout << Tabs(6) << "G a m e  O v e r \n";
    cout << Tabs() << "--------------------------------------------------------------\n";
}
void DisplayWinnerColor(stGameResults gameResult)
{
    // gameResult.playerWonCount == gameResult.computerWonCount ? system("color 3F") : gameResult.playerWonCount > gameResult.computerWonCount ? system("color 2F") : system("color 4F");

     // system("color 2F"); // Green
     // system("color 4F"); // Red
     // system("color 3F"); // Blue
     // enum enWinner { player = 1, computer = 2, draw = 3 };

    string Colors[3] = { "color 2F","color 4F","color 3F" };
    system(Colors[gameResult.GameWinner - 1].c_str());

}


void DisplayBackgroundColorBack(HANDLE hConsole, stGameResults gameResult)
{
    gameResult.playerWonCount == gameResult.computerWonCount ? SetConsoleTextAttribute(hConsole, 63) : gameResult.playerWonCount > gameResult.computerWonCount ? SetConsoleTextAttribute(hConsole, 47) : SetConsoleTextAttribute(hConsole, 79);
}
void ShowFinalGameResults(stGameResults GameResults)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    DisplayWinnerColor(GameResults);
    cout << Tabs() << ".-----------------------[Game Results]-----------------------." << endl;

    cout << Tabs() << " Game Rounds        : " << GameResults.GameRounds << "\n";

    SetConsoleTextAttribute(hConsole, 160);
    cout << Tabs() << " Player won times   : " << GameResults.playerWonCount;
    DisplayBackgroundColorBack(hConsole, GameResults);
    cout << "\n";

    SetConsoleTextAttribute(hConsole, 192);
    cout << Tabs() << " Computer won times : " << GameResults.computerWonCount;
    DisplayBackgroundColorBack(hConsole, GameResults);
    cout << "\n";

    SetConsoleTextAttribute(hConsole, 176);
    cout << Tabs() << " Draw times         : " << GameResults.drawCount;
    DisplayBackgroundColorBack(hConsole, GameResults);
    cout << "\n";


    cout << Tabs() << " Final Winner       : [" << GameResults.WinnerName << "]." << endl;
    cout << Tabs() << ".-------------------------------------------------------------.\n";
}
void StartGame()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    char PlayAgain = 'y';
    do
    {
        system("cls");
        system("color 0F");

        short HowManyRounds = (short)ReadNumberInRange(1, 10, "How Many Rounds 1 to 10 ? : ");
        stGameResults GameResults = PlayGame(HowManyRounds);
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << "\nDo You want to play again ? [Y/N] : ";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}
int main() {
    srand((unsigned)time(NULL));

    StartGame();
    return 0;
}