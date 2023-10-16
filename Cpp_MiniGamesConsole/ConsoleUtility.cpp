#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <windows.h>
#ifndef StringUtility_INCLUDED
#include "StringUtility.cpp"
#endif
#ifndef CalculationUtility_INCLUDED
#include "CalculationUtility.cpp" 
#endif 

#ifndef ConsoleUtility_INCLUDED
#define ConsoleUtility_INCLUDED
typedef void(*DelegateFunction)();


static void ClearConsole()
{
    system("CLS");
}

static void PrintString(string toPrint)
{
    if (toPrint == "" || toPrint == " ") { return; }
    cout << toPrint << endl;
}

static void PrintStringColored(string toPrint)
{
    if (toPrint == "" || toPrint == " ") { return; }
    cout << toPrint << endl;
}

static void ColorConsolText(int color)
{
    if (color < 0 || color > 15) { return; }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
}

static void ColorConsolTextDefault()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 15);
}

static string AskUserInputString()
{
    string toReturn;
    cin >> toReturn;
    return toReturn;
}


static int GetIndexFromUserInputSpecifiqueStrings(string askSentence, vector<string> listKeyChoises, vector<string> listOfChoises)
{
    bool isValide = false;
    string userInput;
    int toReturn = 0;
    do
    {
        PrintString(askSentence);
        for (int i = 0; i < listOfChoises.size(); i++)
        {
            PrintString(listOfChoises[i]);
        }
        cin >> userInput;

        ClearConsole();
        for (int i = 0; i < listKeyChoises.size(); i++)
        {
            isValide = ToLowerCase(listKeyChoises[i]) == ToLowerCase(userInput);
            if (isValide) { toReturn = i; break; }
        }

        if (!isValide)
        {
            PrintString("L'entrer " + userInput + " n'est pas valide.");
        }

    } while (!isValide);

    return toReturn;
}

static int AskUserInputInt(string askSentence)
{
    bool isValidInput = false;
    int num = 0;

    do
    {
        PrintString(askSentence);
        string userInput = AskUserInputString();

        ClearConsole();

        isValidInput = IntTryParse(userInput, num);
        if (!isValidInput)
        {
            PrintString("L'entier " + userInput + " n'est pas valide.");
        }

    } while (!isValidInput);

    return num;
}

static int AskUserInputIntRangedInclusif(string askSentence, int min, int max)
{
    bool isValidInput = false;
    int userIntInput = 0;
    do
    {
        userIntInput = AskUserInputInt(askSentence);

        isValidInput = CheckNumbers::IsBetweenInclusif(userIntInput, min, max);

        if (!isValidInput)
        {
            PrintString("L'entier " + to_string(userIntInput) + " n'est pas entre (Inclusif) " + to_string(min) + " et " + to_string(max));
        }

    } while (!isValidInput);

    return userIntInput;
}

static int AskUserInputIntRanged(string askSentence, int min, int max)
{
    bool isValidInput = false;
    int userIntInput = 0;
    do
    {
        userIntInput = AskUserInputInt(askSentence);

        isValidInput = CheckNumbers::IsBetween(userIntInput, min, max);

        if (!isValidInput)
        {
            PrintString("L'entier " + to_string(userIntInput) + " n'est pas entre " + to_string(min) + " et " + to_string(max));
        }

    } while (!isValidInput);

    return userIntInput;
}

static void AskUserQuestion(string askSentence, vector<string> listKeyChoises, vector<string> listOfChoises, vector<DelegateFunction> listOfDelegate)
{
    listOfDelegate[GetIndexFromUserInputSpecifiqueStrings(askSentence, listKeyChoises, listOfChoises)]();
}

#endif