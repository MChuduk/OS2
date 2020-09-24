//SERVER
#include <windows.h>
#include <iostream>

int main()
{
    printf("Mailslot Server\n");

    HANDLE hMailslot;
    LPSTR lpszMailslotName = (LPSTR)"\\\\.\\mailslot\\MyMailslot";

    DWORD MsgSize;
    DWORD MsgCount;
    DWORD ReadBytesCount;

    char buffer[256];

    hMailslot = CreateMailslotA(lpszMailslotName, 0, MAILSLOT_WAIT_FOREVER, NULL);

    if (hMailslot == INVALID_HANDLE_VALUE) 
    {
        printf("Mailslot create error. Error:%d\n", GetLastError());
        return 0;
    }
    printf("Mailslot is created\n");

    //чтение сообщений из канала
    while (true) 
    {
        BOOL mailslotInfoReturnCode = GetMailslotInfo(hMailslot, NULL, &MsgSize, &MsgCount, NULL);

        if (mailslotInfoReturnCode == FALSE) 
        {
            printf("Get mailslot info error. Error:%d\n", GetLastError());
            break;
        }
        if (MsgCount != 0) 
        {
            BOOL readMsgReturnCode = ReadFile(hMailslot, buffer, sizeof(buffer), &ReadBytesCount, NULL);

            if (!strcmp(buffer, "exit"))
                break;

            if (readMsgReturnCode == TRUE) 
            {
                printf("Readed message: %s\n", buffer);
            }
            else 
            {
                printf("Read message error. Error:%d\n", GetLastError());
                break;
            }
        }
        Sleep(500);
    }

    CloseHandle(hMailslot);
    return 0;
}