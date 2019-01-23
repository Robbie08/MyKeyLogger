#include <iostream>
#include <Windows.h> 
using namespace std;

int main() 
{

	MSG msg; // message that won't be processed

	//Hide the console log window
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}