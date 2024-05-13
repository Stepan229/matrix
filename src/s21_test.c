#include "test.h"

int main() {
  Suite *cases[] = {create_matrix(),    eq_matrix(),      remove_matrix(),
                    sum_matrix(),       sub_matrix(),     mult_number(),
                    mult_matrix(),      transpose(),      determinant(),
                    calc_complements(), inverse_matrix(), NULL};

  for (Suite **current_testcase = cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
  return 0;
}

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}
