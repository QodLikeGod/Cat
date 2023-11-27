# Simple Bash Utils

Development of Bash text utility: cat.

Русская версия находится в репозитории.

## Contents

1. [Information](#Information)
2. [cat History](#cat_Options) 
3. [cat Usage](#chapter-ii) 
4. [cat Options](#cat_Options) 


![simple_bash_utils](source/misc/eng/bashutils.png)

## Information

### cat History

> cat was part of the early versions of Unix, e.g., Version 1, and replaced pr, a PDP-7 and Multics utility for copying a single file to the screen. 
And this code is a monument to him! because CAT is unique!

### cat Usage

Cat is one of the most frequently used commands on Unix-like operating systems. It has three related functions with regard to text files: displaying them, combining copies of them and creating new ones.

`./s21_cat [OPTION] [FILE]...`

### cat Options

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| 3 | -n (GNU: --number) | number all output lines |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

