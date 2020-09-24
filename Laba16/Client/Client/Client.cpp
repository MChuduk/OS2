#include <iostream>
#include <Windows.h>

int main()
{
	setlocale(LC_CTYPE, "Rus");

	HANDLE hPipe;
	DWORD dwRead;
	DWORD dwWritten;

	hPipe = CreateFile(TEXT("\\\\.\\pipe\\Pipe"), 
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

	if (hPipe != INVALID_HANDLE_VALUE)
	{
		char message[] = "Сколько тебе лет?\n";
		WriteFile(hPipe, message, strlen(message) + 1, &dwWritten, NULL);

		while (ReadFile(hPipe, message, sizeof(message) - 1, &dwRead, NULL) != FALSE)
		{
			message[dwRead] = '\0';

			std::cout << message << std::endl;
			int yaer = atoi(message);
			if (yaer < 20) 
			{
				std::cout << "Выгдлядишь неплохо" << std::endl;
			}
			else {
				std::cout << "Хороший возвраст" << std::endl;
			}
			break;
			
		}
	}
	CloseHandle(hPipe);


	system("pause");


    return 0;
}