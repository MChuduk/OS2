#include <iostream>
#include <stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

void task1();
void task2();
void task3();

int main()
{
    setlocale(LC_CTYPE, "Rus");
    std::cout << "������" << std::endl;

    //task1();
    //task2();
    task3();

    return 0;
}


void task1() 
{
    int retVal = 0;
    WSADATA wsaData;
    WORD ver = MAKEWORD(2, 2);
    WSAStartup(ver, (LPWSADATA)&wsaData);

    LPHOSTENT hostEnt;
    hostEnt = gethostbyname("localhost");

    SOCKADDR_IN serverInfo;
    serverInfo.sin_family = PF_INET;
    serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
    serverInfo.sin_port = htons(1111);

    //������� �����
    SOCKET clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSock == SOCKET_ERROR)
    {
        std::cout << "������ �������� ������." << std::endl;
        WSACleanup();
        return;
    }

    retVal = connect(clientSock, (LPSOCKADDR)&serverInfo, sizeof(serverInfo));

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "������ ���������� � �������." << std::endl;
        WSACleanup();
        return;
    }

    std::cout << "���������� � ������� �������." << std::endl;

    while (true)
    {
        char str[80];

        std::cout << "��������� ���������: ";
        std::cin >> str;

        retVal = send(clientSock, str, sizeof(str), 0);

        if (retVal == SOCKET_ERROR)
        {
            std::cout << "������ �������� ���������." << std::endl;
            WSACleanup();
            return;
        }

        if (!strcmp(str, "exit"))
            break;
    }
    closesocket(clientSock);
    WSACleanup();
}

void task2() 
{
    int retVal = 0;
    WSADATA wsaData;
    WORD ver = MAKEWORD(2, 2);
    WSAStartup(ver, (LPWSADATA)&wsaData);

    LPHOSTENT hostEnt;
    hostEnt = gethostbyname("localhost");

    SOCKADDR_IN serverInfo;
    serverInfo.sin_family = PF_INET;
    serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
    serverInfo.sin_port = htons(1111);

    //������� �����
    SOCKET clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSock == SOCKET_ERROR)
    {
        std::cout << "������ �������� ������." << std::endl;
        WSACleanup();
        return;
    }

    retVal = connect(clientSock, (LPSOCKADDR)&serverInfo, sizeof(serverInfo));

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "������ ���������� � �������." << std::endl;
        WSACleanup();
        return;
    }

    std::cout << "���������� � ������� �������." << std::endl;

    char str[80];
    retVal = recv(clientSock, str, sizeof(str), 0);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "������ ��������� ���������" << std::endl;
        WSACleanup();
        return;
    }
    std::cout << "���������� ���������: " << str << std::endl;
    system("pause");

    closesocket(clientSock);
    WSACleanup();
}

void task3() 
{
    int retVal = 0;
    WSADATA wsaData;
    WORD ver = MAKEWORD(2, 2);
    WSAStartup(ver, (LPWSADATA)&wsaData);

    LPHOSTENT hostEnt;
    hostEnt = gethostbyname("localhost");

    SOCKADDR_IN serverInfo;
    serverInfo.sin_family = PF_INET;
    serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
    serverInfo.sin_port = htons(1111);

    //������� �����
    SOCKET clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSock == SOCKET_ERROR)
    {
        std::cout << "������ �������� ������." << std::endl;
        WSACleanup();
        return;
    }

    retVal = connect(clientSock, (LPSOCKADDR)&serverInfo, sizeof(serverInfo));

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "������ ���������� � �������." << std::endl;
        WSACleanup();
        return;
    }

    std::cout << "���������� � ������� �������." << std::endl;

    char str[80] = "���������1337";
    send(clientSock, str, sizeof(str), 0);
    std::cout << "����������: " << str << std::endl;
    Sleep(5000);
    recv(clientSock, str, sizeof(str), 0);
    std::cout << "��������: " << str << std::endl;
    Sleep(5000);
    send(clientSock, str, sizeof(str), 0);
    std::cout << "����������: " << str << std::endl;
    system("pause");

    closesocket(clientSock);
    WSACleanup();
}