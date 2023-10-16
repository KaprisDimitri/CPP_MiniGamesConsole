#include <vector>
#include <mutex>
#include <thread>
#include <conio.h>
using namespace std;

//A retirer estla que pour le debug est les delegate
#ifndef ConsoleUtility_INCLUDED
#include "ConsoleUtility.cpp"
#endif

#ifndef InputActionManager_INCLUDED
#define InputActionManager_INCLUDED

typedef void(*InputDelegate)();

static int IndexFromName(string name);
static bool isInputActionsEnabled(string name);
static bool isInputActionsEnabledIndex(int index);

static std::mutex globalMutex;
static bool enableInputs;
static int userInput;
//On ajout * 
static vector<mutex*> mutexBool;
static vector<bool> enableInputActions;

class InputAction
{
public:
	string name;
	int keyCodeExpected;


	InputDelegate performed;

	InputAction(string nameAction, int keyCode)
	{
		name = nameAction;
		keyCodeExpected = keyCode;
		performed = nullptr;
	}

	thread Enable(bool active)
	{
		int index = IndexFromName(name);
		enableInputActions[index] = active;

		if (active)
		{
			return thread([this, index] { CheckForInput(index); });
		}

		return thread();
	}

	void CheckForInput(int index)
	{
		do
		{
			if (keyCodeExpected == userInput)
			{
				performed();
			}

		} while (isInputActionsEnabledIndex(index));
	}
};

static bool IsEnableInput()
{
	std::lock_guard<std::mutex> lock(globalMutex);
	return enableInputs;
}

static void InputThread()
{
	while (IsEnableInput())
	{
		int RawUserInput = _getch();
		{
			std::lock_guard<std::mutex> lock(globalMutex);
			userInput = RawUserInput;
		}
		PrintString(to_string(userInput));
	}
}

static thread InitInputActionManager()
{
	enableInputs = true;
	return thread(InputThread);
}

static vector<InputAction> inputActions;

static int IndexFromName(string name)
{
	for (int i = 0; i < inputActions.size(); i++)
	{
		if (inputActions[i].name == name) { return i; }
	}
}

static bool isInputActionsEnabled(string name)
{
	int index = IndexFromName(name);
	//PrintString(to_string(index) +" "+ name);
	std::lock_guard<std::mutex> lock(*(mutexBool[index]));
	return enableInputActions[index];
}

static bool isInputActionsEnabledIndex(int index)
{
	//PrintString(to_string(index)+ " Verif");
	std::lock_guard<std::mutex> lock(*(mutexBool[index]));
	return enableInputActions[index];
}

static void AddInputAction(InputAction newInputAction)
{
	inputActions.push_back(newInputAction);
	mutexBool.push_back(new mutex());
	enableInputActions.push_back(false);
}

static void CreateInputAction(string name, int key, InputDelegate func)
{
	InputAction inputActionMove(name, key);
	inputActionMove.performed = func;

	AddInputAction(inputActionMove); 
}

static InputAction GetInputActionFromName(string name)
{
	for (int i = 0; i < inputActions.size(); i++)
	{
		if (name == inputActions[i].name)
		{
			return inputActions[i];
		}
	}
}

#endif