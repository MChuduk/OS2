#include <iostream>
#include "windows.h"

int main()
{
	////2
	//CreateDirectory(TEXT("E:\\OS\\Laba7\\Dir1"), NULL);
	//CreateDirectory(TEXT("E:\\OS\\Laba7\\Dir2"), NULL);
	//
	////3
	//HANDLE hOut;
	DWORD dwNumberOfBytes;
	//hOut = CreateFile(TEXT("E:\\OS\\Laba7\\Dir1\\file1.txt"), GENERIC_WRITE, 0, NULL, 
	//	CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//TCHAR buffer[] = TEXT("example text 1");
	//WriteFile(hOut, buffer, sizeof(buffer), &dwNumberOfBytes, NULL);
	//CloseHandle(hOut);

	////4
	//CopyFile(TEXT("E:\\OS\\Laba7\\Dir1\\file1.txt"), TEXT("E:\\OS\\Laba7\\Dir2\\file1_copy.txt"), FALSE);

	////5
	//DeleteFile(TEXT("E:\\OS\\Laba7\\Dir1\\file1.txt"));

	////6
	//MoveFile(TEXT("E:\\OS\\Laba7\\Dir2\\file1_copy.txt"), TEXT("E:\\OS\\Laba7\\Dir2\\file1_renaimed.txt"));
	char readedInfo[256];
	HANDLE hOut = CreateFile(TEXT("E:\\OS\\Laba7\\Dir2\\file1_renaimed.txt"), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(hOut, readedInfo, sizeof(readedInfo), &dwNumberOfBytes, NULL);
	std::cout << readedInfo << std::endl;
	CloseHandle(hOut);

	return 0;
}
