#include <windows.h>
#include <iostream>

DWORD WINAPI Writer(LPVOID lpParameter);
DWORD WINAPI Reader(LPVOID lpParameter);

CRITICAL_SECTION criticalSection;

int main() 
{
	DWORD thread1Id, thread2Id;
	HANDLE thread1, thread2;

	InitializeCriticalSection(&criticalSection);

	thread1 = CreateThread(0, 0, Writer, 0, CREATE_SUSPENDED, &thread1Id);
	thread2 = CreateThread(0, 0, Reader, 0, CREATE_SUSPENDED, &thread2Id);

	ResumeThread(thread1);
	Sleep(10);
	ResumeThread(thread2);

	WaitForSingleObject(thread1, 5000);
	WaitForSingleObject(thread2, 5000);
	CloseHandle(thread1);
	CloseHandle(thread2);
	DeleteCriticalSection(&criticalSection);
	return 0;
}

DWORD WINAPI Writer(LPVOID lpParameter) 
{
	HANDLE hFile;
	DWORD dwBytesWrite = 0;
	int counter = 0;

	while (true) 
	{
		EnterCriticalSection(&criticalSection);
		hFile = CreateFile(L"E:\\OS\\Laba10\\file.txt",
			GENERIC_WRITE | GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile != INVALID_HANDLE_VALUE) 
		{
			char buffer[5] = "";
			_itoa_s(counter, buffer, 10);
			strcat_s(buffer, sizeof(buffer), "\n");
			WriteFile(hFile, buffer, strlen(buffer), &dwBytesWrite, NULL);
			std::cout << "Write file : " << buffer;
		}
		else 
		{
			std::cout << "error writing file" << std::endl;
		}
		counter++;
		LeaveCriticalSection(&criticalSection);
		Sleep(200);
	}
}

DWORD WINAPI Reader(LPVOID lpParameter) 
{
	HANDLE hFile;
	DWORD dwBytesRead = 0;

	while (true)
	{
		EnterCriticalSection(&criticalSection);
		hFile = CreateFile(L"E:\\OS\\Laba10\\file.txt",
			GENERIC_WRITE | GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile != INVALID_HANDLE_VALUE)
		{
			char readedInfo[10] = "";
			ReadFile(hFile, readedInfo, sizeof(readedInfo) - 1, &dwBytesRead, NULL);
			strcat_s(readedInfo, sizeof(readedInfo), "\0");
			std::cout << "Read file : " << readedInfo;
		}
		else
		{
			std::cout << "error reading file" << std::endl;
		}
		LeaveCriticalSection(&criticalSection);
		Sleep(200);
	}
}