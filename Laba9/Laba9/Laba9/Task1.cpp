#include <iostream>
#include <Windows.h>

DWORD WINAPI Thread1(void* lpParameter)
{
	int* counterp = new int();
	counterp = (int*)lpParameter;
	int counter = *counterp;

	while (counter < 20)
	{
		Sleep(500);
		printf("\n\tCounter1= %d", counter);
		counter++;
	}
	return 0;
}

DWORD WINAPI Thread2(void* lpParameter)
{
	int* counterp = new int();
	counterp = (int*)lpParameter;
	int counter = *counterp;

	while (counter < 20)
	{
		Sleep(1000);
		printf("\n\tCounter2= %d", counter);
		counter++;
	}
	return 0;
}

void RunTask1() 
{
	int a = 5, b = 10;
	DWORD threadID1, threadID2;
	HANDLE handle1, handle2;
	handle1 = CreateThread(0, 0, Thread1, (void*)&a, 0, &threadID1);
	handle2 = CreateThread(0, 0, Thread2, (void*)&b, 0, &threadID2);
	Sleep(5000);
	TerminateThread(handle1, 0);
	TerminateThread(handle2, 0);
}