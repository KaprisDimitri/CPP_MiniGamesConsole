#include <string>
using namespace std;

#ifndef CalculationUtility_INCLUDED
#include "CalculationUtility.cpp" 
#endif
#ifndef ConsoleUtility_INCLUDED
#include "ConsoleUtility.cpp" 
#endif

static class RoleTheDice_FindTheGoodFace
{

public: 

    const string titre = "FindTheGoodFace";

    static void Rules()
    {
        PrintString("Les regle sont simple.");
        PrintString("Vous choissisez une face du des.");
        PrintString("Je vais enssuite tirer le des avec ma main neutre.");
        PrintString("Si la face visible est celle que vous avez choisie ... VOUS AVEZ GAGNEZ !! BRAVO !!!");
        PrintString("Par contre ... si la face visible n'est pas celle que vous avez choisie ... VOUS AVEZ PERDUUUU !! AH AH AH !!!");
        PrintString("Rien a gagner, Rien a perdre. MAIS Que vous faut il pour essayer MAINTENENT !!!");
        int user = AskUserInputIntRanged("Es ce bien claire ?\n 1 - Absolument \n 2 - AHHH oui oui \n 3 - Super bien claire", 1, 3);

        Menu();
    }

    static void Game()
    { 
        ClearConsole();
        PrintString("Tres bien COMMENCONS cetttteee PARTIIIIIEEEE!!!");

        int userFace = AskUserInputIntRanged("Quelle face veux tu choisir ??", 1, 6);
        PrintString("Tu as choisie le " + to_string(userFace) + ", es ce un bON CHOIE ???");
        PrintString("NOUS ALLONS VOIR CA !!!");

        int gameFace = CalculationRandom::FindRandomBetween(1, 6);

        PrintString("Clac .");
        PrintString("Clic ..");
        PrintString("Clouc ...");
        PrintString("ET C'EST LE " + to_string(gameFace) + "!!!");

        if (CheckNumbers::IsEqual(userFace, gameFace))
        {
            PrintString("VOUS AVEZ GAGNEZ !!! BRAVO !!!");
        }
        else
        {
            PrintString("VOUS AVEZ PERDU !!! AH AH AH !!!");
        }

        AskUserQuestion("VOULEZ VOUS RECOMMENCER ???",
            { "Oui", "Non" },
            { "Oui", "Non" },
            { []() { Game(); } ,
              []() { Menu(); } });
    }

    static void Menu()
    {
        AskUserQuestion("Que voudriez vous faire ?",
            { "1", "2", "3" },
            { "1 - Consulter les regles", "2 - Jouer", "3 - Quitter" },
            { []() { Rules(); } ,
              []() { Game(); } ,
              []() { return; } });
    }
};

static class RoleTheDice_BeTheNearest
{

private:

    static void GameLoop(int reference)
    {
        PrintString("Tres bien a toi l'honneur!!! Esperons que tu sois pret du " + to_string(reference));
        PrintString("Lance le des");

        AskUserInputString();
        int userFace = CalculationRandom::FindRandomBetween(1, 6);

        PrintString("Clac .");
        PrintString("Clic ..");
        PrintString("Clouc ...");
        PrintString("ET C'EST LE " + to_string(userFace) + "!!! Tu as " + to_string(Difference(userFace, reference)) + " de difference.");

        PrintString("A Mon Tout Maintenant !!!");
        int aiFace = CalculationRandom::FindRandomBetween(1, 6);

        PrintString("Clac .");
        PrintString("Clic ..");
        PrintString("Clouc ...");
        PrintString("ET C'EST LE " + to_string(aiFace) + "!!! J ai " + to_string(Difference(aiFace, reference)) + " de difference.");

        if (Difference(userFace, reference) == Difference(aiFace, reference))
        {
            PrintString("On dois recommencer on a pas de quoi ce departager !!!");
            GameLoop(reference);
        }
        else if (CheckNumbers::IsLess(userFace, aiFace))
        {
            PrintString("VOUS AVEZ GAGNEZ !!! BRAVO !!!");
        }
        else
        {
            PrintString("VOUS AVEZ PERDU !!! AH AH AH !!!");
        }

    }

public:

    const string titre = "BeTheNearest";

    static void Rules()
    {
        PrintString("Les regle sont simple.");
        PrintString("Le des sera tirer pour definir la face reference.");
        PrintString("On tirera chaqu'un sont tour un des.");
        PrintString("Si tu est le plus proche de la reference ... TU AS GAGNEZ !! BRAVO !!!");
        PrintString("Par contre ... Si je suis le plus proche de la reference ... TU AS PERDUUUU !! AH AH AH !!!");
        PrintString("En cas d'execo on relance les des");
        PrintString("Rien a gagner, Rien a perdre. MAIS Que vous faut il pour essayer MAINTENENT !!!");
        int user = AskUserInputIntRanged("Es ce bien claire ?\n 1 - Absolument \n 2 - AHHH oui oui \n 3 - Super bien claire", 1, 3);

        Menu();
    }

    static void Game()
    {
        ClearConsole();
        PrintString("Tres bien COMMENCONS cetttteee PARTIIIIIEEEE!!!");

        int faceReference = CalculationRandom::FindRandomBetween(1, 6);

        PrintString("Clac .");
        PrintString("Clic ..");
        PrintString("Clouc ...");
        PrintString("ET C'EST LE " + to_string(faceReference) + "!!!");

        GameLoop(faceReference);

       

        AskUserQuestion("VOULEZ VOUS RECOMMENCER ???",
            { "Oui", "Non" },
            { "Oui", "Non" },
            { []() { Game(); } ,
              []() { Menu(); } });
    }

    static void Menu()
    {
        AskUserQuestion("Que voudriez vous faire ?",
            { "1", "2", "3" },
            { "1 - Consulter les regles", "2 - Jouer", "3 - Quitter" },
            { []() { Rules(); } ,
              []() { Game(); } ,
              []() { return; } });
    }
};