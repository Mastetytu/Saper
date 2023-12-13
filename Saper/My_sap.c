#include <stdio.h>
#include<locale.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <malloc.h>
//проверка мин
int Checking_mines(int** mass, int razmer) {
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
//конец игры
int The_end_of_the_game(HANDLE hConsole,int razm, int** mas) {
    int no=0, yes=0;
    system("cls");
    for (int k = 0; k < razm; k++)
    {
        printf_s("\t%d", k);
    }
    printf_s("\n");
    for (int u = 0; u < razm; u++) {
        printf_s("%d ", u);
        for (int l = 0; l < razm; l++) {
            if (mas[u][l] == -3) {
                SetConsoleTextAttribute(hConsole, 12);
                printf_s("\t#");
                SetConsoleTextAttribute(hConsole, 7);
            }
            else  if (mas[u][l] == -4) {
                SetConsoleTextAttribute(hConsole, 11);
                printf_s("\t#");
                SetConsoleTextAttribute(hConsole, 7);
                yes++;
            }
            else  if (mas[u][l] == -5) {
                SetConsoleTextAttribute(hConsole, 7);
                printf_s("\t#");
                SetConsoleTextAttribute(hConsole, 7);
                no++;
            }
            else {
                printf_s("\t%d", mas[u][l]);
            }

        }
        printf_s("\t\n");
    }
    printf_s("Неудачные разминнирования: %d \n Удачные разминнирования: %d \n",no,yes );
    if (no>0)
    {
        printf_s("Вы проиграли \n");
    }
    for (int i = 0; i < razm; i++) {
        free(mas[i]);
    }
    free(mas);
    exit(1);
}
//атака
int repeat_call(int** mas, int razm, int x, int y) {
    if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < razm && y + 1 < razm)
    {
        performing_a_check(mas, razm, x + 1, y);
        performing_a_check(mas, razm, x - 1, y);
        performing_a_check(mas, razm, x + 1, y + 1);
        performing_a_check(mas, razm, x - 1, y - 1);
        performing_a_check(mas, razm, x, y + 1);
        performing_a_check(mas, razm, x, y - 1);
        performing_a_check(mas, razm, x - 1, y + 1);
        performing_a_check(mas, razm, x + 1, y - 1);
    } 
    else {
        system("cls");
        printf_s("Ошибка");
        return;
    }
}
int performing_a_check(int** mas, int razm, int x, int y) {
    if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < razm && y + 1 < razm)
    {
        if (mas[x - 1][y] == 0 || mas[x - 1][y] == -6) {
            mas[x - 1][y] = -6;
            repeat_call(mas, razm, x, y);
             
        }

        else if (mas[x + 1][y] == 0 || mas[x + 1][y] == -6) {
            mas[x + 1][y] = -6;
            repeat_call(mas, razm, x, y);
             
        }

        else if (mas[x + 1][y + 1] == 0 || mas[x + 1][y + 1] == -6) {
            mas[x + 1][y + 1] = -6;
            repeat_call(mas, razm, x, y);
            
        }

        else if (mas[x + 1][y - 1] == 0 || mas[x + 1][y - 1] == -6) {
            mas[x + 1][y - 1] = -6;
            repeat_call(mas, razm, x, y);
        }

        else if (mas[x][y - 1] == 0 || mas[x][y - 1] == -6) {
            mas[x][y - 1] = -6;
            repeat_call(mas, razm, x, y);
             
        }
        else if (mas[x][y + 1] == 0 || mas[x][y + 1] == -6) {
            mas[x][y + 1] = -6;
            repeat_call(mas, razm, x, y);
        }
        else if (mas[x - 1][y - 1] == 0 || mas[x - 1][y - 1] == -6) {
            mas[x - 1][y - 1] = -6;
            repeat_call(mas, razm, x, y);
        }
        else if (mas[x - 1][y + 1] == 0 || mas[x - 1][y + 1] == -6) {
            mas[x - 1][y + 1] = -6;
            repeat_call(mas, razm, x, y);
        }
    }
    else {
        system("cls");
        printf_s("Ошибка");
        
    }
}
int opening_zeros(int** mas, int razm,int x,int y) {
     if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < razm && y + 1 < razm)
     {
         repeat_call(mas, razm, x, y);
     }
     else {
         system("cls");
         printf_s("Ошибка");
         return;
     }
}
int atak(int** mas, int razm) {
    
    int x, y;
    int k = 0;
    printf_s("1.Разминировать \n2.Атаковать \nВаш выбор:");
    scanf_s("%d", &k);
    if (k==1)
    {
        printf_s("Укажите координату по оси x: ");
        scanf_s("%d", &x);
        printf_s("Укажите координату по оси y: ");
        scanf_s("%d", &y);
        if (mas[x][y] != -2) {
            if (mas[x][y] == -1)
            {
                mas[x][y] = -4;

            }
            else
            {
                mas[x][y] = -5;
            }
        }
        else
        {
           
            printf_s("Введите еще раз\n");
            atak(mas, razm);
        }

        system("cls");
    }
    else if (k==2)
    {
        printf_s("Укажите координату по оси x: ");
        scanf_s("%d", &x);
        printf_s("Укажите координату по оси y: ");
        scanf_s("%d", &y);
        if (mas[x][y] == -1)
        {
            mas[x][y] = -3;

        }
        else
        {
            mas[x][y] = -2;
            opening_zeros(mas, razm, x, y);
        }

        system("cls");
    }
    else
    {
       
        printf_s("Введите еще раз\n");
        atak(mas, razm);
    }
   
}
//работа с границами
int upper_left_corner(HANDLE hConsole, int** mas,int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        //левый вр угол
        if (i == 0 && j == 0)
        {
            if (mas[i + 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                printf_s("\t.");
                
            }
        }
    }
}
int upper_right_corner(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        //правый вр угол
         if (i == 0 && j + 1 == razm)
        {
            if (mas[i][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else 
            {
                printf_s("\t.");
                
            }
        }
    }
}
int lower_left_corner(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        //левый ниж угол
         if (i + 1 == razm && j == 0)
        {
            if (mas[i][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else 
            {
                printf_s("\t.");
                
            }
        }
    }
}
int lower_right_corner(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        //правый ниж  угол
        if (i + 1 == razm && j + 1 == razm)
        {
            if (mas[i][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                printf_s("\t.");
                
            }
        }
    }
}
int the_left_wall(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        //левая стенка 
        if (i - 1 > 0 && j == 0 && i + 1 != razm)
        {
            if (mas[i + 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i = 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else 
            {
                printf_s("\t.");
                
            }
        }
    }
}
int the_right_wall(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        //правая стенка
        if (i - 1 > 0 && j + 1 == razm && i + 1 != razm)
        {
            if (mas[i - 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else 
            {
                printf_s("\t.");
                
            }
        }
    }
}
int the_upper_wall(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        //верхняя стенка
        if (i == 0 && j - 1 > -1 && j + 1 != razm)
        {
            if (mas[i][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i + 1][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else 
            {
                printf_s("\t.");
                
            }
        }
    }
}
int the_lower_wall(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        //нижняя стенка
        if (i + 1 == razm && j - 1 > 0 && j + 1 != razm)
        {
            if (mas[i][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j - 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i - 1][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (mas[i][j + 1] == -2)
            {
                printf_s("\t%d", mas[i][j]);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else 
            {
                printf_s("\t.");
                
            }
        }
    }
    
}
int nothing(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
        if (i == 0 && j == 0)
        {
           
        }
        else if (i == 0 && j + 1 == razm)
        {
            
        }
        else if (i + 1 == razm && j == 0)
        {
           
        }
        else if (i + 1 == razm && j + 1 == razm)
        {
            
        }
        else if (i - 1 > 0 && j == 0 && i + 1 != razm)
        {
            
        }
        else if (i - 1 > 0 && j + 1 == razm && i + 1 != razm)
        {
           
        }
        else if (i == 0 && j - 1 > -1 && j + 1 != razm)
        {
           
        }
        else if (i + 1 == razm && j - 1 > 0 && j + 1 != razm)
        {
            
        }

        else {

            printf_s("\t.");

        }
    }
}
int checking_the_sides_and_angles(HANDLE hConsole, int** mas, int i, int j, int razm) {
    upper_left_corner(hConsole, mas, i, j, razm);
    upper_right_corner(hConsole, mas, i, j, razm);
    lower_left_corner(hConsole, mas, i, j, razm);
    lower_right_corner(hConsole, mas, i, j, razm);
    the_left_wall(hConsole, mas, i, j, razm);
    the_right_wall(hConsole, mas, i, j, razm);
    the_upper_wall(hConsole, mas, i, j, razm);
    the_lower_wall(hConsole, mas, i, j, razm);
    nothing(hConsole, mas, i, j, razm);
}
int central_verification(HANDLE hConsole, int** mas, int i, int j, int razm) {
    if (mas[i + 1][j] == -2) {

        printf_s("\t%d", mas[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if (mas[i + 1][j + 1] == -2) {

        printf_s("\t%d", mas[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if (mas[i][j + 1] == -2) {

        printf_s("\t%d", mas[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
    }

    else if (mas[i - 1][j] == -2) {

        printf_s("\t%d", mas[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if (mas[i - 1][j - 1] == -2) {

        printf_s("\t%d", mas[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if (mas[i][j - 1] == -2) {

        printf_s("\t%d", mas[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if (mas[i + 1][j - 1] == -2) {

        printf_s("\t%d", mas[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if (mas[i - 1][j + 1] == -2) {

        printf_s("\t%d", mas[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
    }

    else {

        printf_s("\t.");

    }
}
// рисует поле
int draws_a_field(HANDLE hConsole, int** mas, int x, int y,int razm) {
    
    for (int c = 0; c < x; c++)
    {
        printf_s("\t%d", c);
    }
    printf_s("\n");
    for (int i = 0; i < x; i++) {

        printf_s("%d ", i);
        for (int j = 0; j < y; j++) {

             if (mas[i][j] == -3) {
                 The_end_of_the_game(hConsole, razm, mas);
             }
             else  if (mas[i][j] ==-6) {
                 printf_s("\t0");
             }
             else  if (mas[i][j] == -4 || mas[i][j] == -5) {
                 SetConsoleTextAttribute(hConsole, 11);
                 printf_s("\t#");
                 SetConsoleTextAttribute(hConsole, 7);
                 
             }
             else if (mas[i][j] == -2) {
                SetConsoleTextAttribute(hConsole, 10);
                printf_s("\t#");
                SetConsoleTextAttribute(hConsole, 7);
            }  
            else if ((i - 1 < -1 || j - 1 < -1 || j + 1 == razm || i + 1 == razm) && mas[i][j] != -1) {
                 checking_the_sides_and_angles(hConsole, mas, i, j, razm);
            }
            else if (i - 1 > -1 && j - 1 > -1 && i + 1 < razm && j + 1 < razm && mas[i][j] != -1 ) {
                 central_verification(hConsole, mas, i, j, razm);
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
    for (int i = 0; i <= razmer; i++) {
        int p, h;
        p = rand() % razmer;
        h = rand() % razmer;
        mass[p][h] = -1;
    }
    Checking_mines( mass, razmer);
    int an_endless_loop = 0;
    while (an_endless_loop != 1)
    {
        draws_a_field(hConsole, mass, x, y, razmer);
        atak(mass, razmer);
    }
    for (int i = 0; i < razmer; i++) {
        free(mass[i]);
    }
    free(mass);
    return 0;
}