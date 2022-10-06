#include <stdio.h>

int __attribute__((optimize("O0"))) start_level(int level = 0);

int __attribute__((optimize("O0"))) end_level();

size_t __attribute__((optimize("O0"))) add_approx(size_t start_address, size_t end_address, int id = 0);

size_t __attribute__((optimize("O0"))) remove_approx(size_t start_address, size_t end_address);

double __attribute__((optimize("O0"))) set_read_ber(double read_ber, 		int a = 0, int b = 0, int c = 0);

double __attribute__((optimize("O0"))) set_write_ber(double write_ber, 		int a = 0, int b = 0, int c = 0, int d = 0);

int __attribute__((optimize("O0"))) set_bit_depth(int bit_depth, 			int a = 0, int b = 0, int c = 0, int d = 0, int e = 0);

double __attribute__((optimize("O0"))) get_read_ber(double *read_ber, 		int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0);

double __attribute__((optimize("O0"))) get_write_ber(double *write_ber, 	int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0);

int __attribute__((optimize("O0"))) get_bit_depth(int *bit_depth, 			int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0, int h = 0);