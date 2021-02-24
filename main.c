#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "chess_defines.h"
#include "html_printer.h"

int chessboard[8][8];
int figures[] = {ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK};

void fillChessboard(int chessboard[8][8])
{
    // Заполняем пустотой поле
    for (int n = 0; n < 8; n++) {
        for (int m = 0; m < 8; m++) {
            chessboard[n][m] = EMPTY;
        }
    }
    // Заполняем пешки
    for (int i = 0; i < 8; i++) {
        chessboard[1][i] = BLACK + PAWN;
        chessboard[6][i] = WHITE + PAWN;
    }
    // Заполняем фигуры
    for (int i = 0; i < 8; i++) {
        chessboard[0][i] = BLACK + figures[i];
        chessboard[7][i] = WHITE + figures[i];
    }
}

int main()
{
    fillChessboard(chessboard);
    mkdir("result", 0750);
    printChessboard(chessboard, fopen("result/1.html", "w"));
}
