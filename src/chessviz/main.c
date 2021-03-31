#include <libchessviz/board.h>
#include <libchessviz/chess_defines.h>
#include <libchessviz/html_printer.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <sys/stat.h>
#include <sys/types.h>

int chessboard[8][8];

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Error: Incorrect use. Use: chessviz <file>\n");
        return 1;
    }

    FILE* moves = fopen(argv[1], "r");

    if (moves == NULL) {
        printf("Error: Cant open file");
        return 2;
    }
    
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = getline(&line, &len, moves);
    
    if(nread == -1) {
    	printf("Error - empty file");
    	return 3;
    }
    
    regex_t move_regex;
    regmatch_t groupArray[10];
    
    
    if (regcomp(&move_regex, "(\\d+)\\.\\s([a-f])([1-8])-([a-f])([1-8])\\s([a-f])([1-8])-([a-f])([1-8])", REG_EXTENDED)) {
        fprintf(stderr, "Could not compile regex\n");
        return 4;
    }
    
    int reti = regexec(&move_regex, line, 10, groupArray, 0);
    if(reti != 0) {
    	printf("Error on executing regex");
    	return 5;
    }
    
    char *movenumber_char = new char[groupArray[1].rm_eo - groupArray[1].rm_so + 1]
    movenumber_char[groupArray[1].rm_so] = 0
    
    for(int i = 0; i < groupArray[1].rm_eo - groupArray[1].rm_so + 1; i++) {
    	movenumber_char[i] = line[groupArray[1].rm_so + i]
    }
    
    int move_number;
    sscanf(movenumber_char, "%d", &move_number);
    
    printf("READED FILE. FIRST NUMBER IS %d", move_number);

    fillChessboard(chessboard);
    mkdir("result", 0750);
    printChessboard(chessboard, fopen("result/1.html", "w"));
}
