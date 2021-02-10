#include <stdio.h>

char chessboard[8][8];
char figures[] = {'r', 'k', 'b', 'K', 'Q', 'b', 'k', 'r'};

void fillChessboard(char chessboard[8][8])
{
    // Заполняем пустотой поле
    for (int n = 0; n < 8; n++) {
        for (int m = 0; m < 8; m++) {
            chessboard[n][m] = ' ';
        }
    }
    // Заполняем пешки
    for (int i = 0; i < 8; i++) {
        chessboard[1][i] = 'p';
        chessboard[6][i] = 'p';
    }
    // Заполняем фигуры
    for (int i = 0; i < 8; i++) {
        chessboard[0][i] = figures[i];
        chessboard[7][i] = figures[i];
    }
}

int main()
{
    fillChessboard(chessboard);
}
