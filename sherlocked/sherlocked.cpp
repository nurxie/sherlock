#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <filesystem>
#include <locale.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //do not touch! init a colored string!

const string logoWay = "../logo.txt";
const char encryptionToken[8] = {'S','H','E','R','L','O','C','K',};
string directory = "";
TCHAR buffer[MAX_PATH];

boolean isTheFileEncrypted(string fileName) {
    char encryptionIndicator[8];
    if ((fileName.find(".") < 100 )&&(fileName.find(".") >= 1 )) {
        string watchedDirectory = directory + ((char)92) + fileName;
        //cout << watchedDirectory << endl;
        ifstream openFile(watchedDirectory);
        if (!openFile) return false; //if do not open
        openFile.get(encryptionIndicator, 8);
        int c = 0;
        for (int i = 0; i < 8; i++) {
            if (encryptionIndicator[i] == encryptionToken[i]) c++;
        }
        if (c == 7) {
            return true;
        }
        else {
           return false;
        }
    }
    else {
        return false;
    }
}

void printAMultiColoredString(string string, int backGroundColor, int textColor) {
    SetConsoleTextAttribute(hConsole, (WORD)((backGroundColor << 4) | textColor));
    cout << string << endl;
    /*
    0   BLACK
    1   BLUE
    2   GREEN
    3   CYAN
    4   RED
    5   MAGENTA
    6   BROWN
    7   LIGHTGRAY
    8   DARKGRAY
    9   LIGHTBLUE
    10  LIGHTGREEN
    11  LIGHTCYAN
    12  LIGHTRED
    13  LIGHTMAGENTA
    14  YELLOW
    15  WHITE
    */
}

void logoInit(string way) {
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
        string line;
        ifstream logoFile(way);
        if (logoFile.is_open())
        {
            while (getline(logoFile, line))
            {
                cout << "                 " + line << std::endl;
            }
        }
        logoFile.close();
        cout << endl;
}

boolean fileCheked() {
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
    string watchedDirectory = "";
        GetModuleFileName(NULL, buffer, sizeof(buffer) / sizeof(buffer[0])); 
        wcout << "The path to the file that is running:" << endl << buffer << endl << endl;

        GetCurrentDirectory(sizeof(buffer), buffer);
        wstring wstringBuffer(&buffer[0]); //convert to wstring
        string dir(wstringBuffer.begin(), wstringBuffer.end()); //and convert to string.
        watchedDirectory = dir;
        directory = dir;
        wcout << "Directory in which the SHERLOCK is open: " << endl;
        cout << watchedDirectory << endl;

        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
        cout << "================== Searches for files in the directory in which the program is open ==================" << endl;
        WIN32_FIND_DATAW wfd;
        watchedDirectory = watchedDirectory + "/*";
        wstring wstr(watchedDirectory.begin(), watchedDirectory.end());
        LPCWSTR wide_string;
        wide_string = wstr.c_str();
        HANDLE const hFind = FindFirstFileW(wide_string, &wfd); //chose the dir
        setlocale(LC_ALL, "");
        int countnerOfFiles = 0;
        string test = "";
        if (INVALID_HANDLE_VALUE != hFind)
        {
            do
            {
                countnerOfFiles++;
                wstring ws(&wfd.cFileName[0]);
                string str(ws.begin(), ws.end());
                if (countnerOfFiles > 2) {
                    if (isTheFileEncrypted(str)) {
                        SetConsoleTextAttribute(hConsole, (WORD)((10 << 4) | 0));
                        cout << "[+]";
                        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, (WORD)((12 << 4) | 0));
                        cout << "[-]";
                        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
                    }
                    cout << str << endl;
                }
            } while (NULL != FindNextFileW(hFind, &wfd));

            FindClose(hFind);
        }
        else {
            cout << "================== Critical error opening directory with files! ==================" << endl;
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
            return 0;
        }
        cout << "========= Search completed successfully. Total files found "; 
        SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
        cout << " " << countnerOfFiles << " ";
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
        cout << "   || Use 'help' for more information =" << endl;
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        return 1;
    
}

bool encript() {
    std::fstream fs(L"E:\\q.txt", std::ios::in | std::ios::binary);
    if (fs.is_open())
    {
        char byte;
        fs.read(&byte, sizeof(char));
        cout << byte << (int)byte << endl;
        fs.read(&byte, sizeof(char));
        cout << byte << (int)byte << endl;
        fs.close();

    }
    return 0;
}

