#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <getopt.h>
#include <stdbool.h>

#define BUFFER 8192

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
void parser(int argc, char *argv[], struct activeFlags *activeFlags, char *pattern_e);
 void grepOut(int argc, char *argv[], struct activeFlags *activeFlags, char *pattern_e);
 int file_f(char *main_pattern, char* filename);
void allHandler(struct activeFlags *activeFlags, FILE *file, regex_t regex, char *filename);
void reader(struct activeFlags *activeFlags, char *main_pattern, char *filename);

int main(int argc, char* argv[]) {
    grep(argc, argv);
    return 0;
}

void parser(int argc, char *argv[], struct activeFlags *activeFlags, char* pattern_e) {
  int opt = 0;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o" )) != -1) {
    switch (opt)
    {
    case 'e':
      activeFlags->e = true;
      snprintf(pattern_e, BUFFER, "%s", optarg); 
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
      snprintf(pattern_e, BUFFER, "%s", optarg); 
      break;
    case 'o':
      activeFlags->o = true;
      break;
    default:
      printf("usage: grep [-ivclnhso] [-e pattern] [-f file] [pattern] [file ...]\n");
      break;
    }
  }
}

void grep(int argc, char *argv[]) {
    struct activeFlags activeFlags = {false};
    char patternt_e[BUFFER] = {0}; 
    parser(argc, argv, &activeFlags, patternt_e);
    if (argc >= 3) {
    grepOut(argc, argv, &activeFlags, patternt_e);
    }
}

void grepOut(int argc, char *argv[], struct activeFlags *activeFlags, char* pattern_e) {
  char main_pattern[BUFFER] = {0};
  int f_file = 0;
  if (!activeFlags->f && !activeFlags->e) {
    snprintf(main_pattern, BUFFER, "%s", argv[optind++]);
  }
  if (activeFlags->f) {
    f_file = file_f(main_pattern, pattern_e);
  }
  if (!activeFlags->f && activeFlags->e) {
    snprintf(main_pattern, BUFFER, "%s", pattern_e);
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
      reader(activeFlags, main_pattern, argv[i]);
    }
  }
}

int file_f(char *main_pattern, char* filename) {
  int i = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file != NULL) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
      if (ch == '\0' || ch == '\n') {
        main_pattern[i++] = '|';
      }
      if (ch != '\0' && ch != '\n')  {
        main_pattern[i++] = ch;
      }
    }
  } else {
    printf("grep: file_name: No such file or directory\n");
    i = -1;
  }
  if (main_pattern[i - 1] == '|') {
    main_pattern[i - 1] = '\0';
 }
  fclose(file);
  return i;
}

void reader(struct activeFlags *activeFlags, char *main_pattern, char *filename) {
  int flags = REG_EXTENDED;
  regex_t regex;
  FILE *file;
  file = fopen(filename, "r");
  if (activeFlags->i) {
    flags = REG_ICASE;
  }
  if (file != NULL) {
    regcomp(&regex, main_pattern, flags);
    allHandler(activeFlags, file, regex, filename);
    regfree(&regex);
    fclose(file);
  }
}

void allHandler(struct activeFlags *activeFlags, FILE *file, regex_t regex, char *filename) {
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
      for (int i = match[0].rm_so ; i < match[0].rm_eo ; i++) {
        printf("%c", temp[i]);
      }
      printf("\n");
    }
    line_m += match_;
    nline++;
  }
  if(activeFlags->l && line_m > 0) {
    printf("%s\n", filename);
  }
  if (activeFlags->c && !activeFlags->l) {
    printf("%d\n", line_m);
  }
  if (activeFlags->c && activeFlags->l) {
    printf("%d\n", --line_m);
  }
}
