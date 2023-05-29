/*
20.1.Осмотр(4)
Для того, чтобы быть допущенным к занятиям в бассейне, необходимо предъявить справку, на которой должны поставить свои подписи K врачей.
Некоторые врачи отказываются ставить подписи на справке до тех пор, пока на ней не распишется другой врач.
Например, стоматолог отказывается ставить подпись, пока не будет принесена справка от психиатра, потому что однажды его 
укусил психически неуравновешенный студент.Составлен список, какому врачу нужны какие справки.Нужно определить, можно ли 
получить все справки, а также в какой последовательности необходимо обходить врачей.

Ввод.В первой строке файла INPUT.TXT содержится общее количество врачей(1 ≤ K ≤ 100).В следующих K строках описываются необходимые справки.
Первое число j в i + 1 строке входного файла означает, сколько справок нужно i - му врачу.Затем в той же строке, 
содержится j чисел - номера врачей, чьи подписи надо предварительно поставить, чтобы получить подпись i - го врача.

Вывод.Если подписи всех врачей собрать невозможно, то в выходной файл OUTPUT.TXT следует вывести NO.
Если же все справки собрать возможно, то в первой строке выходного файла должно содержаться YES, 
а в следующих K строках - последовательность, в которой нужно получать справки.В случае нескольких решений выдать любое из них.
Пример
Ввод
4
1 2
0
2 1 4
1 1
Вывод
YES
2
1
4
3

	Стариков Сергей ПС-32 (22)   Visual studio 2019
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");

typedef map<int, vector<int>> mapInput;
typedef map<int, map<int, bool>> mapOutput;
vector<int> path;
const string error = "Invalid value K", yes = "YES", no = "NO";

bool checkPossibility(mapOutput& mapOut)
{
	for (auto i = mapOut.cbegin(); i != mapOut.cend(); ++i)
	{
		for (auto j = i->second.cbegin(); j != i->second.cend(); ++j)
		{
			if (j->second == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void commonPass(mapInput& mapIn, mapOutput& mapOut, int index)
{
	bool check = false;
	path.push_back(index);
	for (int i = 0; i < mapIn[index].size(); i++)
	{
		int newIndex = mapIn[index][i];
		mapOut[newIndex][index] = 1;
		for (auto j = mapOut[newIndex].cbegin(); j != mapOut[newIndex].cend(); ++j)
		{
			if (j->second == 0)
			{
				goto skip;
			}
		}
		commonPass(mapIn, mapOut, newIndex);
	skip:;
	}
}

void firstPass(mapInput& mapIn, mapOutput& mapOut, vector<int>& doctors, ostream& output)
{
	path.clear();
	for (int i = 0; i < doctors.size(); i++)
	{
		int index = doctors[i];
		commonPass(mapIn, mapOut, index);
	}
	if (checkPossibility(mapOut))
	{
		output << yes << endl;
		for (int i = 0; i < path.size(); i++)
		{
			output << path[i] + 1 << endl;
		}
		return;
	}
	output << no << endl;
}

void Calcpath(istream& input, ostream& output)
{
	vector<int> doctors;
	mapInput mapIn;
	mapOutput mapOut;
	int K;

	input >> K;
	if (K < 1 || K > 100)
	{
		output << error;
	}
	else
	{
		for (int i = 0; i < K; i++)
		{
			int singCount;
			input >> singCount;
			for (int k = 0; k < singCount; k++)
			{
				int singNum;
				input >> singNum;
				mapIn[singNum - 1].push_back(i);
				mapOut[i].insert({ singNum - 1, 0 });
			}
			if (singCount == 0)
			{
				doctors.push_back(i);
			}
		}
		firstPass(mapIn, mapOut, doctors, output);
	}
}

int main()
{
	Calcpath(input, output);

	return 0;
}