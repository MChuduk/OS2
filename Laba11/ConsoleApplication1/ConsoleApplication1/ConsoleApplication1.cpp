#include <iostream>
#include <windows.h>
#include "Lab11.h";
using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    setlocale(LC_ALL, "Rus");

    //Task1();
    //Task2();
    //Task3();

    return 0;
}

void Task1() 
{
    system("mode con cols=60 lines=30");
    system("cls");
    SetConsoleTextAttribute(H, 10);
    int N;
    cout << "Введите размер массива: ";
    cin >> N;

    char** strings = (char**)malloc(N * sizeof(char*));

    if (!strings) 
    {
        cout << "Ошибка выделения памяти";
        return;
    }
    for (int i = 0; i < N; i++) 
    {
        cout << "strings[" << i << "] = ";
        strings[i] = (char*)malloc(50 * sizeof(char));
        cin >> strings[i];
    }
    cout << endl;
    for (int i = 0; i < N; i++) 
    {
        cout << strings[i] << endl;
    }

    for (int i = 0; i < N; i++) {
        free(strings[i]);
    }
    free(strings);
}

struct book 
{
    char title[20];
};

void Task2() 
{
    system("cls");
    SetConsoleTextAttribute(H, 10);
    int N;
    cout << "Введите размер массива: ";
    cin >> N;

    book* books = (book*)malloc(N * sizeof(book));

    if (!books)
    {
        cout << "Ошибка выделения памяти";
        return;
    }
    for (int i = 0; i < N; i++)
    {
        cout << "book[" << i << "].title = ";
        char buffer[20];
        cin >> buffer;
        strcpy_s(books[i].title, sizeof(books[i].title), buffer);
    }
    cout << endl;
    for (int i = 0; i < N; i++) 
    {
        cout << books[i].title << endl;
    }
    free(books);
}

void Task3() 
{
    system("cls");
    SetConsoleTextAttribute(H, 10);
    int N, M;
    cout << "Введите размеры массива: ";
    cin >> N >> M;

    book** books = (book**)malloc(N * sizeof(book*));

    if (!books)
    {
        cout << "Ошибка выделения памяти";
        return;
    }
    for (int i = 0; i < N; i++)
    {
        books[i] = (book*)malloc(M * sizeof(book));
        for (int j = 0; j < M; j++)
        {
            cout << "book[" << i << ", " << j << "].title = ";
            char buffer[20];
            cin >> buffer;
            strcpy_s(books[i][j].title, sizeof(books[i][j].title), buffer);
        }
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        {
            cout << books[i][j].title << endl;
        }
    }

    for (int i = 0; i < N; i++) {
        free(books[i]);
    }
    free(books);
}