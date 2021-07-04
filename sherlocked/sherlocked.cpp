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
#include <windows.h>
#include <stdio.h>

#include <iostream>
#include <string>

#include "Windows.h"
#include <stdio.h>

#include <chrono>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>

#include <cstring>

#include <sys/types.h>
#include <sys/stat.h>
#ifndef WIN32
#include <unistd.h>
#endif

#ifdef WIN32
#define stat _stat
#endif

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //do not touch! init a colored string!

const string logoWay = "../logo.txt";
const char encryptionToken[8] = {'S','H','E','R','L','O','C','K',};
const char destroyToken[8] = {'D','E','S','T','R','O','Y','!', };
const char settingsToken[8] = {'S','E','T','T','I','N','G','S', };
const int GMT = 3; //(summer Ukraine)
string directory = "";
int maxMemoryUsage = 0;
TCHAR buffer[MAX_PATH];
string password = "";

boolean createJunkFiles() {
    system("fsutil file createnew E:\File.txt 600");
    return 0;
}

string UNIXtoDate(long int seconds) {

    // Save the time in Human
    // readable format
    string ans = "";

    // Number of days in month
    // in normal year
    int daysOfMonth[] = { 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };

    long int currYear, daysTillNow, extraTime,
        extraDays, index, date, month, hours,
        minutes, secondss, flag = 0;

    // Calculate total days unix time T
    daysTillNow = seconds / (24 * 60 * 60);
    extraTime = seconds % (24 * 60 * 60);
    currYear = 1970;

    // Calculating currrent year
    while (daysTillNow >= 365) {
        if (currYear % 400 == 0
            || (currYear % 4 == 0
                && currYear % 100 != 0)) {
            daysTillNow -= 366;
        }
        else {
            daysTillNow -= 365;
        }
        currYear += 1;
    }

    // Updating extradays because it
    // will give days till previous day
    // and we have include current day
    extraDays = daysTillNow + 1;

    if (currYear % 400 == 0
        || (currYear % 4 == 0
            && currYear % 100 != 0))
        flag = 1;

    // Calculating MONTH and DATE
    month = 0, index = 0;
    if (flag == 1) {
        while (true) {

            if (index == 1) {
                if (extraDays - 29 < 0)
                    break;
                month += 1;
                extraDays -= 29;
            }
            else {
                if (extraDays
                    - daysOfMonth[index]
                    < 0) {
                    break;
                }
                month += 1;
                extraDays -= daysOfMonth[index];
            }
            index += 1;
        }
    }
    else {
        while (true) {

            if (extraDays
                - daysOfMonth[index]
                < 0) {
                break;
            }
            month += 1;
            extraDays -= daysOfMonth[index];
            index += 1;
        }
    }

    // Current Month
    if (extraDays > 0) {
        month += 1;
        date = extraDays;
    }
    else {
        if (month == 2 && flag == 1)
            date = 29;
        else {
            date = daysOfMonth[month - 1];
        }
    }

    // Calculating HH:MM:YYYY
    hours = extraTime / 3600;
    minutes = (extraTime % 3600) / 60;
    secondss = (extraTime % 3600) % 60;

    ans += to_string(date);
    ans += " ";
    switch (month)
    {
    case 1: ans += "Jan"; break;
    case 2: ans += "Feb"; break;
    case 3: ans += "Mar"; break;
    case 4: ans += "Apr"; break;
    case 5: ans += "May"; break;
    case 6: ans += "June";break;
    case 7: ans += "July";break;
    case 8: ans += "Aug"; break;
    case 9: ans += "Sept";break;
    case 10:ans += "Oct"; break;
    case 11:ans += "Nov"; break;
    case 12:ans += "Dec"; break;
    }
    
    ans += " ";
    if (hours < 10) {
        ans += "0" + to_string(hours);
    } else{
        ans += to_string(hours);
    }
    ans += ":";
    if (minutes < 10) {
        ans += "0" + to_string(minutes);
    }
    else {
        ans += to_string(minutes);
    }
    ans += ":";
    if(secondss < 10){
        ans += "0" + to_string(secondss);
    }
    else {
        ans += to_string(secondss);
    }
    ans += " " + to_string(currYear);
    
    // Return the time
    return ans;
}

