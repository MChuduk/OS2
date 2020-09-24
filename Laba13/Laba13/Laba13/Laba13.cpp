#include <iostream>
using namespace std;

bool IsFixedPoint(char* word);
bool IsFloatingPoint(char* word);
bool IsComplex(char* word);
bool IsAlgebra(char* word);
bool IsCorrect(char* word);

bool inttrue(char s);

template< class T >
class Stack {

private:
	int MAX;
	int top;
	T* items;

public:
	Stack(int size) {
		MAX = size;
		top = -1;
		items = new T[MAX];
	}

	~Stack() { delete[] items; }

	void push(T c) {
		if (full()) {
			cout << "Stack Full!" << endl;
			exit(1);
		}

		items[++top] = c;
	}

	T pop() {
		if (empty()) {
			cout << "Stack Empty!" << endl;
			return NULL;
			exit(1);
		}


		return items[top--];
	}

	T free() {
		top = -1;
		return true;
	}

	int empty() { return top == -1; }

	int full() { return top + 1 == MAX; }
};

char word[200] = { " " };

int main()
{
    setlocale(LC_CTYPE, "Rus");

    while (true) 
    {
		char buffer[256];
        std::cout << "Ведите вырыжение: ";
        std::cin >> buffer;

        if (IsFixedPoint(buffer) == true)
        {
            std::cout << "Это число с фиксированной точкой." << std::endl;
            continue;
        }
        if (IsFloatingPoint(buffer) == true)
        {
            std::cout << "Это число с плавающей точкой." << std::endl;
            continue;
        }
		if (IsComplex(buffer) == true)
		{
			std::cout << "Это комплексное число." << std::endl;
			continue;
		}
		if (IsAlgebra(buffer) == true)
		{
			std::cout << "Это алгебралическое выражение." << std::endl;
			continue;
		}
		if (IsCorrect(buffer) == true)
		{
			std::cout << "Корректное выражение со скобками." << std::endl;
			continue;
		}
	/*	if (strcmp(buffer, "exit") != 1) {
			exit(0);
		}*/

        std::cout << "Ошибка." << std::endl;
    }

    return 0;
}

bool IsFixedPoint(char* word)
{
	Stack<int> s(5);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (inttrue(word[i]) || word[i] == '-')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (inttrue(word[i]))
				s.push(1);
			else if (word[i] == '.')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (inttrue(word[i]))
				s.push(3);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
			if (inttrue(word[i]))
				s.push(3);
			else if (word[i] == ' ')
			{
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}


	return true;
}
bool IsFloatingPoint(char* word) {
	Stack<int> s(8);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (inttrue(word[i]) || word[i] == '-' || word[i] == '+')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (inttrue(word[i]))
				s.push(1);
			else if (word[i] == '.')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (inttrue(word[i]))
				s.push(3);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
			if (inttrue(word[i]))
				s.push(3);
			else if (word[i] == 'e')
			{
				s.push(4);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 4)
		{
			if (word[i] == '+' || word[i] == '-')
				s.push(5);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 5)
		{
			if (inttrue(word[i]))
				s.push(6);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 6)
		{
			if (inttrue(word[i]))
				s.push(6);
			else if (word[i] == ' ')
			{
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}


	return true;
}
bool IsComplex(char* word)
{
	Stack<int> s(5);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (inttrue(word[i]) || word[i] == '-' || word[i] == '+')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (inttrue(word[i]))
				s.push(1);
			else if (word[i] == '-' || word[i] == '+')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (inttrue(word[i]))
				s.push(2);
			else if (word[i] = 'j')
			{
				s.push(3);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
			if (word[i] == ' ')
			{
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}
	return true;
}
bool IsAlgebra(char* word)
{
	Stack<int> s(3);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (word[i] == 'b' || word[i] == 'a')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (word[i] == '+' || word[i] == '-' || word[i] == '*' || word[i] == ':')
				s.push(0);
			else if (word[i] == ' ')
			{
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}


	return true;
}
bool IsCorrect(char* word)
{
	Stack<int> s(3);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (word[i] == '(')
				s.push(1);
			else if (inttrue(word[i]) || word[i] == 'b' || word[i] == 'a' || word[i] == '+' || word[i] == '-' || word[i] == '*' || word[i] == ':')
				s.push(0);
			else if (word[i] == ' ')
			{
				return true;
			}
			else
				s.push(-1);
		}
		else if (sost == 1)
		{
			if (word[i] == ')')
				s.push(0);
			else if (inttrue(word[i]) || word[i] == 'b' || word[i] == 'a' || word[i] == '+' || word[i] == '-' || word[i] == '*' || word[i] == ':')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}
	return true;
}

bool inttrue(char s)
{
	switch (s)
	{
	case '1': return true; break;
	case '2': return true; break;
	case '3': return true; break;
	case '4': return true; break;
	case '5': return true; break;
	case '6': return true; break;
	case '7': return true; break;
	case '8': return true; break;
	case '9': return true; break;
	case '0': return true; break;

	default: return false;
		break;
	}
}