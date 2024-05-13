.PHONY: all a clean gcov_report s21_matrix remove_s21_math linter cppcheck leaks
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
LIB = s21_matrix.a
LIB_DIR = functions/*.c
LIB_DIR_TEST = test/*.c
FUNC =  *.c
GCOV_FLAG = -fprofile-arcs -ftest-coverage
LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread 
D_OS = -D __My_Linux__
SUITE_CASES_C = test/suite_*.c
FLAG_COV = --coverage
FLAG_TESTS = -lcheck -lm -lgcov -lsubunit
OS = $(shell uname -s)


ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D __My_Linux__
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D __My_APPLE__
endif

all: s21_matrix.a

s21_matrix.a:
	$(CC) $(D_OS) -c $(FLAGS) $(LIB_DIR)
	ar -rcs $(LIB) *.o
	rm -rf *.o


clang:
	# cp ../materials/linters/.clang-format .
	# clang-format -n *.c *.h 
	cp ../materials/linters/.clang-format functions/
	clang-format -n $(LIB_DIR) *.c
	# cp ../materials/linters/.clang-format test/
	# clang-format -n LIB_DIR_TEST *.c
	

format:
	clang-format -i *.c *.h
	clang-format -i $(LIB_DIR) *.h
	clang-format -i $(LIB_DIR_TEST) *.h

test: s21_matrix.a
	$(CC) $(FLAGS) -o a.out s21_test.c $(LIB_DIR_TEST) -L. $(LIB) $(LIBS_FOR_CHECK_PCKG) -o test-functions.out
	valgrind --leak-check=full ./test-functions.out
	# ./test-functions.out

gcov_report:
	$(CC) $(FLAGS) -o test-functions.out s21_test.c $(LIB_DIR) $(LIB_DIR_TEST) $(LIBS_FOR_CHECK_PCKG) $(GCOV_FLAG) 

	./test-functions.out
	lcov -t "test-functions" -o test-functions.info -c -d .
	rm -rf
	genhtml -o report test-functions.info
	rm -rf *.gcda *.gcno

clean:
	rm -f *.a *.o *.so *.out $(TESTFILE) *.info *.gcno *.gcda
	rm -f *$(TEST_LIB)*.a *$(TEST_LIB)*.o
	rm -rf report
	rm -rf .clang-format
	rm -rf function/.clang-format
	rm -rf mat
	rm -rf daughted
	
daughted: clean s21_matrix.a
	gcc func_tests.c -L. $(LIB) -lm -o daughted
	./daughted