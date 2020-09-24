#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)

void task1();
void task2();
bool IsProcessRun(TCHAR buf[]);
bool AreEqual(const TCHAR* a, const TCHAR* b);

int main()
{
    //task1();
    task2();

    return 0;
}

void task1() 
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	hFind = FindFirstFile(TEXT("E:\\Programs\\*.exe"), &FindFileData);
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	SetCurrentDirectory(TEXT("E:\\Programs"));
	CreateProcess(NULL, FindFileData.cFileName, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi);
}

void task2() 
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	hFind = FindFirstFile(TEXT("E:\\Programs\\GitHub*.exe"), &FindFileData);
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	SetCurrentDirectory(TEXT("E:\\Programs"));
	CreateProcess(NULL, FindFileData.cFileName, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi);

    if (IsProcessRun(FindFileData.cFileName) == true) 
    {
        std::wcout << "Process is running" << std::endl;
    }
    else 
    {
        std::wcout << "Process is not running" << std::endl;
    }
}

bool AreEqual(const TCHAR* a, const TCHAR* b)
{
    while (*a == *b)
    {
        if (*a == TEXT('\0'))return true;
        a++; b++;
    }
    return false;
}


bool IsProcessRun(TCHAR buf[])
{
    bool RUN;

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);
    Process32First(hSnapshot, &pe);

    if (AreEqual(pe.szExeFile, buf))
    {
        RUN = true;
        return RUN;
    }
    else
        RUN = false;
    while (Process32Next(hSnapshot, &pe))
    {
        if (AreEqual(pe.szExeFile, buf))
        {
            RUN = true;
            return RUN;
        }
        else
            RUN = false;
    }
    return RUN;
}
