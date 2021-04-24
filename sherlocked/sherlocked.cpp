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

boolean creatingStreamsOfCacheFiles(string watchedDirectory, int streamsQuantity, int fileSize) {
    ofstream cache0(watchedDirectory + char(92) + "name0");
    ofstream cache1(watchedDirectory + char(92) + "name1");
    ofstream cache2(watchedDirectory + char(92) + "name2");
    ofstream cache3(watchedDirectory + char(92) + "name3");
    ofstream cache4(watchedDirectory + char(92) + "name4");
    ofstream cache5(watchedDirectory + char(92) + "name5");
    ofstream cache6(watchedDirectory + char(92) + "name6");
    ofstream cache7(watchedDirectory + char(92) + "name7");
    ofstream cache8(watchedDirectory + char(92) + "name8");
    ofstream cache9(watchedDirectory + char(92) + "name9");
    ofstream cache10(watchedDirectory + char(92) + "name10");
    ofstream cache11(watchedDirectory + char(92) + "name11");
    ofstream cache12(watchedDirectory + char(92) + "name12");
    ofstream cache13(watchedDirectory + char(92) + "name13");
    ofstream cache14(watchedDirectory + char(92) + "name14");
    ofstream cache15(watchedDirectory + char(92) + "name15");
    ofstream cache16(watchedDirectory + char(92) + "name16");
    ofstream cache17(watchedDirectory + char(92) + "name17");
    ofstream cache18(watchedDirectory + char(92) + "name18");
    ofstream cache19(watchedDirectory + char(92) + "name19");
    ofstream cache20(watchedDirectory + char(92) + "name20");
    ofstream cache21(watchedDirectory + char(92) + "name21");
    ofstream cache22(watchedDirectory + char(92) + "name22");
    ofstream cache23(watchedDirectory + char(92) + "name23");
    ofstream cache24(watchedDirectory + char(92) + "name24");
    ofstream cache25(watchedDirectory + char(92) + "name25");
    ofstream cache26(watchedDirectory + char(92) + "name26");
    ofstream cache27(watchedDirectory + char(92) + "name27");
    ofstream cache28(watchedDirectory + char(92) + "name28");
    ofstream cache29(watchedDirectory + char(92) + "name29");
    ofstream cache30(watchedDirectory + char(92) + "name30");
    ofstream cache31(watchedDirectory + char(92) + "name31");
    ofstream cache32(watchedDirectory + char(92) + "name32");
    ofstream cache33(watchedDirectory + char(92) + "name33");
    ofstream cache34(watchedDirectory + char(92) + "name34");
    ofstream cache35(watchedDirectory + char(92) + "name35");
    ofstream cache36(watchedDirectory + char(92) + "name36");
    ofstream cache37(watchedDirectory + char(92) + "name37");
    ofstream cache38(watchedDirectory + char(92) + "name38");
    ofstream cache39(watchedDirectory + char(92) + "name39");
    ofstream cache40(watchedDirectory + char(92) + "name40");
    ofstream cache41(watchedDirectory + char(92) + "name41");
    ofstream cache42(watchedDirectory + char(92) + "name42");
    ofstream cache43(watchedDirectory + char(92) + "name43");
    ofstream cache44(watchedDirectory + char(92) + "name44");
    ofstream cache45(watchedDirectory + char(92) + "name45");
    ofstream cache46(watchedDirectory + char(92) + "name46");
    ofstream cache47(watchedDirectory + char(92) + "name47");
    ofstream cache48(watchedDirectory + char(92) + "name48");
    ofstream cache49(watchedDirectory + char(92) + "name49");
    ofstream cache50(watchedDirectory + char(92) + "name50");
    ofstream cache51(watchedDirectory + char(92) + "name51");
    ofstream cache52(watchedDirectory + char(92) + "name52");
    ofstream cache53(watchedDirectory + char(92) + "name53");
    ofstream cache54(watchedDirectory + char(92) + "name54");
    ofstream cache55(watchedDirectory + char(92) + "name55");
    ofstream cache56(watchedDirectory + char(92) + "name56");
    ofstream cache57(watchedDirectory + char(92) + "name57");
    ofstream cache58(watchedDirectory + char(92) + "name58");
    ofstream cache59(watchedDirectory + char(92) + "name59");
    ofstream cache60(watchedDirectory + char(92) + "name60");
    ofstream cache61(watchedDirectory + char(92) + "name61");
    ofstream cache62(watchedDirectory + char(92) + "name62");
    ofstream cache63(watchedDirectory + char(92) + "name63");
    //ofstream cache64(watchedDirectory + char(92) + "name64");
    char* buffer = new char[fileSize];
    for (int i = 0; i < fileSize; i++) {
        buffer[i] = 'I';
    }
    cout << "record\n";
    //for (int i = 0; i < 1048576; i++) {
        cache0.write(buffer, fileSize);
        cache1.write(buffer, fileSize);
        cache2.write(buffer, fileSize);
        cache3.write(buffer, fileSize);
        cache4.write(buffer, fileSize);
        cache5.write(buffer, fileSize);
        cache6.write(buffer, fileSize);
        cache7.write(buffer, fileSize);
        cache8.write(buffer, fileSize);
        cache9.write(buffer, fileSize);
        cache10.write(buffer, fileSize);
        cache11.write(buffer, fileSize);
        cache12.write(buffer, fileSize);
        cache13.write(buffer, fileSize);
        cache14.write(buffer, fileSize);
        cache15.write(buffer, fileSize);
        cache16.write(buffer, fileSize);
        cache17.write(buffer, fileSize);
        cache18.write(buffer, fileSize);
        cache19.write(buffer, fileSize);
        cache20.write(buffer, fileSize);
        cache21.write(buffer, fileSize);
        cache22.write(buffer, fileSize);
        cache23.write(buffer, fileSize);
        cache24.write(buffer, fileSize);
        cache25.write(buffer, fileSize);
        cache26.write(buffer, fileSize);
        cache27.write(buffer, fileSize);
        cache28.write(buffer, fileSize);
        cache29.write(buffer, fileSize);
        cache30.write(buffer, fileSize);
        cache31.write(buffer, fileSize);
        cache32.write(buffer, fileSize);
        cache33.write(buffer, fileSize);
        cache34.write(buffer, fileSize);
        cache35.write(buffer, fileSize);
        cache36.write(buffer, fileSize);
        cache37.write(buffer, fileSize);
        cache38.write(buffer, fileSize);
        cache39.write(buffer, fileSize);
        cache40.write(buffer, fileSize);
        cache41.write(buffer, fileSize);
        cache42.write(buffer, fileSize);
        cache43.write(buffer, fileSize);
        cache44.write(buffer, fileSize);
        cache45.write(buffer, fileSize);
        cache46.write(buffer, fileSize);
        cache47.write(buffer, fileSize);
        cache48.write(buffer, fileSize);
        cache49.write(buffer, fileSize);
        cache50.write(buffer, fileSize);
        cache51.write(buffer, fileSize);
        cache52.write(buffer, fileSize);
        cache53.write(buffer, fileSize);
        cache54.write(buffer, fileSize);
        cache55.write(buffer, fileSize);
        cache56.write(buffer, fileSize);
        cache57.write(buffer, fileSize);
        cache58.write(buffer, fileSize);
        cache59.write(buffer, fileSize);
        cache60.write(buffer, fileSize);
        cache61.write(buffer, fileSize);
        cache62.write(buffer, fileSize);
        cache63.write(buffer, fileSize);
        //cache64.write(buffer, fileSize);
        cout << ".";
    //}
    cout << "\n End) \n";
    cache0.close();
    cache1.close();
    cache2.close();
    cache3.close();
    cache4.close();
    cache5.close();
    cache6.close();
    cache7.close();
    cache8.close();
    cache9.close();
    cache10.close();
    cache11.close();
    cache12.close();
    cache13.close();
    cache14.close();
    cache15.close();
    cache16.close();
    cache17.close();
    cache18.close();
    cache19.close();
    cache20.close();
    cache21.close();
    cache22.close();
    cache23.close();
    cache24.close();
    cache25.close();
    cache26.close();
    cache27.close();
    cache28.close();
    cache29.close();
    cache30.close();
    cache31.close();
    cache32.close();
    cache33.close();
    cache34.close();
    cache35.close();
    cache36.close();
    cache37.close();
    cache38.close();
    cache39.close();
    cache40.close();
    cache41.close();
    cache42.close();
    cache43.close();
    cache44.close();
    cache45.close();
    cache46.close();
    cache47.close();
    cache48.close();
    cache49.close();
    cache50.close();
    cache51.close();
    cache52.close();
    cache53.close();
    cache54.close();
    cache55.close();
    cache56.close();
    cache57.close();
    cache58.close();
    cache59.close();
    cache60.close();
    cache61.close();
    cache62.close();
    cache63.close();
    //cache64.close();
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


void menu() {
    string enteredString = "";
    while (1) {
        getline(cin, enteredString);
        string twoСommandСharacters = "";
        twoСommandСharacters = twoСommandСharacters + (1, enteredString[0]) + (1, enteredString[1]);
        char thirdCharacterOfTheCommand = ' ';
        thirdCharacterOfTheCommand = (1, enteredString[2]);

        /*cout << twoСommandСharacters << endl;
        cout << thirdCharacterOfTheCommand << endl;*/
        if (enteredString == "help") {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
            cout << "=============================================== HELP =================================================" << endl;
            cout << ">> сd - change directory         || Example: 'cdexample'  -  move to 'example' directory from the original" << endl; //
            cout << ">                                || Example: 'cd" << ((char)92) << "'  -  go to the root directory, to the drive" << endl; //
            cout << ">                                || Example: 'cd.'  -  go one directory back" << endl; //
            cout << ">                                || Example: 'cd!C'  -  change drive to 'C:'" << endl; //
            cout << ">                                || Example: 'cd'  -  show where you are" << endl; //
            cout << ">                                || Example: 'cd*C:" << ((char)92) << "Users'  -  specify the path manually" << endl; //
            cout << ">> sf - search files in directory|| Example: 'sf.txt'  -  search only .txt files and get info about them" << endl; //
            cout << ">                                || Example: 'sf.'  -  search all files and get info about them" << endl; //
            cout << ">> fd - fully destroy            || Example: 'fdtest.txt'  -  fully destroy information in file 'test.txt'" << endl;
            cout << ">                                || Example: 'fd.txt'  -  destroy all files of extension .txt" << endl;
            cout << ">                                || Example: 'fd.'  -  destroy all files in directory" << endl;
            cout << ">> ef - encrypt file(s)          || Example: 'etest.txt'  -  encrypt the file using password" << endl;
            cout << ">                                || Example: 'ef.txt'  -  encrypt all files of extension .txt" << endl;
            cout << ">                                || Example: 'ef.'  -  encrypt all files in directory" << endl;
            cout << ">> df - decipher file(s)         || Example: 'dftest.txt'  -  decrypt file using password " << endl;
            cout << ">                                || Example: 'df.txt'  -  decrypt all files of extension .txt" << endl;
            cout << ">                                || Example: 'df.'  -  decrypt all files in directory" << endl;
            cout << ">> rp - remember password        || Example: 'rp1a2B_+'  -  keep the '1a2B_+' password valid for this session " << endl; //
            cout << ">> fp - forget  password         || Example: 'fp'  -  forget the entered password" << endl; //
            cout << ">> of - open the file            || Example: 'oftest.txt'  -  open the file with the default program" << endl;//
            cout << ">> gi - get info                 || Example: 'gitest.txt'  -  get info about test.txt file" << endl; //
            cout << ">> exit                          || Example: 'exit'  -  close the programm" << endl; //
            cout << ">> df - delete file              || Example: 'dftest.txt'  -  delete test.txt file" << endl; //
            cout << ">> fs - free space               || Example: 'fs'  -  free space in directory" << endl; //
            cout << ">> rt - remove traces            || Example: 'rt'  -  remove traces in a directory" << endl;
            cout << ">> settings                      || Example: 'settings'  -  program settings " << endl;
            cout << "============================================= V0.1 Beta ==============================================" << endl;
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        }
        else if (twoСommandСharacters == "cd") {
            //cout << "here" << (int)thirdCharacterOfTheCommand << "!" << endl;
            if (thirdCharacterOfTheCommand == ((char)92)) {
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
        if (twoСommandСharacters == "sf") {
            if (thirdCharacterOfTheCommand == '.') {
                string fileExtension = "";
                for (int i = 2; i < enteredString.length(); i++) {
                    fileExtension = fileExtension + enteredString[i];
                }
                fileCheked(fileExtension);
            }
        }
        ///////////////////////////////////////////////////////////////////////
        if (twoСommandСharacters == "gi") {
            string fileName = "";
            for (int i = 2; i < enteredString.length(); i++) {
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
        if (twoСommandСharacters == "df") {
            string fileName = "";
            for (int i = 2; i < enteredString.length(); i++) {
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
        if (twoСommandСharacters == "of") {
            string fileName = "";
            for (int i = 2; i < enteredString.length(); i++) {
                fileName = fileName + enteredString[i];
            }
            char* fileToOpen = new char[fileName.size() + 1];
            copy(fileName.begin(), fileName.end(), fileToOpen);
            fileToOpen[fileName.size()] = '\0'; // don't forget the terminating 0
            system(fileToOpen);
        }
        if (twoСommandСharacters == "rp") {
            password = "";
            for (int i = 2; i < enteredString.length(); i++) {
                password = password + enteredString[i];
            }
            if ((enteredString.length() - 2) == password.length()) {
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
        if (twoСommandСharacters == "fp") {
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
        if (twoСommandСharacters == "fs") {
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
        if (twoСommandСharacters == "rt") {
            string watchedDirectory = "";
            creatingStreamsOfCacheFiles(directory, 1, 67108864 + 67108864/2);
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
