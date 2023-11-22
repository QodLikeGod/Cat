CC=gcc -Wall -Werror -Wextra
EXE=qcat

all: qcat

clean: 
	rm -rf $(EXE)

rebuild: clean all

qcat: qcat.c qcat_functions.c
	$(CC) -o $(EXE) qcat.c qcat_functions.c

f: qcat.c qcat_functions.c
	$(CC) -o $(EXE) qcat.c qfunctions.c -fsanitize=address


##Краткость-сестра таланта!