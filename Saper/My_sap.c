#include <stdio.h>
#include<locale.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <malloc.h>

 int prover(int** mas, int x, int y) {
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
        exit(1);
    }
   
}

 int atak(int** mas, int x, int y) {
    printf_s("Укажите координату по оси x: ");
    scanf_s("%d", &x);
    printf_s("Укажите координату по оси y: ");
    scanf_s("%d", &y);
    mas[x][y] = 0;
}
// рисует поле
 void ris_pol(HANDLE hConsole, int** mas, int x, int y) {
     
    printf_s("  A B C D E F G H I J\n");
    for (int i = 0; i < x; i++) {

        printf_s("%d ", i);
        for (int j = 0; j < y; j++) {
            
            if  (mas[i][j] == -1){
                printf_s("\t*");
            }
            else if (mas[i][j] == 0) {

                printf_s("*");
            }
            else if (mas[i][j] == 1) {

                printf_s("*");
            }

        }

        printf("\t\n");
    }
    atak(mas, x, y);

}
int main() {
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
    int yrte = 0;
    while (yrte!=1)
    {
        ris_pol(hConsole, &mass, x, y);
        prover(&mass, x, y);
    }

    for (int i = 0; i < razmer; i++) {
        free(mass[i]);
    }
    free(mass);
    return 0;
}