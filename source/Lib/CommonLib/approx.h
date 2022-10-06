#include <stdio.h>

//FILE *debug;

unsigned long long __attribute__((optimize("O0"))) add_approx(unsigned long long start_address, unsigned long long end_address);

unsigned long long __attribute__((optimize("O0"))) remove_approx(unsigned long long start_address, unsigned long long end_address);

double __attribute__((optimize("O0"))) set_read_ber(double read_ber);

double __attribute__((optimize("O0"))) set_write_ber(double write_ber);

int __attribute__((optimize("O0"))) set_bit_depth(int bit_depth);

double __attribute__((optimize("O0"))) get_read_ber(double *read_ber);

double __attribute__((optimize("O0"))) get_write_ber(double *write_ber);

int __attribute__((optimize("O0"))) get_bit_depth(int *bit_depth);