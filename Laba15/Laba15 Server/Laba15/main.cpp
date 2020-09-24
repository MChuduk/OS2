#include <iostream>
#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

void task1();
void task2();
void task3();

int main(void)
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
    int retVal;
    WORD sockVer;
    WSADATA wsaData;
    sockVer = MAKEWORD(2, 2);
    WSAStartup(sockVer, &wsaData);

    SOCKADDR_IN sin;
    sin.sin_family = PF_INET;
    sin.sin_port = htons(1111);
    sin.sin_addr.s_addr = INADDR_ANY;

    //������� �����
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (servSock == SOCKET_ERROR)
    {
        std::cout << "������ �������� ������." << std::endl;
        WSACleanup();
        return;
    }

    retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));

    //�������� ������ ������� �����
    retVal = listen(servSock, 10);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "������ ��������� ������� �� �����������." << std::endl;
        WSACleanup();
        return;
    }
    //���� �������
    SOCKET clientSock;

    clientSock = accept(servSock, NULL, NULL);

    if (clientSock == INVALID_SOCKET)
    {
        std::cout << "������ ����������� � �������" << std::endl;
        WSACleanup();
        return;
    }

    while (true)
    {
        char recStr[80];

        retVal = recv(clientSock, recStr, sizeof(recStr), 0);

        if (retVal == SOCKET_ERROR)
        {
            std::cout << "������ ��������� ���������" << std::endl;
            return;
        }
        std::cout << "���������� ���������: " << recStr << std::endl;

        if (!strcmp(recStr, "exit"))
            break;
    }

    //��������� �����
    closesocket(clientSock);
    closesocket(servSock);
    WSACleanup();
}

void task2() 
{
    int retVal;
    WORD sockVer;
    WSADATA wsaData;
    sockVer = MAKEWORD(2, 2);
    WSAStartup(sockVer, &wsaData);

    SOCKADDR_IN sin;
    sin.sin_family = PF_INET;
    sin.sin_port = htons(1111);
    sin.sin_addr.s_addr = INADDR_ANY;

    //������� �����
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (servSock == SOCKET_ERROR)
    {
        std::cout << "������ �������� ������." << std::endl;
        WSACleanup();
        return;
    }

    retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));

    //�������� ������ ������� �����
    retVal = listen(servSock, 10);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "������ ��������� ������� �� �����������." << std::endl;
        WSACleanup();
        return;
    }
    //���� �������
    SOCKET clientSock;

    clientSock = accept(servSock, NULL, NULL);

    if (clientSock == INVALID_SOCKET)
    {
        std::cout << "������ ����������� � �������" << std::endl;
        WSACleanup();
        return;
    }

    char msg[80] = "��������� �� �������";

    retVal = send(clientSock, msg, sizeof(msg), 0);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "������ �������� ���������" << std::endl;
        return;
    }
    system("pause");
    //��������� �����
    closesocket(clientSock);
    closesocket(servSock);
    WSACleanup();
}

void task3() 
{
    int retVal;
    WORD sockVer;
    WSADATA wsaData;
    sockVer = MAKEWORD(2, 2);
    WSAStartup(sockVer, &wsaData);

    SOCKADDR_IN sin;
    sin.sin_family = PF_INET;
    sin.sin_port = htons(1111);
    sin.sin_addr.s_addr = INADDR_ANY;

    //������� �����
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (servSock == SOCKET_ERROR)
    {
        std::cout << "������ �������� ������." << std::endl;
        WSACleanup();
        return;
    }

    retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));

    //�������� ������ ������� �����
    retVal = listen(servSock, 10);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "������ ��������� ������� �� �����������." << std::endl;
        WSACleanup();
        return;
    }
    //���� �������
    SOCKET clientSock;

    clientSock = accept(servSock, NULL, NULL);

    if (clientSock == INVALID_SOCKET)
    {
        std::cout << "������ ����������� � �������" << std::endl;
        WSACleanup();
        return;
    }

    char recStr[80];
    recv(clientSock, recStr, sizeof(recStr), 0);
    std::cout << "��������: " << recStr << std::endl;
    Sleep(5000);
    send(clientSock, recStr, sizeof(recStr), 0);
    std::cout << "����������: " << recStr << std::endl;
    Sleep(5000);
    recv(clientSock, recStr, sizeof(recStr), 0);
    std::cout << "��������: " << recStr << std::endl;
    system("pause");


    //��������� �����
    closesocket(clientSock);
    closesocket(servSock);
    WSACleanup();
}
