#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct activeFlags {
  bool i;
  bool v;
  bool c;
  bool l;
  bool n;
  bool h;
  bool s;
  bool o;
  bool err;
  bool e;
  bool f;
} activeFlags;

void grep(int argc, char *argv[]);
void parser(int argc, char *argv[], struct activeFlags *activeFlags, char *E);
void grepOut(int argc, char *argv[], struct activeFlags *activeFlags, char *E);
int file_f(char *thePattern, char *filename);
void allHandler(struct activeFlags *activeFlags, FILE *file, regex_t regex,
                char *filename);
void reader(struct activeFlags *activeFlags, char *thePattern, char *filename);

#endif  // SRC_GREP_S21_GREP_H_
