#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 256

typedef struct {
  int s; // Squeeze multiple adjacent empty lines, causing the output to be
         // single spaced.
  int n; // Number the output lines, starting at 1.
  int b; // Number the non-blank output lines, starting at 1.
  int E; // Display a dollar sign (`$') at the end of each line.
  int T; // Display tab characters as `^I'.
  int v; // Display non-printing characters so they are visible
  int e; // Display non-printing characters (see the -v option), and display a
         // dollar sign (`$') at the end of each line.
  int t; // Display non-printing characters (see the -v option), and display tab
         // characters as `^I'.
} Flags;

void cat(int argc, char *argv[]);
int onFlags(Flags *flags);
int getFlags(char *argv, Flags *flags);
int flag_s(char ch_before, char ch_after, char buffer);
int flag_b(char chefore, int *ALL_lines, char buffer);
int flag_n(int I_line, int *ALL_lines, char buffer);
int flag_E(char buffer);
int flag_T(char buffer);
int flag_v(char *buffer);



#endif // SRC_CAT_S21_CAT_H_