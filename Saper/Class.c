#include <stdio.h>
#include<locale.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <malloc.h>

inline int prover(int** mas, int x, int y) {
    int con = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (mas[i][j] == 0)
            {
                con = con + 1;
            }

        }
    }
    int u;
    u = x * y;
    if (con == u)
    {
        u = 1;
        return u;
    }
    else
    {
        u = 0;
        return u;
    }
}
inline int chisy_pam(int** mas, int razm) {
    for (int i = 0; i < razm; i++) {
        free(mas[i]);
    }
    free(mas);
    getchar();
}

inline int atak(int** mas, int x, int y) {
    printf_s("”кажите координату по оси x: ");
    scanf_s("%d", &x);
    printf_s("”кажите координату по оси y: ");
    scanf_s("%d", &y);
    mas[x][y] = 0;
}
// рисует поле
inline void ris_pol(HANDLE hConsole, int** mas, int x, int y) {
    SetConsoleTextAttribute(hConsole, 6);  // dark yellow text
    printf_s("  A B C D E F G H I J\n");
    for (int i = 0; i < x; i++) {
        SetConsoleTextAttribute(hConsole, 6);  // dark yellow text
        printf_s("%d ", i);
        for (int j = 0; j < y; j++) {
            if (mas[i][j] == -1) {
                SetConsoleTextAttribute(hConsole, 12);  // red text
                printf_s("*");
            }
            else if (mas[i][j] == 0) {
                SetConsoleTextAttribute(hConsole, 6);  // red text
                printf_s("*");
            }
            else if (mas[i][j] == 1) {
                SetConsoleTextAttribute(hConsole, 7);  // red text
                printf_s("*");
            }

        }

        printf("\t\n");
    }
    atak(mas, x, y);
    system("cls");
}