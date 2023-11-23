#ifndef QCAT_H
#define QCAT_H

#include <getopt.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int n;
  int E;
  int s;
  int T;
  int v;
  int b;
} options;

void qcat(FILE *f, const char *table[static 256], options opt);
void parse_options(int argc, char **argv, options *opt);
void cat_table(const char *table[static 256]);
void cat_E(const char *table[static 256]);
void cat_T(const char *table[static 256]);
void cat_v(const char *table[static 256]);

#endif
