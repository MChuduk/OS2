#include <iostream>
#include <Windows.h>

int value;

DWORD WINAPI Reader(void* lpParameter)
{
	std::wcout << "value: " << value << "\n";
	return 0;
}

DWORD WINAPI Writer(void* lpParameter)
{
	while (value < 20)
	{
		value++;
		DWORD threadID;
		HANDLE handle = CreateThread(0, 0, Reader, 0, 0, &threadID);
		Sleep(300);
	}
	return 0;
}

void RunTask2() 
{
	DWORD threadID;
	HANDLE handle = CreateThread(0, 0, Writer, 0, 0, &threadID);
	Sleep(7000);
}