CC=gcc -Wall -Werror -Wextra
EXE=s21_cat

all: s21_cat

clean: 
	rm -rf $(EXE)

rebuild: clean all

s21_cat: s21_cat.c s21_cat_functions.c
	$(CC) -o $(EXE) s21_cat.c s21_cat_functions.c

f: s21_cat.c s21_cat_functions.c
	$(CC) -o $(EXE) s21_cat.c s21_cat_functions.c -fsanitize=address
