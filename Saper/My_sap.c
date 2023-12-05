#include <stdio.h>
#include<locale.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <malloc.h>
int protg(int** mass, int razmer) {
    for (int i = 0; i < razmer; ++i)
    {
        for (int j = 0; j < razmer; ++j)
        {
            if (mass[i][j] != -1)
            {if(i-1>-1 && j-1>-1 && i+1<razmer && j+1<razmer)
                if (i > 0 && mass[i + 1][j] == -1)
                    ++mass[i][j];
            if (i - 1 > -1 && j - 1 > -1 && i + 1 < razmer && j + 1 < razmer)
                if (i < razmer - 1 && mass[i - 1][j] == -1)
                    ++mass[i][j];
            if (i - 1 > -1 && j - 1 > -1 && i + 1 < razmer && j + 1 < razmer)
                if (j > 0 && mass[i][j - 1] == -1)
                    ++mass[i][j];
            if (i - 1 > -1 && j - 1 > -1 && i + 1 < razmer && j + 1 < razmer)
                if (j < razmer - 1 && mass[i][j + 1] == -1)
                    ++mass[i][j];
            if (i - 1 > -1 && j - 1 > -1 && i + 1 < razmer && j + 1 < razmer)
                if (j < razmer - 1 && i>0 && mass[i - 1][j + 1] == -1)
                    ++mass[i][j];
            if (i - 1 > -1 && j - 1 > -1 && i + 1 < razmer && j + 1 < razmer)
                if (i < razmer - 1 && j>0 && mass[i + 1][j - 1] == -1)
                    ++mass[i][j];
            if (i - 1 > -1 && j - 1 > -1 && i + 1 < razmer && j + 1 < razmer)
                if (j < razmer - 1 && i < razmer - 1 && mass[i + 1][j + 1] == -1)
                    ++mass[i][j];
            if (i - 1 > -1 && j - 1 > -1 && i + 1 < razmer && j + 1 < razmer)
                if (j > 0 && i > 0 && mass[i - 1][j - 1] == -1)
                    ++mass[i][j];
            }
        }
    }
}

int atak(int** mas, int razm, int yt) {
    int x, y;
    printf_s("Укажите координату по оси x: ");
    scanf_s("%d", &x);
    printf_s("Укажите координату по оси y: ");
    scanf_s("%d", &y);
    if (mas[x][y] == -1)
    {

        exit(1);
    }
    else
    {
        mas[x][y] = 0;
    }
    
    system("cls");
}
// рисует поле
int ris_pol(HANDLE hConsole, int** mas, int x, int y) {
    for (int c = 0; c < x; c++)
    {
        printf_s("\t%d", c);
    }
    printf_s("\n");
    for (int i = 0; i < x; i++) {

        printf_s("%d ", i);
        for (int j = 0; j < y; j++) {

            /*  if (mas[i][j] == 0) {
                    printf_s("\t#");

             }*/
            if (mas[i][j] >= 0) {
                SetConsoleTextAttribute(hConsole, 10);
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else {

                printf_s("\t.");

            }
        }

        printf_s("\t\n");
    }


}
int main() {
    setlocale(LC_ALL, "ru");
    srand((int)time(NULL));
    int razmer, x, y;
    int** mass;
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf_s("Укажите размер поля по оси x и y: ");
    scanf_s("%d", &razmer);
    x = razmer;
    y = x;
    mass = (int**)malloc( x * sizeof(int*));
    int  k = 0;
    // заполняем массив поля цифрами
    for (int i = 0; i < razmer; i++) {
        // Выделение памяти под хранение строк
        mass[i] = (int*)malloc(y * sizeof(int));
        for (int j = 0; j < razmer; j++) {
            mass[i][j] = 0;
        }
    }
    //// заполняем массив поля минами
    for (int i = 0; i < razmer; i++) {
        int p, h;
        p = rand() % razmer;
        h = rand() % razmer;
        mass[p][h] = -1;
    }
    int vr1, vr2;
    int TYR = 0;
    if (TYR!=1)
    { 
        protg( mass, razmer);
        TYR++;
    }
    int yt = 0;
    int yrte = 0;
    while (yrte != 1)
    {
        ris_pol(hConsole, mass, razmer, x, y);
        atak(mass, razmer, yt);

    }

    for (int i = 0; i < razmer; i++) {
        free(mass[i]);
    }
    free(mass);
    return 0;
}