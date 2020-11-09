/*
19.16.Простые числа(3)
Найти сумму простых чисел, расположенных между N и K(0 < N ≤ K ≤ 4×10^6), включая эти числа.
Ввод.В первой строке файла INPUT.TXT содержатся через пробел натуральные числа N и K.
Вывод.Вывести в файл OUTPUT.TXT одно число - сумму простых чисел, расположенных между N и K.
Пример
Ввод
  1 5
Вывод
  10
  
    Стариков Сергей ПС-32 (22)   Visual studio 2019
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");

const string error = "Invalid values N or K";

bool isSimpleInteger(long curr)
{
    for (long i = 2; i <= sqrt(curr); i++)
        if (curr % i == 0)
            return false;
    return true;
}

void CalcResult(long N, long K)
{
    long long result = 0;

    for (long i = N; i <= K; i++) {
        if (isSimpleInteger(i) && i > 1) 
        {
            result += i;
        }
    }

    output << result << endl;
}

int main()
{
    long N, K;
    input >> N >> K;
    if (N >= 0 && K >= N)
    {
        CalcResult(N, K);
    }
    else
    {
        output << error << endl;
    }
    return 0;
}