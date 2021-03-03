CFLAGS = -Wall -Werror -Wextra
CHESSVIZ_SRC = src/chessviz/
LIBCHESSVIZ_SRC = src/libchessviz/

CHESSVIZ_OBJ = obj/src/chessviz/
LIBCHESSVIZ_OBJ = obj/src/libchessviz/

CHESSVIZ_BIN = bin/

$(CHESSVIZ_BIN)chessviz: $(CHESSVIZ_OBJ)main.o $(LIBCHESSVIZ_OBJ)libchessviz.a
	$(CC) $(CFLAGS) -o $@ $^

$(CHESSVIZ_OBJ)main.o: $(CHESSVIZ_SRC)main.c
	$(CC) -c $(CFLAGS) -o $@ $<
	
$(LIBCHESSVIZ_OBJ)libchessviz.a: $(LIBCHESSVIZ_OBJ)html_printer.o $(LIBCHESSVIZ_OBJ)board.o
	ar rcs $@ $^

$(LIBCHESSVIZ_OBJ)html_printer.o: $(LIBCHESSVIZ_SRC)html_printer.c
	$(CC) -c $(CFLAGS) -o $@ $<
	
$(LIBCHESSVIZ_OBJ)board.o: $(LIBCHESSVIZ_SRC)board.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(CHESSVIZ_OBJ)*.o 
	rm -rf $(LIBCHESSVIZ_OBJ)*.o
	rm -rf $(LIBCHESSVIZ_OBJ)*.a
	rm -rf $(CHESSVIZ_BIN)chessviz
