#include <stdio.h>
#include<locale.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <malloc.h>
#include "Class.c"


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	srand((int)time(NULL));
    int razmer,x,y;
    int** mass;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf_s("Укажите размер поля по оси x и y: ");
    scanf_s("%d", &razmer);
    x = razmer;
    y = x;
    mass = (int**)malloc(x * sizeof(int));
    int  k = 0;
    // заполняем массив поля цифрами
    for (int i = 0; i < razmer; i++) {
        // Выделение памяти под хранение строк
        mass[i] = (int*)malloc(y * sizeof(int));
        for (int j = 0; j < razmer; j++) {
                mass[i][j] = 1;
        }
    }
    //// заполняем массив поля минами
    for (int i = 0; i <= razmer; i++) {
        x = rand() % razmer;
        y = rand() % razmer;
        mass[x][y] = -1;
    }
    while (prover(&mass, x, y) ==1)
    {
        ris_pol(hConsole, &mass, x, y);
    }

    chisy_pam(&mass, razmer);
    return 0;
}