/*
14.14. Ферзи (5)
Имеется шахматная доска N×N (4 ≤ N ≤ 40), в которой по горизонталям слева направо записаны в 
порядке возрастания целые числа от 1 до N2. Например, при N=4 доска заполняется следующим образом:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Выбирается такой набор из N клеток, что любые два ферзя, стоящие на этих клетках, не бьют друг друга. 
Иными словами, любые две клетки находятся на разных горизонталях, вертикалях и диагоналях. 
Найти максимальную сумму чисел в таких наборах. 
Ввод из файла INPUT.TXT. В единственной строке задается значение N. 
Вывод в файл OUTPUT.TXT. В единственной строке выводятся максимальное значение суммы чисел.
Пример
Ввод   
4 
Вывод
34
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ifstream in("INPUT.txt");
    std::ofstream out;
    out.open("OUTPUT.txt");
    string line;
    int N;

    if (in.is_open() && out.is_open())
    {
        in >> N;
        int fieldSize = pow(N, 2);

        std::vector<int> field(fieldSize);

        for (int i = 1; i <= fieldSize; i++) {
            field[i - 1] = i;
        }

        for (int k = 1; k <= N; k++) {
            field[fieldSize - k * 1] = 0;
            field[fieldSize - 1 - k * N] = 0;
            field[fieldSize - 1 - k * (N + 1)] = 0;
        }

        out << fieldSize + *std::max_element(field.begin(), field.end()) << endl;
    }
}