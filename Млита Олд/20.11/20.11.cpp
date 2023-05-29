/*
20.11.Наибольшее число(4)
В положительном целом N - значном числе вычеркнуть одну цифру так, чтобы оставшееся число было как можно большим.
Ввод из файла INPUT.TXT.В первой строке находится количество знаков числа N (2 ≤ N ≤ 105). Во второй строке задано само N - значное число.
Вывод в файл OUTPUT.TXT.Вывести единственное число : номер позиции, соответствующий вычеркнутой цифре.Если решений несколько, вывести наименьший номер.
Пример
Ввод 1    Ввод 2
3         3
113       321
Вывод 1   Вывод 2
1         3

    Стариков Сергей ПС-32 (22)   Visual studio 2019
*/

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

const char constSymbol = 'a';

int CalculatePos(string str)
{
    int position = 0, temp = 0, min = 10;

    for (int i = 0; i < str.size(); i++)
    {
        temp = str[i] - constSymbol;
        if (temp < min)
        {
            min = temp;
            position = i + 1;
        }
    }
    return position;
}

int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    string str;

    getline(input, str);
    getline(input, str);
    output << CalculatePos(str) << endl;
}