boolean getInfo(string fileName, string& fileSize, string& dateCreation, string& dateMode) {
    string watchedDirectory = directory + ((char)92) + fileName;
    bool doesOpen = false;

    ifstream in_file;
    in_file.open(watchedDirectory, ios::binary);
    if (!in_file.is_open()) {
        doesOpen = false;
        return doesOpen;
    }
    else {
        doesOpen = true;
    }
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
    in_file.seekg(0, ios::end);
    int file_size = in_file.tellg();
    fileSize = to_string(file_size);
    char watchedDirectoryCharType[1024];
    strcpy(watchedDirectoryCharType, watchedDirectory.c_str());
    struct stat t_stat;
    stat(watchedDirectoryCharType, &t_stat);
    struct tm* timeinfo = localtime(&t_stat.st_ctime); 
    dateCreation = asctime(timeinfo);
    struct stat result;
    __time64_t mod_time;
    if (stat(watchedDirectory.c_str(), &result) == 0)
    {
        mod_time = result.st_mtime;
    }
    dateMode = UNIXtoDate(mod_time+(GMT*3600));
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
    return doesOpen;
}

int isTheFileEncrypted(string fileName) {
    char readIndicator[8];
    if ((fileName.find(".") < 100 )&&(fileName.find(".") >= 1 )) {
        string watchedDirectory = directory + ((char)92) + fileName;
        //cout << watchedDirectory << endl;
        ifstream openFile(watchedDirectory);
        if (!openFile) return -1; //if do not open
        openFile.get(readIndicator, 8);
        int e = 0;
        int d = 0;
        int s = 0;
        for (int i = 0; i < 8; i++) {
            if (readIndicator[i] == encryptionToken[i]) e++;
        }
        for (int i = 0; i < 8; i++) {
            if (readIndicator[i] == destroyToken[i]) d++;
        }
        for (int i = 0; i < 8; i++) {
            if (readIndicator[i] == settingsToken[i]) s++;
        }
        //cout << d << ": destroy cpuntner!" << endl;
        if (e == 7) {
            return 1;
        }
        else if (d == 7) {
           return 2;
        }
        else if (s == 7) {
            return 3;
        }
        else {
            return 0;
        }
    }
    else {
        return -1;
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

boolean fileCheked(string fileExtension) {
    string watchedDirectory = "";
       /* GetModuleFileName(NULL, buffer, sizeof(buffer) / sizeof(buffer[0])); 
        GetCurrentDirectory(sizeof(buffer), buffer);
        wstring wstringBuffer(&buffer[0]); //convert to wstring
        string dir(wstringBuffer.begin(), wstringBuffer.end()); //and convert to string.
        watchedDirectory = dir;
        directory = dir;*/
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
        cout << "=============================== Searches for files in the directory =================================" << endl;
        WIN32_FIND_DATAW wfd;
        watchedDirectory = directory;
        watchedDirectory = watchedDirectory + ((char)92)  + "*";
        //cout <<watchedDirectory << " :Directory" << endl;
        wstring wstr(watchedDirectory.begin(), watchedDirectory.end());
        LPCWSTR wide_string;
        wide_string = wstr.c_str();
        HANDLE const hFind = FindFirstFileW(wide_string, &wfd); //chose the dir
        setlocale(LC_ALL, "");
        int countnerOfFiles = 0;
        int countnerOfVisibleFiles = 0;
        string test = "";
        if (INVALID_HANDLE_VALUE != hFind)
        {
            do
            {
                string fileExtensionBeingViewed = "";
                countnerOfFiles++;
                wstring ws(&wfd.cFileName[0]);
                string str(ws.begin(), ws.end());
                int markerOfDot = 0;
                for (int i = str.length(); i > 0; i--) {
                    if (str[i] == '.') {
                        markerOfDot = i;
                    }
                }
                if (countnerOfFiles > 2) {
                    for (int i = markerOfDot; i < str.length(); i++) {
                        string test1 = "";
                        test1 = str[i];
                        fileExtensionBeingViewed = fileExtensionBeingViewed + test1;
                    }
                }
                if ((fileExtension == fileExtensionBeingViewed) || (fileExtension == ".")) {
                    if (countnerOfFiles > 2) {
                        if (isTheFileEncrypted(str) == 1) {
                            SetConsoleTextAttribute(hConsole, (WORD)((10 << 4) | 0));
                            cout << "[+]";
                            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
                            countnerOfVisibleFiles++;
                        }
                        else if (isTheFileEncrypted(str) == 0) {
                            SetConsoleTextAttribute(hConsole, (WORD)((12 << 4) | 0));
                            cout << "[-]";
                            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
                            countnerOfVisibleFiles++;
                        }
                        else if (isTheFileEncrypted(str) == 2) {
                            SetConsoleTextAttribute(hConsole, (WORD)((14 << 4) | 0));
                            cout << "[D]";
                            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
                            countnerOfVisibleFiles++;

                        }
                        else if (isTheFileEncrypted(str) == 3) {
                            SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | 15));
                            cout << "[S]";
                            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
                            countnerOfVisibleFiles++;

                        }
                        else if (isTheFileEncrypted(str) == -1) {
                            cout << "   ";
                        }
                        cout << str << endl;
                    }
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
        cout << " " << (countnerOfVisibleFiles) << " ";
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
        cout << "   || Use ";
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14)); //--
        cout << "'help'";
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));
        cout << " for more information = " << endl;
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

