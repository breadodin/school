#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

START_TEST(s21_cat_1) {
  FILE *s21_cat_out = fopen("s21_cat_test.txt", "r");
  FILE *cat_out = fopen("cat_test.txt", "r");
  while (!feof(s21_cat_out) && !feof(cat_out)) {
    char string_21_cat[200], string_cat[200];
    fscanf(s21_cat_out, "%100s", string_21_cat);
    fscanf(cat_out, "%100s", string_cat);
    ck_assert_str_eq(string_21_cat, string_cat);
  }
  fclose(s21_cat_out);
  fclose(cat_out);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_cat_1);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
