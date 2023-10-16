#include <string>
#include <iostream>
using namespace std;

#ifndef StringUtility_INCLUDED
#define StringUtility_INCLUDED

static bool IntTryParse(string stringToParse, int& toReturn)
{
    try {
        // Essayer de convertir la chaîne en int
        toReturn = stoi(stringToParse);
        return true;
    }
    catch (invalid_argument) {
        // La conversion a échoué
        return false;
    }
    catch (out_of_range) {
        // La chaîne est en dehors de la plage des int
        return false;
    }
}

static string ToLowerCase(string stringToLower)
{
    string toRetrun = "";
    for (int i = 0; i < stringToLower.size(); i++)
    {
        toRetrun += tolower(stringToLower[i]);
    }
    return toRetrun;
}

#endif