void usedDirectory() {
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
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
}

void infoAboutMemory(){
#define DIV 1024
#define divisor "K"
#define WIDTH 7
    MEMORYSTATUS stat;
    GlobalMemoryStatus(&stat);
   /* printf("The MemoryStatus structure is %ld bytes long.\n",
        stat.dwLength);
    printf("It should be %d.\n", sizeof(stat));*/
    cout << endl;
    if (stat.dwLength == sizeof(stat)) {cout << "Initialization of the RAM buffer is successful!" << endl;}
    else {cout << "RAM buffer initialization failed" << endl;}
    cout << "The MemoryStatus structure is: " << stat.dwLength << endl;
   /* printf("%ld percent of memory is in use.\n",
        stat.dwMemoryLoad);
    printf("There are %*ld total %sbytes of physical memory.\n",
        WIDTH, stat.dwTotalPhys / DIV, divisor);
    printf("There are %*ld free %sbytes of physical memory.\n",
        WIDTH, stat.dwAvailPhys / DIV, divisor);
    printf("There are %*ld total %sbytes of paging file.\n",
        WIDTH, stat.dwTotalPageFile / DIV, divisor);
    printf("There are %*ld free %sbytes of paging file.\n",
        WIDTH, stat.dwAvailPageFile / DIV, divisor);
    printf("There are %*lx total %sbytes of virtual memory.\n",
        WIDTH, stat.dwTotalVirtual / DIV, divisor);
    printf("There are %*lx free %sbytes of virtual memory.\n",
        WIDTH, stat.dwAvailVirtual / DIV, divisor);*/
    cout << "Maximum file size for operations: " << (WIDTH, stat.dwAvailPhys / DIV) << " kilobyte" << endl;
}

int getDiskFreeSpacePercentage()
{
    DWORD lpSectorsPerCluster,
        lpBytesPerSector,
        lpNumberOfFreeClusters,
        lpTotalNumberOfClusters;

    if (GetDiskFreeSpace(NULL,
        &lpSectorsPerCluster,
        &lpBytesPerSector,
        &lpNumberOfFreeClusters,
        &lpTotalNumberOfClusters))
    {
        return int(double(lpNumberOfFreeClusters) / double(lpTotalNumberOfClusters) * 100.0);
    }
    else
    {
        return 0;
    }
}

void uknowCommand() {
    SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
    cout << "Uknow command!";
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
    cout << endl;
}


