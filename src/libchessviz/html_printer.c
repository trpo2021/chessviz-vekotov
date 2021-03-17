#include "html_printer.h"
#include "chess_defines.h"
#include <stdio.h>

void printFigure(int figure, FILE* file)
{
    switch (figure) {
    case EMPTY:
        fprintf(file, " ");
        break;
    case WHITE + PAWN:
        fprintf(file, "&#9817;");
        break;
    case WHITE + ROOK:
        fprintf(file, "&#9814;");
        break;
    case WHITE + KNIGHT:
        fprintf(file, "&#9816;");
        break;
    case WHITE + BISHOP:
        fprintf(file, "&#9815;");
        break;
    case WHITE + QUEEN:
        fprintf(file, "&#9812;");
        break;
    case WHITE + KING:
        fprintf(file, "&#9813;");
        break;
    case BLACK + PAWN:
        fprintf(file, "&#9823;");
        break;
    case BLACK + ROOK:
        fprintf(file, "&#9820;");
        break;
    case BLACK + KNIGHT:
        fprintf(file, "&#9822;");
        break;
    case BLACK + BISHOP:
        fprintf(file, "&#9821;");
        break;
    case BLACK + QUEEN:
        fprintf(file, "&#9818;");
        break;
    case BLACK + KING:
        fprintf(file, "&#9819;");
        break;
    }
}

void printChessboard(int chessboard[8][8], FILE* html_file)
{
    fprintf(html_file, "<html><body><table border='1'>");
    for (int n = 0; n < 8; n++) {
        fprintf(html_file, "<tr>");
        for (int m = 0; m < 8; m++) {
            fprintf(html_file, "<td height='65' style='font-size: 50px'>");
            printFigure(chessboard[n][m], html_file);
            fprintf(html_file, "</td>");
        }
        fprintf(html_file, "</tr>");
    }
    fprintf(html_file, "</table></body></html>");
}
