#include "../libchessviz/board.h"
#include "../libchessviz/chess_defines.h"
#include "../libchessviz/html_printer.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int chessboard[8][8];

int main(int argc, char **argv)
{
    if(argc == 0) {
    	fprintf("Error: Incorrect use. Use: chessviz <file>");
    	return 1;
    }
    
    FILE* moves = fopen(argv);
    
    if(moves == NULL) {
    	fprintf("Error: Cant open file");
    	return 2;
    }
    
    fillChessboard(chessboard);
    mkdir("result", 0750);
    printChessboard(chessboard, fopen("result/1.html", "w"));
}
