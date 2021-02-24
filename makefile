CFLAGS = -Wall -Werror -Wextra

chessviz: main.o html_printer.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) -c $(CFLAGS) -o $@ $<
	
html_printer.o: html_printer.c
	$(CC) -c $(CFLAGS) -o $@ $<	

clean:
	rm -rf *.o chessviz
