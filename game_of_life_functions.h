#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>


void fill_array(bool t[20][60], int x, int y, int a);
void show_array(bool t[20][60], int x, int y);
void life_step(bool t[20][60], int x, int y);
void short_game_of_life();