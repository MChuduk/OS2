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
    std::cout << "СЕРВЕР" << std::endl;

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

    //Создаем сокет
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (servSock == SOCKET_ERROR)
    {
        std::cout << "Ошибка создания сокета." << std::endl;
        WSACleanup();
        return;
    }

    retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));

    //Пытаемся начать слушать сокет
    retVal = listen(servSock, 10);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "Ошибка обработки запроса на подключение." << std::endl;
        WSACleanup();
        return;
    }
    //Ждем клиента
    SOCKET clientSock;

    clientSock = accept(servSock, NULL, NULL);

    if (clientSock == INVALID_SOCKET)
    {
        std::cout << "Ошибка подключения к клиенту" << std::endl;
        WSACleanup();
        return;
    }

    while (true)
    {
        char recStr[80];

        retVal = recv(clientSock, recStr, sizeof(recStr), 0);

        if (retVal == SOCKET_ERROR)
        {
            std::cout << "Ошибка получения сообщения" << std::endl;
            return;
        }
        std::cout << "Полученное сообщение: " << recStr << std::endl;

        if (!strcmp(recStr, "exit"))
            break;
    }

    //Закрываем сокет
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

    //Создаем сокет
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (servSock == SOCKET_ERROR)
    {
        std::cout << "Ошибка создания сокета." << std::endl;
        WSACleanup();
        return;
    }

    retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));

    //Пытаемся начать слушать сокет
    retVal = listen(servSock, 10);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "Ошибка обработки запроса на подключение." << std::endl;
        WSACleanup();
        return;
    }
    //Ждем клиента
    SOCKET clientSock;

    clientSock = accept(servSock, NULL, NULL);

    if (clientSock == INVALID_SOCKET)
    {
        std::cout << "Ошибка подключения к клиенту" << std::endl;
        WSACleanup();
        return;
    }

    char msg[80] = "Сообщение от сервера";

    retVal = send(clientSock, msg, sizeof(msg), 0);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "Ошибка отправки сообщения" << std::endl;
        return;
    }
    system("pause");
    //Закрываем сокет
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

    //Создаем сокет
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (servSock == SOCKET_ERROR)
    {
        std::cout << "Ошибка создания сокета." << std::endl;
        WSACleanup();
        return;
    }

    retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));

    //Пытаемся начать слушать сокет
    retVal = listen(servSock, 10);

    if (retVal == SOCKET_ERROR)
    {
        std::cout << "Ошибка обработки запроса на подключение." << std::endl;
        WSACleanup();
        return;
    }
    //Ждем клиента
    SOCKET clientSock;

    clientSock = accept(servSock, NULL, NULL);

    if (clientSock == INVALID_SOCKET)
    {
        std::cout << "Ошибка подключения к клиенту" << std::endl;
        WSACleanup();
        return;
    }

    char recStr[80];
    recv(clientSock, recStr, sizeof(recStr), 0);
    std::cout << "Получено: " << recStr << std::endl;
    Sleep(5000);
    send(clientSock, recStr, sizeof(recStr), 0);
    std::cout << "Отправлено: " << recStr << std::endl;
    Sleep(5000);
    recv(clientSock, recStr, sizeof(recStr), 0);
    std::cout << "Получено: " << recStr << std::endl;
    system("pause");


    //Закрываем сокет
    closesocket(clientSock);
    closesocket(servSock);
    WSACleanup();
}
