#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>


// проверяет ячейку на мину (тупо конечно, ну да ладно); выход за пределы возвращает false
bool proverka_ich() {
    
    
}

// проверяет ячейку на пустоту (true), выход за пределы массива возвращает false
bool empty(int i, int j) {
 
}


// рекурсивная функция, которая открывает поля в точке попадания
void clean(int i, int j) {
    // проверим на выход за пределы массива
    if ((i >= 0) && (i < N)) {
        if ((j >= 0) && (j < N)) {
            // проверим, не было ли открыто поле раньше
            if (!open[i][j]) {
                // откроем
                open[i][j] = true;
                // если поле пустое (=0), просто пооткрываем всех его соседей
                if (matrix[i][j] == 0) {
                    clean(i - 1, j - 1);
                    clean(i - 1, j);
                    clean(i - 1, j + 1);
                    clean(i, j - 1);
                    clean(i, j + 1);
                    clean(i + 1, j - 1);
                    clean(i + 1, j);
                    clean(i + 1, j + 1);
                }
                // если не пустое (!=0) открываем только пустых (=0) соседей
                else {
                    if (empty(i - 1, j - 1)) clean(i - 1, j - 1);
                    if (empty(i - 1, j)) clean(i - 1, j);
                    if (empty(i - 1, j + 1)) clean(i - 1, j + 1);
                    if (empty(i, j - 1)) clean(i, j - 1);
                    if (empty(i, j + 1)) clean(i, j + 1);
                    if (empty(i + 1, j - 1)) clean(i + 1, j - 1);
                    if (empty(i + 1, j)) clean(i + 1, j);
                    if (empty(i + 1, j + 1)) clean(i + 1, j + 1);
                }
            }
        }
    }
}

// рисует "мину" - звездочку красного цвета
void coutmine(HANDLE hConsole) {
    SetConsoleTextAttribute(hConsole, 12);  // red text
    printf_s("* ");
    SetConsoleTextAttribute(hConsole, 7);   // white text
}

// рисует минное поле с учетом открытых и закрытых полей
// и вспомогательные оси
void draw_matrix(HANDLE hConsole) {
    SetConsoleTextAttribute(hConsole, 6);  // dark yellow text
    printf_s("  A B C D E F G H I J\n");
    SetConsoleTextAttribute(hConsole, 7);  // white text
    for (int x = 0; x < N; x++) {
        SetConsoleTextAttribute(hConsole, 6);  // dark yellow text
        printf_s("%d ", x);
        SetConsoleTextAttribute(hConsole, 7);  // white text
        for (int y = 0; y < N; y++) {
            if (open[x][y]) {
                SetConsoleTextAttribute(hConsole, 8);  // gray text
                if (matrix[x][y] == -1) coutmine(hConsole);
                else if (matrix[x][y] == 0) printf_s(". ");
                else printf(" %d ", matrix[x][y]);
                SetConsoleTextAttribute(hConsole, 7);  // white text
            }
            else {

                printf("# ");

            }
        }
        printf("\n");
    }
}

// функция завершает игру, выведя одну из двух надписей "Loser!" или "Winner!"
void fin(HANDLE hConsole, bool loser) {
    COORD coord;
    coord.X = 33;
    coord.Y = 10;
    system("cls");
    draw_matrix(hConsole);
    SetConsoleCursorPosition(hConsole, coord);
    if (loser) {
        SetConsoleTextAttribute(hConsole, 12);  // red text
        printf("L O S E R ! ! !");
        SetConsoleTextAttribute(hConsole, 7);  // white text
    }
    else {
        SetConsoleTextAttribute(hConsole, 10);  // red text
        printf_s("W I N N E R ! ! !");
        SetConsoleTextAttribute(hConsole, 7);  // white text
    }
    printf("\n\n\n\n");
    _getch();
}

// в случае проигрыша эта функция откроет все мины
void openmines() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == -1) open[i][j] = true;
        }
    }
}

// проверяет, все ли поле открыто, кроме мин (таково условие победы =)
bool checkwin() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if ((matrix[x][y] != -1) && (!open[x][y])) return false;
        }
    }
    return true;
}

int game_ch() {
    // главный игровой цикл
    while (true) {
        // чистим экран от старого рисунка
        system("cls");
        // рисуем поле
        draw_matrix(hConsole);
        printf_s("\n");
        // запрашиваем координаты удара
        printf_s("Введите координаты удара (C3): ");
        scanf_s(" %c", s);
        // переводим координаты в цифровой вид
        if ((s[0] >= 65) && (s[0] <= 74)) j = s[0] - 65;        // буква в промежутке от A до J
        else if ((s[0] >= 97) && (s[0] <= 106)) j = s[0] - 97;  // буква в промежутке от a до j
        else continue;                              // если введены неверные значения, возврат в начало цикла
        if ((s[1] >= 48) && (s[1] <= 57)) i = s[1] - 48;
        else continue;
        // далее проверяем все восемь окрестных полей на пустые клетки
        // и если надо показываем некий кусок поля (ну, много пустых клеток, например)
        clean(i, j);

        if (mine(i, j)) { openmines(); fin(hConsole, true); break; }  // программа покидает цикл в случае проигрыша
        if (checkwin()) { fin(hConsole, false); break; }                 // или победы
    }
}