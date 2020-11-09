/*
19.4.Спираль(3).
Расположить N2  чисел от 1 до N^2 по спирали.
Ввод.В единственной строке файла INPUT.TXT задано число N(1 ≤  N ≤ 50).
Вывод.Выходной файл OUTPUT.TXT содержит N2  чисел  по N  чисел по спирали.
Пример
Ввод
4
Вывод
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7

Стариков Сергей ПС-32 (22)   Visual studio 2019
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");

const string error = "Invalid value N";

bool CheckN(int N)
{
    if (N >= 1 && N <= 50)
        return true;
    return false;
}

string BuildSpiral(int N) 
{
    string result;
    int i, j, temp = 1;
    int mass[50][50];

    for (i = 0; i < N / 2; i++)
    {
        for (j = i; j < N - i; j++)
            mass[i][j] = temp++;

        for (j = i + 1; j < N - i; j++)
            mass[j][N - 1 - i] = temp++;

        for (j = N - 2 - i; j >= i; j--)
            mass[N - 1 - i][j] = temp++;

        for (j = N - 2 - i; j > i; j--)
            mass[j][i] = temp++;
    }

    if (N % 2 == 1)
        mass[N / 2][N / 2] = temp;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            result += (to_string(mass[i][j]) + " ");
        result += "\n";
    }
    return result;
}

int main()
{
    int N;

    input >> N;

    if (CheckN(N))
    {
        output << BuildSpiral(N) << endl;
    }
    else
    {
        output << error << endl;
    }

    return 0;
}
