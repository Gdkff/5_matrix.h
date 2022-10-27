.PHONY: all, clean, test, s21_matrix.a, gcov_report

LIBS_ADDITIONAL = 
ifeq ($(OS), Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname -s)
endif

ifeq ($(detected_OS), Linux)
	detected_Linux := $(shell cat /etc/issue | sed -n '1p' | awk '{print $$1}')
	ifeq ($(detected_Linux), Arch)
	LIBS_ADDITIONAL = -lm
	endif

	ifeq ($(detected_Linux), Ubuntu)
	LIBS_ADDITIONAL = -lm -lsubunit
	endif
	
	ifeq ($(detected_Linux), Debian)
	LIBS_ADDITIONAL = -lm -lsubunit
	endif
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SOURCES = s21_*.c
OBJECTS = s21_*.o
TESTEXEC = tests/test

ALLPROJECT = tests/*.c *.c *.h

all: s21_matrix.a

s21_matrix.a: clean
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rcs s21_matrix.a $(OBJECTS)
	rm -f *.o

test: clean s21_matrix.a
	$(CC) $(CFLAGS) -c tests/test_*.c
	$(CC) $(CFLAGS) test_*.o --coverage $(SOURCES) -o $(TESTEXEC) -lcheck $(LIBS_ADDITIONAL)
	./$(TESTEXEC)
	gcov tests/test-s21_*.gcda

gcov_report: test
	gcovr -b
	gcovr
	gcovr --html-details -o tests/report.html
	find . -name '*.gcno' -type f -delete
	find . -name '*.gcda' -type f -delete

check:
	cppcheck --enable=all --force --check-config for details $(ALLPROJECT)
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c $(ALLPROJECT)

clean:
	find . -name '*.gcno' -type f -delete
	find . -name '*.gcda' -type f -delete
	find . -name '*.gcov' -type f -delete
	find . -name '*.a' -type f -delete
	find . -name '*.o' -type f -delete
	find . -name '*.info' -type f -delete
	find . -name '*.html' -type f -delete
	find . -name '*.css' -type f -delete
	rm -f $(TESTEXEC)