#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>


// ��������� ������ �� ���� (���� �������, �� �� �����); ����� �� ������� ���������� false
bool proverka_ich() {
    
    
}

// ��������� ������ �� ������� (true), ����� �� ������� ������� ���������� false
bool empty(int i, int j) {
 
}


// ����������� �������, ������� ��������� ���� � ����� ���������
void clean(int i, int j) {
    // �������� �� ����� �� ������� �������
    if ((i >= 0) && (i < N)) {
        if ((j >= 0) && (j < N)) {
            // ��������, �� ���� �� ������� ���� ������
            if (!open[i][j]) {
                // �������
                open[i][j] = true;
                // ���� ���� ������ (=0), ������ ����������� ���� ��� �������
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
                // ���� �� ������ (!=0) ��������� ������ ������ (=0) �������
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

// ������ "����" - ��������� �������� �����
void coutmine(HANDLE hConsole) {
    SetConsoleTextAttribute(hConsole, 12);  // red text
    printf_s("* ");
    SetConsoleTextAttribute(hConsole, 7);   // white text
}

// ������ ������ ���� � ������ �������� � �������� �����
// � ��������������� ���
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

// ������� ��������� ����, ������ ���� �� ���� �������� "Loser!" ��� "Winner!"
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

// � ������ ��������� ��� ������� ������� ��� ����
void openmines() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == -1) open[i][j] = true;
        }
    }
}

// ���������, ��� �� ���� �������, ����� ��� (������ ������� ������ =)
bool checkwin() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if ((matrix[x][y] != -1) && (!open[x][y])) return false;
        }
    }
    return true;
}

int game_ch() {
    // ������� ������� ����
    while (true) {
        // ������ ����� �� ������� �������
        system("cls");
        // ������ ����
        draw_matrix(hConsole);
        printf_s("\n");
        // ����������� ���������� �����
        printf_s("������� ���������� ����� (C3): ");
        scanf_s(" %c", s);
        // ��������� ���������� � �������� ���
        if ((s[0] >= 65) && (s[0] <= 74)) j = s[0] - 65;        // ����� � ���������� �� A �� J
        else if ((s[0] >= 97) && (s[0] <= 106)) j = s[0] - 97;  // ����� � ���������� �� a �� j
        else continue;                              // ���� ������� �������� ��������, ������� � ������ �����
        if ((s[1] >= 48) && (s[1] <= 57)) i = s[1] - 48;
        else continue;
        // ����� ��������� ��� ������ ��������� ����� �� ������ ������
        // � ���� ���� ���������� ����� ����� ���� (��, ����� ������ ������, ��������)
        clean(i, j);

        if (mine(i, j)) { openmines(); fin(hConsole, true); break; }  // ��������� �������� ���� � ������ ���������
        if (checkwin()) { fin(hConsole, false); break; }                 // ��� ������
    }
}