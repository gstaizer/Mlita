﻿/*
20.5.Теннисный турнир(5)
В теннисном турнире участвуют 2n игроков(1 ≤ n ≤ 18).Каждый теннисист имеет индивидуальный числовой рейтинг.
Чем больше рейтинг, тем выше мастерство игрока.Известно, что рейтинги всех игроков разные.
Турнир проходит по олимпийской системе с выбываниями.После каждого тура проигравшие покидают турнир.
Таким образом, n - й тур является финалом.
Организаторы формируют начальный список участников.В первом туре первый игрок списка играет со вторым, 
третий с четвертым и т.д.В результате список сокращается вдвое.Во втором туре встречаются победители 
первой и второй пар, третьей и четвертой и т.д.Далее все продолжается аналогично.Таким образом, начальный 
список и результаты матчей полностью определяют пары участников последующих встреч.
Игроки получили стартовые номера в порядке убывания их рейтинга.Сильнейший игрок имеет номер 1, второй по 
силе – номер 2 и т.д.Конечно, никому не хочется, чтобы сильные игроки встречались на ранних этапах.
Более того, по традиции проведения турниров фавориты играют сначала со слабейшими игроками.
Поэтому в первом туре запланированы матчи игроков с номерами 1 и 2n, 2 и 2n – 1, 3 и 2n – 2 и т.д.
Решено подобный принцип распространить и на последующие туры.
Организаторы рассуждают так.Допустим, что в матчах всегда будут побеждать игроки с более высоким рейтингом.
Тогда во второй тур выйдут игроки с номерами 1, 2, …, 2n - 1. Желательно, чтобы далее встретились игроки 
с номерами 1 и 2n - 1, 2 и 2n - 1 – 1, …, 2n - 2 и 2n - 2 + 1. Тогда в третий тур выйдут лучшие игроки 
с номерами 1, 2, …, 2n - 2. При подобном течении турнира в каждый следующий тур будут попадать лучшие 
по рейтингу игроки предыдущего тура.Интрига сохранится до конца турнира, а в финале окажутся первые два номера рейтинга.
Помогите организаторам турнира сформировать начальный список игроков в соответствии с описанными пожеланиями.
Входные данные.В единственной строке находится значения n.
Выходные данные.В единственной строке вывести через пробел 2n номеров игроков, составляющих начальный список.
В случае нескольких вариантов вывести любое допустимое решение.
Примеры
Примеры
Ввод 1       Ввод 2
1            2
Вывод 1      Вывод 2
1 2          1 4 2 3

    Стариков Сергей ПС-32 (22)   Visual studio 2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string error = "Invalid value N";

void CreatingInitialList(int N, ofstream& output)
{
    double numberOfPlayers = pow(2, N);

    int result[30000][2] = { 0 };

    for (int i = 0; i < numberOfPlayers / 2; i++)
    {
        int k = 3, k1, k2, temp = 0, j = 3;

        k1 = i + 1;
        k2 = numberOfPlayers - i;

        if (N > 4) 
        {
                output << k1 << ' ';
                output << k2 << ' ';
        }
        else
        {
            if (i == 0)
            {
                result[i][1] = k1;
                result[i][2] = k2;
            }
            else if (i == 1)
            {
                temp = numberOfPlayers / 2 - 1;
                result[temp][1] = k1;
                result[temp][2] = k2;
            }
            else
            {
                if (i % 2 == 0)
                {
                    if (i == 6)
                        k++;
                    temp = numberOfPlayers / 4 + i - k;
                    result[temp][1] = k1;
                    result[temp][2] = k2;
                    k--;

                }
                else
                {
                    if (i == 7)
                        j++;
                    temp = numberOfPlayers / 2 - numberOfPlayers / 4 - i + j;
                    result[temp][1] = k1;
                    result[temp][2] = k2;
                    j--;
                }
            }
        }
    }

    if (N <= 4)
    {
        for (int i = 0; i < numberOfPlayers / 2; i++)
        {
            output << result[i][1] << ' ' << result[i][2] << ' ';
        }
    }
}

int main()
{
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
   
    int N;
    input >> N;

    if (N < 1 || N > 18)
    {
        output << error << endl;
    }
    else
    {
        CreatingInitialList(N, output);
    }
}