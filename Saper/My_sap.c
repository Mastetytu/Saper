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
        ris_pol(mas, x, y);
        system("cls");
        exit(1);
        
    }
   
}

 int atak(int** mas) {
     int x, y;
    printf_s("Укажите координату по оси x: ");
    scanf_s("%d", &x);
    printf_s("Укажите координату по оси y: ");
    scanf_s("%d", &y);
    if (mas[x][y] == -1)
                    {
                        mas[x][y] = 2;
                    }
    else
    {
        mas[x][y] = 0;
    }
     system("cls");
}
// рисует поле
 int ris_pol( int** mas, int x, int y) {
     
    printf_s(" \tA \tB \tC \tD \tE\n");
    for (int i = 0; i < x; i++) {

        printf_s("%d ", i);
        for (int j = 0; j < y; j++) {
            
             if (mas[i][j] == 2) {
                    printf_s("\t*");
                    
             }
             else if (mas[i][j] == 0) {
                    printf_s("\t#");
                    
             }
             else {
                
                    printf_s("\t.");
                
            }
        }

        printf("\t\n");
    }
    

}
int main() {
	setlocale(LC_ALL, "ru");
	srand((int)time(NULL));
    int razmer,x,y;
    int** mass;
    printf_s("Укажите размер поля по оси x и y: ");
    scanf_s("%d", &razmer);
    x = razmer;
    y = x;
   mass = (int**)malloc(x * sizeof(int*));
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
    for (int i = 0; i < razmer; i++) {
        int p, h;
        p = rand() % razmer;
        h = rand() % razmer;
        mass[p][h] = -1;
    }
    int yrte = 0;
    while (yrte!=1)
    {
        ris_pol( mass, x, y);
        atak(mass);
        prover(mass, x, y);
    }

    for (int i = 0; i < razmer; i++) {
        free(mass[i]);
    }
    free(mass);
    return 0;
}