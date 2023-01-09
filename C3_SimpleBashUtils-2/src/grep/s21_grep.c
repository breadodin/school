#include "s21_grep.h"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    grep(argc, argv);
  } else {
    printf(
        "usage: grep [-ivclnhso] [-e pattern] [-f file] [pattern] [file "
        "...]\n");
  }
  return 0;
}

void parser(int argc, char *argv[], struct activeFlags *activeFlags, char *E) {
  int opt = 0;
  while ((opt = getopt(argc, argv, "e:f:ivclnhso")) != -1) {
    switch (opt) {
      case 'e':
        activeFlags->e = true;
        snprintf(E, BUFSIZ, "%s", optarg);
        E += BUFSIZ;
        break;
      case 'i':
        activeFlags->i = true;
        break;
      case 'v':
        activeFlags->v = true;
        break;
      case 'c':
        activeFlags->c = true;
        break;
      case 'l':
        activeFlags->l = true;
        break;
      case 'n':
        activeFlags->n = true;
        break;
      case 'h':
        activeFlags->h = true;
        break;
      case 's':
        activeFlags->s = true;
        break;
      case 'f':
        activeFlags->f = true;
        snprintf(E, BUFSIZ, "%s", optarg);
        E += BUFSIZ;
        break;
      case 'o':
        activeFlags->o = true;
        break;
      case '?':
        activeFlags->err = true;
        printf(
            "usage: grep [-ivclnhso] [-e pattern] [-f file] [pattern] [file "
            "...]\n");
        break;
      default:
        printf(
            "usage: grep [-ivclnhso] [-e pattern] [-f file] [pattern] [file "
            "...]\n");
        break;
    }
  }
}

void grep(int argc, char *argv[]) {
  struct activeFlags activeFlags = {false};
  char chE[BUFSIZ] = {0};
  parser(argc, argv, &activeFlags, chE);
  if (argc >= 3) {
    grepOut(argc, argv, &activeFlags, chE);
  }
}

void grepOut(int argc, char *argv[], struct activeFlags *activeFlags, char *E) {
  char thePattern[BUFSIZ] = {0};
  int f_file = 0;
  if (!activeFlags->f && !activeFlags->e) {
    snprintf(thePattern, BUFSIZ, "%s", argv[optind++]);
  }
  if (activeFlags->f) {
    f_file = file_f(thePattern, E);
  }
  if (!activeFlags->f && activeFlags->e) {
    snprintf(thePattern, BUFSIZ, "%s", E);
  }
  if (f_file != -1) {
    int file = 0;
    if (argc - optind > 1) {
      file = 1;
    }
    for (int i = optind; i < argc; i++) {
      if (file && !activeFlags->h && !activeFlags->l) {
        printf("grep: %s:", argv[i]);
      }
      reader(activeFlags, thePattern, argv[i]);
    }
  }
}

int file_f(char *thePattern, char *filename) {
  int i = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file != NULL) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
      if (ch == '\0' || ch == '\n') {
        thePattern[i++] = '|';
      }
      if (ch != '\0' && ch != '\n') {
        thePattern[i++] = ch;
      }
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename);
    i = -1;
  }
  if (thePattern[i - 1] == '|') {
    thePattern[i - 1] = '\0';
  }
  fclose(file);
  return i;
}

void reader(struct activeFlags *activeFlags, char *thePattern, char *filename) {
  int flags = REG_EXTENDED;
  regex_t regex;
  FILE *file;
  file = fopen(filename, "r");
  if (activeFlags->i) {
    flags = REG_ICASE;
  }
  if (file != NULL) {
    regcomp(&regex, thePattern, flags);
    allHandler(activeFlags, file, regex, filename);
    regfree(&regex);
    fclose(file);
  }
}

void allHandler(struct activeFlags *activeFlags, FILE *file, regex_t regex,
                char *filename) {
  char temp[BUFSIZ * 10] = {0};
  regmatch_t match[2];
  int line_m = 0, nline = 1;
  while (fgets(temp, BUFSIZ - 1, file) != NULL) {
    int match_ = 0;
    int success = regexec(&regex, temp, 1, match, 0);
    if (strchr(temp, '\n') == NULL) {
      strcat(temp, "\n");
    }
    if (success == 0 && !activeFlags->v) {
      match_ = 1;
    }
    if (success == REG_NOMATCH && activeFlags->v) {
      match_ = 1;
    }
    if (match_ && !activeFlags->l && !activeFlags->c && activeFlags->n) {
      printf("%d:", nline);
    }
    if (match_ && !activeFlags->l && !activeFlags->c && !activeFlags->o) {
      printf("%s", temp);
    }
    if (match_ && activeFlags->o) {
      for (int i = match[0].rm_so; i < match[0].rm_eo; i++) {
        printf("%c", temp[i]);
      }
      printf("\n");
    }
    line_m += match_;
    nline++;
  }
  if (activeFlags->l && line_m > 0) {
    printf("%s\n", filename);
  }
  if (activeFlags->c && !activeFlags->l) {
    printf("%d\n", line_m);
  }
  if (activeFlags->c && activeFlags->l) {
    printf("%d\n", --line_m);
  }
}