void menu() {
    string enteredString = "";
    while (1) {
        cin >> enteredString;
        string twoСommandСharacters = "";
        twoСommandСharacters = twoСommandСharacters + (1, enteredString[0]) + (1, enteredString[1]);
        char thirdCharacterOfTheCommand = ' ';
        thirdCharacterOfTheCommand = (1, enteredString[2]);

        /*cout << twoСommandСharacters << endl;
        cout << thirdCharacterOfTheCommand << endl;*/
        if (enteredString == "help" || enteredString == "sos") {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
            cout << "=============================================== HELP =================================================" << endl;
            cout << ">> сd - change directory         || Example: 'cdexample'  -  move to 'example' directory from the original" << endl;
            cout << ">                                || Example: 'cd" << ((char)92) <<"'  -  go to the root directory, to the drive" << endl;
            cout << ">                                || Example: 'cd.'  -  go one directory back" << endl;
            cout << ">                                || Example: 'cd!C'  -  change drive to 'C:'" << endl;
            cout << ">                                || Example: 'cd'  -  show where you are" << endl;
            cout << ">                                || Example: 'cd*C:"<< ((char)92) <<"Users'  -  specify the path manually" << endl;
            cout << ">> s - search files in directory || Example: 's.txt'  -  search only .txt files and get info about them" << endl;
            cout << ">                                || Example: 's'  -  search all files and get info about them" << endl;
            cout << ">> fd - fully destroy            || Example: 'fdtest.txt'  -  fully destroy information in file 'test.txt'" << endl;
            cout << ">> e - encrypt                   || Example: 'etest.txt'  -  encrypt the file using password" << endl;
            cout << ">                                || Example: 'e.txt'  -  encrypt all files of extension .txt" << endl;
            cout << ">                                || Example: 'e.'  -  encrypt all files in directory" << endl;
            cout << ">> rp - remember password        || Example: 'rp1a2B_+'  -  keep the password valid for this session " << endl;
            cout << ">> fp - forget  password         || Example: 'fp'  -  forget the entered password" << endl;
            cout << ">> d - decipher                  || Example: 'dtest.txt'  -  decrypt file using password " << endl;
            cout << ">                                || Example: 'd.txt'  -  decrypt all files of extension .txt" << endl;
            cout << ">                                || Example: 'd.'  -  decrypt all files in directory" << endl;
            cout << ">> of - open the file            || Example: 'oftest.txt'  -  open the file with the default program" << endl;
            cout << "============================================= V0.1 Beta ==============================================" << endl;
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        }
        else if (twoСommandСharacters == "cd") {
            //cout << "here" << (int)thirdCharacterOfTheCommand << "!" << endl;
            if (thirdCharacterOfTheCommand == ((char)92) ) {
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
                cout << "Last directory: " << directory << endl;
                string newDirectory = "";
                for (int i = 0; i < 3; i++) {
                    newDirectory = newDirectory + directory[i];
                }
                cout << "New directory: " << newDirectory << endl;
                directory = newDirectory;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
            }
            else if (thirdCharacterOfTheCommand == '.') {
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
                int markerOfSeparator = 0;
                for (int i = directory.length(); i > 2; i--) {
                    if (directory[i] == ((char)92)) {
                        markerOfSeparator = i;
                        break;
                    }
                    
                }
                if (markerOfSeparator == 0) {
                    cout << "Error! We are already in the root directory " << endl;
                }
                else {
                    string newDirectory = "";
                    for (int i = 0; i < markerOfSeparator; i++) {
                        newDirectory = newDirectory + directory[i];
                    }
                    directory = newDirectory;
                }
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
            }
            else if (thirdCharacterOfTheCommand == ((char)0)) {
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
                cout << "Directory: " << directory << endl;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
            }
            else if (thirdCharacterOfTheCommand == '!') {
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
                char newDrive;
                newDrive = (char)enteredString[3];
                if (((int)newDrive) > 96 && ((int)newDrive) < 123) {
                    newDrive = (char)((int)newDrive - (97 - 65));
                }
                if (((int)newDrive > 64 && ((int)newDrive) < 91)) {
                    string newDirectory = "";
                    newDirectory = newDrive;
                    newDirectory = newDirectory + ":" + ((char)92);
                    cout << "Last directory: " << directory << endl;
                    directory = newDirectory;
                }
                else {
                    cout << "Error! Invalid name of drive!" << endl;
                }
                cout << "New directory: " << directory << endl;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
            }
            else if (thirdCharacterOfTheCommand == '*') {
                string newDirectory = "";
                for (int i = 3; i < enteredString.length(); i++) {
                    newDirectory = newDirectory + enteredString[i];
                }
                directory = newDirectory;
            }
            else {
                string newFolder = "";
                for (int i = 2; i < enteredString.length(); i++) {
                    newFolder = newFolder + enteredString[i];
                }
                directory = directory + ((char)92) + newFolder;
            }
        }
        ////////////////////////////////////////////////////////////////////////
        if (twoСommandСharacters == "s") {
            if (thirdCharacterOfTheCommand == '.') {
                string fileExtension = "";
               
            }
        }
        
    }
//cout << ">> ad -  automatic decipher      || Example 'ad test.txt'  -  decrypt the file with the saved key" << endl;
//cout << ">> ae - automatic encrypt        || Example 'ae test.txt'  -  automatic file encryption with the selected key" << endl;
//cout << ">> ss - save settings            || Example 'ss'  -  create a sherlock settings file in the working directory" << endl;
// cout << ">> ds - delete settings          || Example 'ss'  -  delete a sherlock settings file in the working directory" << endl;   

    /*
    string newNextFolder = "";
                for (int i = 3; i < enteredString.length(); i++) {
                    newNextFolder = newNextFolder + enteredString[i];
                }
                cout << newNextFolder << endl;*/
    
}

int main()
{
    logoInit(logoWay);  
    fileCheked();
    menu();
    system("pause");
}
