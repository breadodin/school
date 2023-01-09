#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 256

typedef struct {
  int s;
  int n;
  int b;
  int E;
  int T;
  int v;
  int e;
  int t;
} Flags;

void cat(int argc, char *argv[]);
int printResult(FILE *filename, Flags flags);
int onFlags(Flags *flags);
int getFlags(char *argv, Flags *flags);
int flag_s(char ch_before, char ch_after, char buffer);
int flag_b(char chefore, int *ALL_lines, char buffer);
int flag_n(int I_line, int *ALL_lines, char buffer);
void flag_E(char buffer);
void flag_T(char buffer, int *justPrint);
void flag_v(char buffer, int *justPrint);

#endif  // SRC_CAT_S21_CAT_H_
