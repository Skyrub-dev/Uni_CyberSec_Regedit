#include <iostream>
#include <Windows.h>
#include <tchar.h>

using namespace std;

//ANTIVIRUS

int main()
{

    HKEY hk;
    DWORD ValueNumber{};        //number of values for a key
    DWORD MaxValueNameLen{};    //longest value name
    DWORD MaxValueDataLen{};    //longest value data
    DWORD valueNameLen;         //value name length
    DWORD dataLen;              //data length
    

    TCHAR NameToFind[] = TEXT("MSPaint"); //Will search for "MSPaint"
    TCHAR valueName[28], valuePath[MAX_PATH];
    //--------------------Opening the Run Key----------//
    RegOpenKey(HKEY_CURRENT_USER,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\run",
        &hk); //Where the program will look to find the key

    //--------------------Get Key Values ------------//
    RegQueryInfoKey(hk,
        NULL, NULL, NULL, NULL, NULL, NULL,
        &ValueNumber,
        &MaxValueNameLen,
        &MaxValueDataLen,
        NULL, NULL);
    cout << "Number of entries in run is " << ValueNumber << "\n\n";

    //---------------------------Listing Key Values----------------//

    if (ValueNumber)
    {
        cout << "Now, listing each value and its path \n\n"; /*This will list every value currently 
        stored at the above location in the windows registry:
        (SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\run)*/

        for (int j = 0; j < (int)ValueNumber; j++) /*int of j declared, for every registry key represented by 'ValueNumber'
            it will increment resulting in a list*/
        {
            valueNameLen = MaxValueNameLen;
            dataLen = MaxValueDataLen;

            //Enumerate the key values
            RegEnumValue(hk,
                j,
                valueName,
                &valueNameLen,
                NULL,
                NULL,
                (LPBYTE)valuePath,
                &dataLen);

            //use wcout insted of cout to print out TCHAR arryas
            wcout << "Name: " << valueName << ", path: ";
            wcout << valuePath << "\n";

            // _tcscmp is used to compare two TCHAR values
            if (_tcscmp(valueName, NameToFind) == 0)
            {
                cout << "Infected entry found, deleting... \n";
                cout << "...Deleted\n";
                RegDeleteValue(hk, valueName); //Will ONLY delete the registry key
                DeleteFile(valuePath); //Deletes the application from the user's computer
            }
            else
            {
                cout << "Infected entry not found, moving to next...\n\n";
            }
            
        }
    }

    RegCloseKey(hk);

    return 0;

}
