#include <iostream>
#include <locale>

using namespace std;

void arrayRandom(int* array, int n)
{
	srand((int)time(0));
	for (int i = 0; i < n; i++)
		array[i] = rand();
}

int solution(int n)
{
	int sum = 0;
	int* array = new int[n];

	arrayRandom(array, n);

	for (int i = 1; i < (n - 1); i++)
	{
		if (array[i] < array[i - 1] and array[i] < array[i + 1])
			sum++;
	}
	return sum;
}

void Task()
{
	int n;

	cout << "Введите длину массива: ";
	while (true)
	{
		cin >> n;

		if (n >= 3) break;
		cout << "По условию задачи в массиве должно быть как минимум 3 элемента" << endl;
	}
	cout << "В сгенерированном массиве длиною " << n << " количесво локальных минимумов равно: " << solution(n) << endl;
}

void menu()
{
	while (true)
	{
		int number;

		cout << "Количество повторений:	";
		cin >> number;

		if (number > 0) for (int i = 0; i < number; i++) Task();
		else if (number == 0) break;
		else cout << "Введено не коректное значение";
	}
}

int main()
{
	setlocale(0, "");
	menu();
}