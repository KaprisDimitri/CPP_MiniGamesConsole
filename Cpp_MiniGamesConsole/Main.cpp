#include <string>
#include <iostream>
using namespace std;
#ifndef StringUtility_INCLUDED
#include "StringUtility.cpp"
#endif
#ifndef CalculationUtility_INCLUDED
#include "CalculationUtility.cpp" 
#endif
#ifndef ConsoleUtility_INCLUDED
#include "ConsoleUtility.cpp" 
#endif

#include"RoleTheDice.cpp"

bool isRunning = true;
int main()
{
    do
    {
        AskUserQuestion("Quel jeu voudriez vous faire ?",
            { "1", "2", "3" },
            { "1 - FindTheGoodFace", "2 - BeTheNearest", "3 - Quitter" },
            { []() { RoleTheDice_FindTheGoodFace::Menu(); } ,
              []() { RoleTheDice_BeTheNearest::Menu(); } ,
              []() { isRunning = false; } });

    } while (isRunning);
	cout << "Hello" << endl;
}