//CLIENT 1
#include <windows.h>
#include <iostream>

int main()
{
	printf("Mailslot Client 1\n");

	HANDLE hMailslot;
	LPSTR  lpszMailslotName = (LPSTR)"\\\\.\\mailslot\\MyMailslot";

	DWORD WriteBytesCount;

	char buffer[256];

	hMailslot = CreateFileA(lpszMailslotName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if (hMailslot == INVALID_HANDLE_VALUE) 
	{
		printf("Mailslot open error. Error:%d\n", GetLastError());
		return 0;
	}
	printf("Mailslot is opened\n");

	//посылаем сообщения через канал
	while (true) 
	{
		printf(">>");
		std::cin >> buffer;

		BOOL writeMassegeReturnCode = WriteFile(hMailslot, buffer, strlen(buffer) + 1, &WriteBytesCount, NULL);

		if (!strcmp(buffer, "exit"))
			break;

		if (writeMassegeReturnCode == FALSE) 
		{
			printf("Write messag error. Error:%d\n", GetLastError());
			break;
		}
	}

	CloseHandle(hMailslot);
	return 0;
}