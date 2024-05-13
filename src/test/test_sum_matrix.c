#include "../test.h"

START_TEST(sum_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t C1;
  matrix_t D;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &D);

  char str1[] = "3.123 2.123 1.1231 2.123";
  char str2[] = "3.123 2.123 1.1231 2.123";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 0);
  s21_sub_matrix(&C, &C, &C1);
  ck_assert_int_eq(s21_eq_matrix(&C1, &D), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&C1);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;

  s21_create_matrix(2, 4, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t C1;
  matrix_t D;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(2, 3, &D);

  char str1[] = "3.123 2.123 1.1231 2.123 7 9.123";
  char str2[] = "3.123 2.123 1.1231 2.123 7 9.123";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 0);
  s21_sub_matrix(&C, &C, &C1);
  ck_assert_int_eq(s21_eq_matrix(&C1, &D), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&C1);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t C1;
  matrix_t D;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(3, 2, &D);

  char str1[] = "2.123 7 9.123 3.123 2.123 1.1231";
  char str2[] = "2.123 7 9.123 3.123 2.123 1.1231";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 0);
  s21_sub_matrix(&C, &C, &C1);
  ck_assert_int_eq(s21_eq_matrix(&C1, &D), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&C1);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sum_matrix_5) {
  ck_assert_int_eq(s21_sum_matrix(NULL, NULL, NULL), 1);
}
END_TEST

Suite *sum_matrix(void) {
  Suite *s = suite_create("sum_matrix");
  TCase *tc = tcase_create("sum_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);
  tcase_add_test(tc, sum_matrix_4);
  tcase_add_test(tc, sum_matrix_5);

  return s;
}