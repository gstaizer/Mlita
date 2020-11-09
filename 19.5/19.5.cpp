/*
19.5.Квадраты(2)
Составить программу, которая будет находить, на сколько квадратов можно разрезать данный прямоугольник, 
если от него каждый раз отрезается квадрат максимально большой площади.Стороны прямоугольника и квадратов выражены натуральными числами.
Ввод.В первой строке файла INPUT.TXT стороны прямоугольника A и B(1 ≤  A, B ≤ 10^18).
Вывод.Выходной файл OUTPUT.TXT содержит одно число - количество квадратов.
Пример
Ввод
6 4
Вывод
3

	Стариков Сергей ПС-32 (22)   Visual studio 2019
*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");

const string error = "Invalid value A or B";

int main()
{
	double A, B, threshold = pow(10, 18);
	long long result = 1;

	input >> A >> B;
	if (A < 1 || A > threshold || B < 1 || B > threshold)
	{
		output << error << endl;
	}
	else
	{
		while (A != B)
		{
			A > B ? A = A - B : B = B - A;
			result++;
		}

		output << result << endl;
	}
}