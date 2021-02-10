#include <stdio.h>

int chessboard[8][8];
int white_figures[] = {1, 2, 3, 4, 5, 3, 2, 1};
int black_figures[] = {11, 12, 13, 14, 15, 13, 12, 11};

void printFigure(int figure, FILE* file)
{
    switch (figure) {
    case -1:
        fprintf(file, " ");
        break;
    case 0:
        fprintf(file, "&#9817;");
        break;
    case 1:
        fprintf(file, "&#9814;");
        break;
    case 2:
        fprintf(file, "&#9816;");
        break;
    case 3:
        fprintf(file, "&#9815;");
        break;
    case 4:
        fprintf(file, "&#9812;");
        break;
    case 5:
        fprintf(file, "&#9813;");
        break;
    case 10:
        fprintf(file, "&#9823;");
        break;
    case 11:
        fprintf(file, "&#9820;");
        break;
    case 12:
        fprintf(file, "&#9822;");
        break;
    case 13:
        fprintf(file, "&#9821;");
        break;
    case 14:
        fprintf(file, "&#9818;");
        break;
    case 15:
        fprintf(file, "&#9819;");
        break;
    }
}

void fillChessboard(int chessboard[8][8])
{
    // Заполняем пустотой поле
    for (int n = 0; n < 8; n++) {
        for (int m = 0; m < 8; m++) {
            chessboard[n][m] = -1;
        }
    }
    // Заполняем пешки
    for (int i = 0; i < 8; i++) {
        chessboard[1][i] = 10;
        chessboard[6][i] = 0;
    }
    // Заполняем фигуры
    for (int i = 0; i < 8; i++) {
        chessboard[0][i] = black_figures[i];
        chessboard[7][i] = white_figures[i];
    }
}

void printChessboard(int chessboard[8][8])
{
    FILE* html_file;
    html_file = fopen("result.html", "w+");
    fprintf(html_file, "<html><body>");
    for (int n = 0; n < 8; n++) {
        for (int m = 0; m < 8; m++) {
            printFigure(chessboard[n][m], html_file);
        }
        fprintf(html_file, "<br>");
    }
    fprintf(html_file, "</body></html>");
}

int main()
{
    fillChessboard(chessboard);
    printChessboard(chessboard);
}
