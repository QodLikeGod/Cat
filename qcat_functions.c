#include "qcat.h"

void qcat(FILE *f, const char *table[static 256], options opt) {
  int ch = 0;
  int cnt = 0;
  int flagS = 0;
  int lst = '\n';
  while ((ch = fgetc(f)) != EOF) {
    if (lst == '\n') {
      int line = (ch == '\n' && lst == '\n') ? 1 : 0;
      if (ch == '\n') {
        if (flagS) {
          continue;
        }
      } else {
        flagS = 0;
      }
      if (line && opt.s) {
        flagS = 1;
      }
      if (opt.b) {
        if (ch != '\n') {
          printf("%6d	", ++cnt);
        }
      } else if (opt.n) {
        printf("%6d	", ++cnt);
      }
    }
    printf("%s", table[ch]);
    lst = ch;
  }
}

void parse_options(int argc, char **argv, options *opt) {
  const char *short_options = "sbnveEtT";
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};

  int op;
  while ((op = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    switch (op) {
      case 'b':
        opt->b = 1;
        break;
      case 'n':
        opt->n = 1;
        break;
      case 'e':
        opt->E = 1;
        opt->v = 1;
        break;
      case 'E':
        opt->E = 1;
        break;
      case 's':
        opt->s = 1;
        break;
      case 't':
        opt->T = 1;
        opt->v = 1;
        break;
      case 'T':
        opt->T = 1;
        break;
      case 'v':
        opt->v = 1;
        break;
      default:
        printf("Unknown flag: %c\n", op);
    }
  }
}

void cat_table(const char *table[static 256]) {
  const char *defTable[] = {
      "\00",  "\01",  "\02",  "\03",  "\04",  "\05",  "\06",  "\07",  "\b",
      "\t",   "\n",   "\v",   "\014", "\r",   "\016", "\017", "\020", "\021",
      "\022", "\023", "\024", "\025", "\026", "\027", "\030", "\031", "\032",
      "\033", "\034", "\035", "\036", "\037", " ",    "!",    "\"",   "#",
      "$",    "%",    "&",    "\'",   "(",    ")",    "*",    "+",    ",",
      "-",    ".",    "/",    "0",    "1",    "2",    "3",    "4",    "5",
      "6",    "7",    "8",    "9",    ":",    ";",    "<",    "=",    ">",
      "?",    "@",    "A",    "B",    "C",    "D",    "E",    "F",    "G",
      "H",    "I",    "J",    "K",    "L",    "M",    "N",    "O",    "P",
      "Q",    "R",    "S",    "T",    "U",    "V",    "W",    "X",    "Y",
      "Z",    "[",    "\\",   "]",    "^",    "_",    "`",    "a",    "b",
      "c",    "d",    "e",    "f",    "g",    "h",    "i",    "j",    "k",
      "l",    "m",    "n",    "o",    "p",    "q",    "r",    "s",    "t",
      "u",    "v",    "w",    "x",    "y",    "z",    "{",    "|",    "}",
      "~",    "\x7f", "\x80", "\x81", "\x82", "\x83", "\x84", "\x85", "\x86",
      "\x87", "\x88", "\x89", "\x8a", "\x8b", "\x8c", "\x8d", "\x8e", "\x8f",
      "\x90", "\x91", "\x92", "\x93", "\x94", "\x95", "\x96", "\x97", "\x98",
      "\x99", "\x9a", "\x9b", "\x9c", "\x9d", "\x9e", "\x9f", "\xa0", "\xa1",
      "\xa2", "\xa3", "\xa4", "\xa5", "\xa6", "\xa7", "\xa8", "\xa9", "\xaa",
      "\xab", "\xac", "\xad", "\xae", "\xaf", "\xb0", "\xb1", "\xb2", "\xb3",
      "\xb4", "\xb5", "\xb6", "\xb7", "\xb8", "\xb9", "\xba", "\xbb", "\xbc",
      "\xbd", "\xbe", "\xbf", "\xc0", "\xc1", "\xc2", "\xc3", "\xc4", "\xc5",
      "\xc6", "\xc7", "\xc8", "\xc9", "\xca", "\xcb", "\xcc", "\xcd", "\xce",
      "\xcf", "\xd0", "\xd1", "\xd2", "\xd3", "\xd4", "\xd5", "\xd6", "\xd7",
      "\xd8", "\xd9", "\xda", "\xdb", "\xdc", "\xdd", "\xde", "\xdf", "\xe0",
      "\xe1", "\xe2", "\xe3", "\xe4", "\xe5", "\xe6", "\xe7", "\xe8", "\xe9",
      "\xea", "\xeb", "\xec", "\xed", "\xee", "\xef", "\xf0", "\xf1", "\xf2",
      "\xf3", "\xf4", "\xf5", "\xf6", "\xf7", "\xf8", "\xf9", "\xfa", "\xfb",
      "\xfc", "\xfd", "\xfe", "\xff"};

  memcpy(table, defTable, sizeof defTable);
}

