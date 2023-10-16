/*#include <mutex>
using namespace std;
#include <thread>
#include <vector>
#include <conio.h>

//A retirer
#ifndef ConsoleUtility_INCLUDED
#include "ConsoleUtility.cpp"
#endif

class InputActionManager;

#ifndef InputActionClasses_INCLUDED
#define InputActionClasses_INCLUDED


//Permet de communiquer une variable entre thread
/*static std::mutex mtx;
static bool enableInput;
static bool isInputEnabled() {
	std::lock_guard<std::mutex> lock(mtx);
	return enableInput;
}

class InputAction
{
public:
	string name;
	int keyCodeExpected;


	DelegateFunction performed;

	InputAction(string nameAction, int keyCode)
	{
		name = nameAction;
		keyCodeExpected = keyCode;
		performed = nullptr;
	}

	thread Enable(bool active)
	{
		enableInputActions[IndexFromName(name)] = active;

		if (active)
		{
			return thread(&InputAction::CheckForInput, this);
		}

		return thread();
	}

	void CheckForInput()
	{
		do
		{
			int userInput = _getch();

			if (keyCodeExpected == userInput)
			{
				cout << "Bon " + to_string(userInput) << endl;
				performed();
			}
			else
			{
				cout << "PasBOn " + to_string(userInput) << endl;
			}

		} while (isInputActionsEnabled());
	}
};

class ActionMap
{
public:
	string name;

	vector<InputAction> inputActions;

	ActionMap(string nameAction)
	{
		name = nameAction;
	}

	void AddInputAction(InputAction newInputAction)
	{
		inputActions.push_back(newInputAction);
	}

	InputAction GetInputActionFromName(string name)
	{
		for (int i = 0; i < inputActions.size(); i++)
		{
			if (name == inputActions[i].name)
			{
				return inputActions[i];
			}
		}
	}
}; 

#endif*/