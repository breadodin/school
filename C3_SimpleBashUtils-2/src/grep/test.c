#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

START_TEST(s21_grep_1) {
  FILE *s21_grep_out = fopen("s21_grep_test.txt", "r");
  FILE *grep_out = fopen("grep_test.txt", "r");
  while (!feof(s21_grep_out) && !feof(grep_out)) {
    char string_21_grep[200], string_grep[200];
    fscanf(s21_grep_out, "%100s", string_21_grep);
    fscanf(grep_out, "%100s", string_grep);
    ck_assert_str_eq(string_21_grep, string_grep);
  }
  fclose(s21_grep_out);
  fclose(grep_out);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_grep_1);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
