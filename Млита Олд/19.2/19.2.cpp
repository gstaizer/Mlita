/*
19.2. Домино (3)

Найти количество вариантов покрытия прямоугольника 2×N прямоугольниками 2×1. 
Покрытия, которые преобразуются друг в друга симметриями, считать различными.
Ввод. В единственной строке входного файла INPUT.TXT задано значение N (1 ≤ N ≤ 20).
Вывод. В единственной строке выходного файла OUTPUT.TXT должно содержаться количество 
вариантов покрытия прямоугольника.

Стариков Сергей ПС-32 (22)   Visual studio 2019
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string error = "Invalid value N";

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");

string CalculateRes(int N) 
{
	int temp = 0, prev = 2, prevEarlier = 1;
	string result;

	if (N < 1 || N > 20)
	{
		return error;
	}
	else
	{
		if (N == 1 || N == 2)
		{
			result = to_string(N);
			return result;
		}
		else
		{
			for (int i = 2; i < N; i++)
			{
				temp = prev + prevEarlier;
				prevEarlier = prev;
				prev = temp;
			}
			result = to_string(temp);
			return result;
		}
	}
}

int main()
{
	int N;
	input >> N;
	output << CalculateRes(N) << endl;
	return 0;
}