/*
19.7.Последняя цифра(2)
Найти последнюю цифру числа an, где a и n – натуральные числа(1 ≤ a, n ≤ 10^4).
Ввод.В единственной строке файла INPUT.TXT заданы числа a и n.
Вывод.В файл OUTPUT.TXT вывести единственное требуемое число.
Пример
Ввод
7 2
Вывод
9

Стариков Сергей ПС-32 (22)   Visual studio 2019
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");

const string error = "Invalid value A or N";

void FindLastNumber(int A, int N)
{
	long long temp = 0, threshold = 10000;

	temp = A;

	if (A < 1 || A > threshold || N < 1 || N > threshold)
	{
		output << error << endl;
	}
	else if (N == 1) 
	{
		temp %= 10;
		output << temp << endl;
	}
	else 
	{
		for (int i = 1; i != N; i++)
		{
			temp *= A;
			temp %= 10;
		}
		output << temp << endl;
	}
}

int main()
{
	int A = 0, N = 0;
	input >> A >> N;
	FindLastNumber(A, N);
}