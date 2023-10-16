#include <string>
#include <thread>
#include <vector>
#include <conio.h>
#include <mutex>
using namespace std;

#ifndef ConsoleUtility_INCLUDED
#include "ConsoleUtility.cpp"
#endif

#ifndef InputActionManager_INCLUDED
#include "InputActionManager.cpp"
#endif

 
int value;

void JeBOUGE()
{
	if (isInputActionsEnabled("Move"))
	{
		value++;
		cout << "JeBouge " + to_string(value) << endl;
	}
}
 
void JeSaute()
{
	if (isInputActionsEnabled("Jump"))
	{
		value++;
		cout << "Je Saute"+ to_string(value) << endl;
	}
}

 
int main()  
{
	thread workerInputs = InitInputActionManager();
	CreateInputAction("Move", 97, [] {JeBOUGE(); });
	CreateInputAction("Jump", 122, [] {JeSaute(); });
	thread workerMove = GetInputActionFromName("Move").Enable(true);  
	thread workerJump = GetInputActionFromName("Jump").Enable(true);  
	int i = 0;
	do
	{
		//PrintString("Thread principale : " + to_string(value));
		std::this_thread::sleep_for(std::chrono::seconds(10));
		i++; 
	} while (i < 10); 
	GetInputActionFromName("Move").Enable(false);
	GetInputActionFromName("Jump").Enable(false);
	enableInputs = false;
	PrintString("Programme Finie");
	workerMove.join();
	workerJump.join();
	workerInputs.join();
	PrintString("Tout Thread Terminer");
}  