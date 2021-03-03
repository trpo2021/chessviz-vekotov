#include "../libchessviz/board.h"
#include "../libchessviz/chess_defines.h"
#include "../libchessviz/html_printer.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int chessboard[8][8];

int main()
{
    fillChessboard(chessboard);
    mkdir("result", 0750);
    printChessboard(chessboard, fopen("result/1.html", "w"));
}