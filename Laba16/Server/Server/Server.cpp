#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_CTYPE, "Rus");

	HANDLE hPipe;
	char buffer[1024];
	DWORD dwRead;
	DWORD dwWritten;

	hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipe"),
		PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,  
		PIPE_WAIT,
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);

	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, NULL) != FALSE)
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
			{
				buffer[dwRead] = '\0';

				char year[10];
				std::cout << buffer << std::endl;
				std::cout << "Ответ: ";
				std::cin >> year;
				WriteFile(hPipe, year, strlen(year) + 1, &dwWritten, NULL);
			}
			break;
		}
		DisconnectNamedPipe(hPipe);
	}
	system("pause");
	return 0;
}