void menu() {
    string enteredString = "";
    while (1) {
        getline(cin, enteredString);
        string twoСommandСharacters = "";
        twoСommandСharacters = twoСommandСharacters + (1, enteredString[0]) + (1, enteredString[1]);
        char thirdCharacterOfTheCommand = ' ';
        char fourthCharacterOfTheCommand = ' ';
        if(enteredString.length() >= 2) thirdCharacterOfTheCommand = (1, enteredString[2]);
        if(enteredString.length() >= 3) fourthCharacterOfTheCommand = (1, enteredString[3]);

        /*cout << twoСommandСharacters << endl;
        cout << thirdCharacterOfTheCommand << endl;*/
        if (enteredString == "help" || enteredString == "sos") {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
            cout << "=============================================== HELP =================================================" << endl;
            cout << ">> сd - change directory         || Example: 'cd example'  -  move to 'example' directory from the original" << endl; //
            cout << ">                                || Example: 'cd " << ((char)92) << "'  -  go to the root directory, to the drive" << endl; // 
            cout << ">                                || Example: 'cd ..'  -  go one directory back" << endl; // 
            cout << ">                                || Example: 'cd C:'  -  change drive to 'C:'" << endl; //
            cout << ">                                || Example: 'cd'  -  show where you are" << endl; //
            cout << ">                                || Example: 'cd C:" << ((char)92) << "Users'  -  specify the path manually" << endl; // 
            cout << ">> ls - search files in directory|| Example: 'ls .txt'  -  search only .txt files and get info about them" << endl; //
            cout << ">                                || Example: 'ls'  -  search all files and get info about them" << endl; //
            cout << ">> ef - encrypt file(s)          || Example: 'ef test.txt'  -  encrypt the file using password" << endl;
            cout << ">                                || Example: 'ef .txt'  -  encrypt all files of extension .txt" << endl;
            cout << ">                                || Example: 'ef .'  -  encrypt all files in directory" << endl;
            cout << ">> df - decipher file(s)         || Example: 'df test.txt'  -  decrypt file using password " << endl;
            cout << ">                                || Example: 'df .txt'  -  decrypt all files of extension .txt" << endl;
            cout << ">                                || Example: 'df .'  -  decrypt all files in directory" << endl;
            cout << ">> rp - remember password        || Example: 'rp 1a2B_+'  -  keep the '1a2B_+' password valid for this session " << endl; //
            cout << ">> fp - forget  password         || Example: 'fp'  -  forget the entered password" << endl; //
            cout << ">> of - open the file            || Example: 'of test.txt'  -  open the file with the default program" << endl;//
            cout << ">> gi - get info                 || Example: 'gi test.txt'  -  get info about test.txt file" << endl; //
            cout << ">> exit                          || Example: 'exit'  -  close the programm" << endl; //
            cout << ">> df - delete file              || Example: 'df test.txt'  -  delete test.txt file" << endl; //
            cout << ">> fs - free space               || Example: 'fs'  -  free space in directory" << endl; //
            cout << ">> rt - remove  all traces       || Example: 'rt'  -  remove traces in a directory" << endl;
            cout << ">> settings                      || Example: 'settings'  -  program settings " << endl;
            cout << "============================================= V0.1 Beta ==============================================" << endl;
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        }
        else if (twoСommandСharacters == "cd") {
            if (enteredString.length() > 3 && enteredString[3] == ((char)92)) {
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
            else if (enteredString.length() > 3 && enteredString[3] == '.' && enteredString[4] == '.') {
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
            else if (enteredString.length() > 1 && enteredString[2] == ((char)0)) {
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
                cout << "Directory: " << directory << endl;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
            }
            else if (enteredString.length() > 3 && enteredString[4] == ':' && enteredString.length() < 6) {
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
            else if (enteredString.length() > 3 && enteredString[4] == ':' && enteredString[5] == char(92)) { 
                string newDirectory = "";
                for (int i = 3; i < enteredString.length(); i++) {
                    newDirectory = newDirectory + enteredString[i];
                }
                directory = newDirectory;
            }
            else if (enteredString.length() > 1 && enteredString[2] == ' ' && enteredString[4] != ':') {
                string newFolder = "";
                for (int i = 3; i < enteredString.length(); i++) {
                    newFolder = newFolder + enteredString[i];
                }
                directory = directory + ((char)92) + newFolder;
            }
            else {
                uknowCommand();
            }
        }
        ////////////////////////////////////////////////////////////////////////
        if (enteredString[0] == 'l' && enteredString[1] == 's') {
            if (enteredString.length() < 3) {
                enteredString = enteredString + " .";
            }
            if (enteredString[3] == '.') {
                string fileExtension = "";
                for (int i = 3; i < enteredString.length(); i++) {
                    fileExtension = fileExtension + enteredString[i];
                }
                fileCheked(fileExtension);
            }
            else { uknowCommand(); }
        }
        //else { uknowCommand(); }
        ///////////////////////////////////////////////////////////////////////
        if (enteredString[0] == 'g' && enteredString[1] == 'i') {
            string fileName = "";
            for (int i = 3; i < enteredString.length(); i++) {
                fileName = fileName + enteredString[i];
            }
            string fileSize = "";
            string dateCreation = "";
            string dateMode = "";
            bool fileOpenForGetInfo = getInfo(fileName, fileSize, dateCreation, dateMode);
            if (!fileOpenForGetInfo) {
                SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
                cout << "File opening or recognition error!";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                cout << "\n";
            }
            else {
                SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 15));
                cout << "The file was successfully recognized and opened!";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                cout << "\n";
            }
            if (fileOpenForGetInfo) {
                dateCreation = "Date of creation file: " + dateCreation;
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
                cout << fileSize << " bytes file size \n" << dateCreation << "Date of modification file: " << dateMode << "\n";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
            }
        }
        if (enteredString == "exit") {
            exit(0);
        }
        if (enteredString[0] == 'd' && enteredString[1] == 'f') {
            string fileName = "";
            for (int i = 3; i < enteredString.length(); i++) {
                fileName = fileName + enteredString[i];
            }
            fileName = directory + char(92) + fileName;
            char* fileLocationToDelete = new char[fileName.size() + 1];
            copy(fileName.begin(), fileName.end(), fileLocationToDelete);
            fileLocationToDelete[fileName.size()] = '\0'; // don't forget the terminating 0
            if (!remove(fileLocationToDelete)) {
                SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 15));
                cout << "The selected file has been successfully deleted!";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                cout << "\n";
            }
            else {
                SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
                cout << "Failed to delete the selected file!";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                cout << "\n";
            }
        }
        if (enteredString[0] == 'o' && enteredString[1] == 'f') {
            string fileName = "";
            for (int i = 3; i < enteredString.length(); i++) {
                fileName = fileName + enteredString[i];
            }
            char* fileToOpen = new char[fileName.size() + 1];
            copy(fileName.begin(), fileName.end(), fileToOpen);
            fileToOpen[fileName.size()] = '\0'; // don't forget the terminating 0
            system(fileToOpen);
        }
        if (enteredString[0] == 'r' && enteredString[1] == 'p') {
            password = "";
            for (int i = 3; i < enteredString.length(); i++) {
                password = password + enteredString[i];
            }
            if ((enteredString.length() - 3) == password.length()) {
                SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 15));
                cout << "Your password has been successfully written!";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                cout << "\n";
            }
            else {
                SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
                cout << "Password write error !";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                cout << "\n";
            }
        }
        if (enteredString[0] == 'f' && enteredString[1] == 'p') {
            password = "";
            if (password.length() == 0) {
                SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 15));
                cout << "Your password has been successfully forgotten!";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                cout << "\n";
            }
            else {
                SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
                cout << "Password forgotten error !";
                SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                cout << "\n";
            }
        }
        if (enteredString[0] == 'f' && enteredString[1] == 's') {
            ULARGE_INTEGER liFreeBytesAvailable;
            ULARGE_INTEGER liTotalNumberOfBytes;
            ULARGE_INTEGER liTotalNumberOfFreeBytes;
            string watchedDirectory = "";
            for (int i = 0; i < 3; i++) {
                watchedDirectory = watchedDirectory + directory[i];
            }
            watchedDirectory = watchedDirectory + (char(92));
            wstring wWatchedDirectory(watchedDirectory.begin(), watchedDirectory.end());
            const wchar_t* wCharWatchedDirectory = wWatchedDirectory.c_str();
            ::GetDiskFreeSpaceEx((wCharWatchedDirectory),              
                &liFreeBytesAvailable,      // bytes available to caller
                &liTotalNumberOfBytes,      // bytes on disk
                &liTotalNumberOfFreeBytes); // free bytes on disk

            const LONGLONG nKBFactor = 1024;            
            const LONGLONG nMBFactor = nKBFactor * 1024;
            const LONGLONG nGBFactor = nMBFactor * 1024; 

            // get free space in KB.
            long int dKBFreSpace
                = (double)(LONGLONG)liTotalNumberOfFreeBytes.QuadPart / nKBFactor;
            // get free space in MB.
            double dMBFreSpace
                = (double)(LONGLONG)liTotalNumberOfFreeBytes.QuadPart / nMBFactor;
            // get free space in GB.
            double dGBFreSpace
                = (double)(LONGLONG)liTotalNumberOfFreeBytes.QuadPart / nGBFactor;
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
            cout << "Free disk space '" << watchedDirectory[0] << ":'" << endl;
            cout << dKBFreSpace << " KB of free space \n" << dMBFreSpace << " MB of free space \n" << dGBFreSpace << " GB of free space \n";
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        }
        if (enteredString[0] == 'r' && enteredString[1] == 't') {
            string watchedDirectory = "";
            createJunkFiles();
        }
    }
}

int main()
{
    logoInit(logoWay);  
    usedDirectory();
    infoAboutMemory();
    fileCheked("."); //all files
    menu();
    system("pause");
}
