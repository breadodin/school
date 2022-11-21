#include "s21_cat.h"

int main(int argc, char *argv[]) {
  if (argc > 1)
    cat(argc, argv);
  else
    printf("usage: cat [-benstuv] [file ...]\n");
  return 0;
}

void cat(int argc, char *argv[]) {
  Flags flags;
  onFlags(&flags);

  int i = 1;
  int errcheck = 0;

  for (; i < argc; ++i) {
    if (strspn(argv[i], "-") == 0)
      break;
    if (getFlags(argv[i], &flags) == 1)
      errcheck = 1;
  }

  if (flags.b)
    flags.n = 0;
  if (!errcheck && i == argc) {
    printf("usage: cat [-benstuv] [file ...]\n");
  }

  for (; !errcheck && i < argc; ++i) {
    FILE *filename = fopen(argv[i], "r");
    if (filename) {
      int I_line = 1;
      int ALL_lines = 1;
      char chefore = '\n'; // <-
      char chafter = ' ';  // ->
      char buffer[BUFFER] = {'\0'};

      while ((*buffer = fgetc(filename)) != EOF) {
        if (flags.s && flag_s(chefore, chafter, *buffer)) {continue;}
        if (flags.n) {
          I_line = flag_n(I_line, &ALL_lines, *buffer);
        }
        if (flags.b) {
          flag_b(chefore, &ALL_lines, *buffer);
        }
        if (flags.E) {flag_E(*buffer);}
        if (flags.T && flag_T(*buffer)) {continue;}
        chafter = chefore;
        chefore = *buffer;
        if (*buffer == '\0') {
          fputc(*buffer, stdout);
        } else {
          fputs(buffer, stdout);
          memset(buffer, '\0', BUFFER);
        }
      }
      fclose(filename);
    } else {
      printf("cat: %s: No such file or directory\n", argv[i]);
    }
    fclose(filename);
  }
  if (errcheck) {
    printf("cat: illegal option -- %s.\nusage: cat [-benstuv] [file ...]\n", argv[i - 1]);
  }
}
int onFlags(Flags *flags) {
  flags->s = 0;
  flags->n = 0;
  flags->b = 0;
  flags->E = 0;
  flags->T = 0;
  flags->v = 0;
  // flags->e = 0;
  // flags->t = 0;
  return 1;
}

int getFlags(char *argv, Flags *flags) {
  int errcheck = 0;
  if (strlen(argv) == 1 || strlen(argv) != strspn(argv, "-snbETvet")) {
    errcheck = 1;
  } else {
    if (strchr(argv, 's'))
      flags->s = 1;
    if (strchr(argv, 'b'))
      flags->b = 1;
    if (strchr(argv, 'n'))
      flags->n = 1;
    if (strchr(argv, 'T'))
      flags->T = 1;
    if (strchr(argv, 'E'))
      flags->E = 1;
  }
  return errcheck;
}

int flag_s(char chefore, char chafter, char buffer) {
  return buffer == '\n' && chefore == '\n' && chafter == '\n';
}

int flag_n(int I_line, int *ALL_lines, char buffer) {
  if (I_line) {
    printf("%6d\t", (*ALL_lines)++);
  }
  return buffer == '\n';
}

int flag_b(char chefore, int *ALL_lines, char buffer) {
  if (chefore == '\n' && buffer != '\n') {
    printf("%6d\t", (*ALL_lines)++);
  }
  return buffer == '\n';
}

int flag_E(char buffer) {
    if (buffer == '\n') {
        printf("$");
    }
    return buffer =='\n';
}

int flag_T(char buffer) {
    int tab;
    if (buffer == '\t') {
        tab = printf("^I");
    }
    return tab;
}

int flag_v(char *buffer) {

}