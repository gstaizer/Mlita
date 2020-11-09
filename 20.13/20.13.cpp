/*
20.13.Арифметическая прогрессия(4)
Заданo N натуральных(целых положительных) чисел из диапазона[1; 10000].
Необходимо определить, можно ли из этих чисел в каком - либо порядке их следования составить арифметическую прогрессию.
Ввод.Первая строка файла INPUT.TXT содержит число тестовых блоков L(L ≤ 10).
Каждый тестовый блок состоит из двух строк.В первой указывается количество чисел N(N ≤ 10^5), во второй - N чисел через пробел.
Вывод.Результат в файле OUTPUT.TXT.Для каждого тестового блока выводится единственная строка 
со значением Yes или No – можно или нет составить арифметическую прогрессию.
Пример
Ввод
2
3
5 9 1
4
11 13 15 13
Вывод
Yes
No

	Стариков Сергей ПС-32 (22)   Visual studio 2019
*/

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string error1 = "Invalid value L", error2 = "Invalid value N";

int Compare(const void* x1, const void* x2) // Для сортировки
{
	return (*(int*)x1 - *(int*)x2);
}

bool CheckSeq(vector<int>& numbers)
{
	long k, lenght;
	lenght = numbers.size();
	if (lenght == 1 || lenght == 2)
	{
		return true;
	}
	k = numbers[1] - numbers[0];
	for (int i = 2; i < lenght; i++)
	{
		if (numbers[i - 1] + k != numbers[i])
		{
			return false;
		}
	}
	return true;
}

string IsValidArithmeticProgression(ifstream& input)
{
	vector<int> numbers;
	long N, number, threshold = 100000;

	input >> N;

	if (N > threshold || N < 1)
	{
		return error2;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			input >> number;
			numbers.push_back(number);
		}
		qsort(&numbers[0], N, sizeof(int), Compare);
		return CheckSeq(numbers) ? "Yes" : "No";
	}
}

int main()
{
	ifstream input("INPUT.txt");
	ofstream output("OUTPUT.txt");
	
	int L;
	input >> L;

	if (L > 10 || L < 1)
	{
		output << error1 << endl;
	}
	else
	{
		for (int i = 0; i < L; i++)
		{
			output << IsValidArithmeticProgression(input) << endl;
		}
	}
}