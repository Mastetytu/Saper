#include <stdio.h>
#include<locale.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "Class.c"



int main() {
	setlocale(LC_ALL, "ru");
	srand((int)time(NULL));
    
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   
    // заполняем массив поля минами
    for (int c = 0; c < M; c++) {
        do {
            i = rand() % N; j = rand() % N;
        } while (matrix[i][j] != 0);
        matrix[i][j] = -1;
    }
    // заполняем массив поля цифрами
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (matrix[i][j] != -1) {
                k = 0;
                if (mine(i - 1, j - 1)) k++;
                if (mine(i - 1, j)) k++;
                if (mine(i - 1, j + 1)) k++;
                if (mine(i, j - 1)) k++;
                if (mine(i, j + 1)) k++;
                if (mine(i + 1, j - 1)) k++;
                if (mine(i + 1, j)) k++;
                if (mine(i + 1, j + 1)) k++;
                matrix[i][j] = k;
            }
        }
    }

   

    return 0;
}