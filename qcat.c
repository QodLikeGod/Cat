#include "qcat.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: qcat [OPTION] [FILE]\n");
    return 1;
  }

  options opt = {0, 0, 0, 0, 0, 0};
  parse_options(argc, argv, &opt);
  const char *table[256];
  cat_table(table);

  if (opt.E) cat_E(table);
  if (opt.T) cat_T(table);
  if (opt.v) cat_v(table);

  for (int i = optind; i < argc; i++) {
    FILE *f = fopen(argv[i], "r");
    if (f == NULL) {
      printf("%s: No such file or directory\n", argv[i]);
      continue;
    }
    qcat(f, table, opt);
    fclose(f);
  }
  return 0;
}