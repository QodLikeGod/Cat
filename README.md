# Simple Bash Util

Development of Bash text utility: cat.

Русская версия находится в репозитории.

## Contents

1. [Information](#Information)
2. [cat History](#cat_History) 
3. [cat Usage](#cat_Usage) 
4. [cat Options](#cat_Options)
5. [Cat Test](#Cat_Test)

![(^_^)](misc/eng/meow.png)

## Information

### cat_History

> cat was part of the early versions of Unix, e.g., Version 1, and replaced pr, a PDP-7 and Multics utility for copying a single file to the screen. 
And this code is a monument to him! because CAT is unique!

### cat_Usage

Cat is one of the most frequently used commands on Unix-like operating systems. It has three related functions with regard to text files: displaying them, combining copies of them and creating new ones.

`cat [OPTION] [FILE]...`

### cat_Options

| No. | Options | Description |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| 3 | -n (GNU: --number) | number all output lines |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

### Cat_Tests

If you want to test 

sh ./test_cat/test_func_qcat.sh
