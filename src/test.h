#include "check.h"
#include "s21_matrix.h"

Suite *create_matrix(void);
Suite *eq_matrix(void);
Suite *remove_matrix(void);
Suite *sum_matrix(void);
Suite *sub_matrix(void);
Suite *mult_number(void);
Suite *mult_matrix(void);
Suite *transpose(void);
Suite *determinant(void);
Suite *calc_complements(void);
Suite *inverse_matrix(void);

void run_testcase(Suite *testcase);