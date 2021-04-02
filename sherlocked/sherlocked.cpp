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
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
    
}

boolean fileCheked() {
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
            return 0;
        }
        cout << "======================== Search completed successfully. Total files found "; 
        SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
        cout << " " << countnerOfFiles << " ";
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
        cout << " =======================" << endl;
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
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
    cout << "=============================================== MENU =================================================" << endl;
    cout << ">>> сd - change directory  || Example: cd \source  -  move to directory \source from the original <<<" << endl;
}

int main()
{
    logoInit(logoWay);  
    fileCheked();
    menu();
    system("pause");
}