void cat_E(const char *table[static 256]) { table['\n'] = "$\n"; }

void cat_T(const char *table[static 256]) { table['\t'] = "^I"; }

void cat_v(const char *table[static 256]) {
  const char *smpl1[] = {"^@", "^A", "^B", "^C", "^D", "^E", "^F", "^G", "^H"};
  const char *smpl2[] = {"^K", "^L", "^M", "^N",  "^O", "^P", "^Q",
                         "^R", "^S", "^T", "^U",  "^V", "^W", "^X",
                         "^Y", "^Z", "^[", "^\\", "^]", "^^", "^_"};
  const char *smpl3[] = {
      "^?",   "M-^@", "M-^A",  "M-^B", "M-^C", "M-^D", "M-^E", "M-^F", "M-^G",
      "M-^H", "M-^I", "M-^J",  "M-^K", "M-^L", "M-^M", "M-^N", "M-^O", "M-^P",
      "M-^Q", "M-^R", "M-^S",  "M-^T", "M-^U", "M-^V", "M-^W", "M-^X", "M-^Y",
      "M-^Z", "M-^[", "M-^\\", "M-^]", "M-^^", "M-^_", "M- ",  "M-!",  "M-\"",
      "M-#",  "M-$",  "M-%",   "M-&",  "M-'",  "M-(",  "M-)",  "M-*",  "M-+",
      "M-,",  "M--",  "M-.",   "M-/",  "M-0",  "M-1",  "M-2",  "M-3",  "M-4",
      "M-5",  "M-6",  "M-7",   "M-8",  "M-9",  "M-:",  "M-;",  "M-<",  "M-=",
      "M->",  "M-?",  "M-@",   "M-A",  "M-B",  "M-C",  "M-D",  "M-E",  "M-F",
      "M-G",  "M-H",  "M-I",   "M-J",  "M-K",  "M-L",  "M-M",  "M-N",  "M-O",
      "M-P",  "M-Q",  "M-R",   "M-S",  "M-T",  "M-U",  "M-V",  "M-W",  "M-X",
      "M-Y",  "M-Z",  "M-[",   "M-\\", "M-]",  "M-^",  "M-_",  "M-`",  "M-a",
      "M-b",  "M-c",  "M-d",   "M-e",  "M-f",  "M-g",  "M-h",  "M-i",  "M-j",
      "M-k",  "M-l",  "M-m",   "M-n",  "M-o",  "M-p",  "M-q",  "M-r",  "M-s",
      "M-t",  "M-u",  "M-v",   "M-w",  "M-x",  "M-y",  "M-z",  "M-{",  "M-|",
      "M-}",  "M-~",  "M-^?"};

  memcpy(table, smpl1, sizeof smpl1);
  memcpy(&table[9 + 2], smpl2, sizeof smpl2);
  memcpy(&table['~' + 1], smpl3, sizeof smpl3);
}
