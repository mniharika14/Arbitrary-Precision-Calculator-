OBJ = $(patsubst %.c, %.o, $(wildcard *.c))
result.exe : $(OBJ)
	gcc -o $@ $^
clean :
	rm *.exe *.o
