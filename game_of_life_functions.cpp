#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>
#include "game_of_life_functions.h"
#include "training_functions.h"


void fill_array(bool t[20][60], int x, int y, int a)
{
    srand(time(nullptr));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if ((rand() % 100) < a)
                t[i][j] = true;
            else
                t[i][j] = false;
        }
    }

}

void show_array(bool t[20][60], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (t[i][j] != 0)
                std::cout << '+';
            else
                std::cout << ' ';


        }
        std::cout << '\n';

    }

}

void life_step(bool t[20][60], int x, int y)
{
    bool t2[20][60];
    int sum;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            sum = 0;
            for (int s = (i - 1); s < i + 2; s++)
            {
                for (int u = (j - 1); u < j + 2; u++)
                {
                    if ((s == i) && (u == j))
                        continue;
                    else
                        sum += t[(x + s) % x][(y + u) % y]; //modulo is allow to not read memory except array area
                }
            }


            if (sum == 3)
                t2[i][j] = true;
            else if (sum == 2)
                t2[i][j] = t[i][j];
            else
                t2[i][j] = false;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            t[i][j] = t2[i][j];

        }

    }
}

void short_game_of_life()
{
      bool field[20][60];
    int a = 5;
    int steps;
    do
    {
        std::cout << "how much life? 0-100%\n";
        std::cin >> a;
        system("cls");
    } while (!isRight() || a < 0 || a > 100);

    do
    {
        std::cout << "how much steps? 0-500\n";
        std::cin >> steps;
        system("cls");
    } while (!isRight() || (steps  < 0 || steps > 500));

    fill_array(field, 20, 60, a);
    show_array(field, 20, 60);
    system("pause");
    system("cls");

    for (int i = 0;i < steps;i++)
    {
        system("cls");
        life_step(field, 20, 60);
        show_array(field, 20, 60);
        //system("pause");
        //Sleep(10);
    }
}