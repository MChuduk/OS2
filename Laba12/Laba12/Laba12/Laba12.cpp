#include <iostream>
#include <windows.h>

HANDLE hHeap;
int N;
int* array = nullptr;

void PrintArray();
void DrawMenu();
void AddValueRight(int value);
void DeleteValueRight();
void InsertValue(int index, int value);
void DeleteValue(int index);

int main()
{
	std::cout << "Array elements count: ";
	std::cin >> N;

	size_t array_size = N * sizeof(int);

	hHeap = HeapCreate(HEAP_NO_SERIALIZE, array_size, 0);
	if (!hHeap) 
	{
		std::cerr << "Heap create error. Error: " << GetLastError();
		return 1;
	}

	array = (int*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, array_size);
	if (!array) 
	{
		std::cerr << "Heap memory allocation error. Error: " << GetLastError();
		return 1;
	}

	for (int i = 0; i < N; i++) array[i] = i + 5;

	system("cls");
	DrawMenu();
	return 0;
}

void DrawMenu() 
{
	int choise, value, index;
	while (true) 
	{
		PrintArray();
		std::cout << std::endl;

		std::cout << "[1] add value right" << std::endl;
		std::cout << "[2] delete value right" << std::endl;
		std::cout << "[3] insert value" << std::endl;
		std::cout << "[4] delete value" << std::endl;
		std::cout << "[5] exit" << std::endl;
		std::cout << ">>";
		std::cin >> choise;

		switch (choise) 
		{
			case 1:
				std::cout << ">>";
				std::cin >> value;
				AddValueRight(value);
				break;
			case 2:
				DeleteValueRight();
				break;
			case 3:
				std::cout << ">> value: ";
				std::cin >> value;
				std::cout << ">> index: ";
				std::cin >> index;
				InsertValue(index, value);
				break;
			case 4:
				std::cout << ">> index: ";
				std::cin >> index;
				DeleteValue(index);
				break;
			case 5:
				HeapDestroy(hHeap);
				exit(0);
				break;
		}
		system("pause");
		system("cls");
	}
}

void PrintArray() 
{
	std::cout << "Index : ";
	for (int i = 0; i < N; i++)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	std::cout << "Value : ";
	for (int i = 0; i < N; i++) 
	{
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;
}

void AddValueRight(int value) 
{
	N = N + 1;
	size_t array_size = N * sizeof(int);

	array = (int*)HeapReAlloc(hHeap, HEAP_ZERO_MEMORY, array, array_size);
	array[N - 1] = value;
}

void DeleteValueRight() 
{
	N = N - 1;
	size_t array_size = N * sizeof(int);

	array = (int*)HeapReAlloc(hHeap, HEAP_ZERO_MEMORY, array, array_size);
}

void InsertValue(int index, int value) 
{
	N = N + 1;
	size_t array_size = N * sizeof(int);

	array = (int*)HeapReAlloc(hHeap, HEAP_ZERO_MEMORY, array, array_size);

	int current_index = N - 1;
	while (current_index > index) 
	{
		array[current_index] = array[current_index - 1];
		current_index--;
	}
	array[index] = value;
}

void DeleteValue(int index) 
{
	int current_index = index + 1;
	while (current_index < N)
	{
		array[current_index - 1] = array[current_index];
		current_index++;
	}

	N = N - 1;
	size_t array_size = N * sizeof(int);

	array = (int*)HeapReAlloc(hHeap, HEAP_ZERO_MEMORY, array, array_size);
}