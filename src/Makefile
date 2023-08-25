CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic

SOURCES = $(wildcard *.c)
TEST_SOURCES = $(wildcard test_gcov/*.c)
OBJECTS = $(SOURCES:.c=.o)

s21_math.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib s21_math.a
	rm -rf *.o

test: 
	$(CC) $(CFLAGS) $(TEST_SOURCES) -o test_gcov/test -lcheck -lsubunit -lm -lgcov
	./test_gcov/test

gcov_report:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(TEST_SOURCES) -o test_gcov/test -lcheck -lsubunit -lm -lgcov
	mkdir -p gcov_report
	./test_gcov/test
	gcovr -r . --html --html-details -o gcov_report/coverage.html
	rm -rf $(OBJECTS) s21_math.a test *.gc* test_gcov/*.gc*

clean:
	clear
	@rm -rf *.o *.a *.gc* test gcov_report

all: s21_math.a

cpp:
	@cppcheck —enable=all —suppress=missingIncludeSystem *.c

clang:
	@clang-format -n *.c *.h

valgrind:
	@valgrind ./test_gcov/test
