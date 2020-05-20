CC = g++
CFLAGS = -lglut -lGLU -lGL
EXEC = programm
OBJ = programm.o

EXEC : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS)

programm.o : programm.cpp programm.h
	$(CC) programm.cpp -c $(CFLAGS)

clean :
	rm -f $(OBJ) $(EXEC)
