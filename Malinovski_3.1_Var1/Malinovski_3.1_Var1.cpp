#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum FillArray {
	Random = 1,
	Personal = 2,
	Initilization = 3
};

bool isInt(const string& str)
{
	istringstream check_Is_Int(str);
	int num;
	return (check_Is_Int >> num) && (check_Is_Int.eof());
}

int getChoice()
{
	string input = " ";
	while (true)
	{
		if (input != "")
		{
			cout << "Введите число \'1\' если хотите заполнить массив случайными числами от 1 до 100.\n";
			cout << "Введите число \'2\' если хотите заполнить массив лично.\n";
			cout << "Введите число \'3\' если хотите заполнить массив при инициализации.\n";
		}

		getline(cin, input);

		if (input != "")
		{
			if (isInt(input))
			{
				if (stoi(input) > 0 && stoi(input) < 4) 
					return stoi(input); //string to int
				else
					cout << "Ошибка! Введите число 1,2 или 3.\n";
			}
			else
			{
				cout << "Ошибка! Введите число 1,2 или 3.\n";
			}
		}
	}
}

int getElement(int i)
{
	string input = " ";

	while (true)
	{
		if (input != "")
		{
			cout << "Введите " << i << "й элемент массива: ";
		}

		getline(cin, input);

		if (input != "")
		{
			if (isInt(input))
				return stoi(input); //string to int
		}
		else
			cout << "Ошибка! Введите целое число.\n";
		
	}
}

int getArrayLength ()
{
	string input = " ";

	while (true)
	{
		if (input != "")
		{
			cout << "Введите кол-во элементов в массиве: ";
		}

		getline(cin, input);

		if (input != "")
		{
			if (isInt(input))
			{
				if (stoi(input) > 0)
					return stoi(input); //string to int
				else
					cout << "Ошибка! Введите натуральное число.\n";
			}
			else
			{
				cout << "Ошибка! Введите натуральное число.\n";
			}
		}
	}
}

void FoundRepeatElements (int* arr, int length)
{
	bool FoundRepeated = false;

	cout << "Элементы встречающиеся более одного раза: ";

	for (int i = 0; i < length; i++)
	{
		bool isRepeated = false;
		for (int j = 0; j < i; j++)
		{
			if (*(arr + i) == *(arr + j))
			{
				isRepeated = true;
				break;
			}
		}

		if (isRepeated == true)
			continue;

		int count = 0;
		for (int j = 0; j < length; j++)
		{
			if (*(arr + i) == *(arr + j))
				count++;
		}

		if (count > 1)
		{
			cout << *(arr + i) << "  ";
			FoundRepeated = true;
		}

	}

	if (FoundRepeated == false)
	{
		cout << "Нет повторяющихся элементов!";
	}
	cout << endl;
	
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int choice;
	int length;
	choice = getChoice();
	length = getArrayLength();

	int *arr = new int[length];
	
	FillArray filltype = (FillArray)choice;

	switch (filltype)
	{
	case Random:
	{
		for (int i = 0; i < length; i++)
		{
			*(arr + i) = rand() % 100 + 1;
			cout << i << "й элемент массива = " << *(arr + i) << endl;
			
		}
		FoundRepeatElements(arr, length);
		break;
	}
	case Personal:
	{
		for (int i = 0; i < length; i++)
		{
			*(arr + i) = getElement(i);
			
		}
		FoundRepeatElements(arr, length);
		break;
	}
	case Initilization:
	{
		for (int i = 0; i < length; i++)
		{
			*(arr + i) = i;
			cout << i << "й элемент массива = " << *(arr + i) << endl;
		}
		cout << "Повторений: 0\n\n";
		break;
	}
	}
		
	delete[] arr;
	return 0;
}