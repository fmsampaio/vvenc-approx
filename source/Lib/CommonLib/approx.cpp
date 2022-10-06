#include <stdio.h>
#include "approx.h"

//FILE *debug;

unsigned long long __attribute__((optimize("O0"))) add_approx(unsigned long long start_address, unsigned long long end_address)
{
    //	debug = fopen("/tmp/memapproxlog", "w");
    //	fprintf(debug, "%s %llu %llu\n", "add_approx", start_address, end_address);
    //	fclose(debug);
    return end_address - start_address;
}

unsigned long long __attribute__((optimize("O0"))) remove_approx(unsigned long long start_address, unsigned long long end_address)
{
    //	debug = fopen("/tmp/memapproxlog", "w");
    //	fprintf(debug, "%s %llu %llu\n", "remove_approx", start_address, end_address);
    //	fclose(debug);
    return end_address - start_address;
}

double __attribute__((optimize("O0"))) set_read_ber(double read_ber)
{
    //	debug = fopen("/tmp/memapproxlog", "w");
    //	fprintf(debug, "%s %f\n", "set_read_ber", read_ber);
    //	fclose(debug);
    return read_ber;
}

double __attribute__((optimize("O0"))) set_write_ber(double write_ber)
{
    //	debug = fopen("/tmp/memapproxlog", "w");
    //	fprintf(debug, "%s %f\n", "set_write_ber", write_ber);
    //	fclose(debug);
    return write_ber;
}

int __attribute__((optimize("O0"))) set_bit_depth(int bit_depth)
{
    //	debug = fopen("/tmp/memapproxlog", "w");
    //	fprintf(debug, "%s %d\n", "set_bit_depth", bit_depth);
    //	fclose(debug);
    return bit_depth;
}

double __attribute__((optimize("O0"))) get_read_ber(double *read_ber)
{
    //	debug = fopen("/tmp/memapproxlog", "w");
    //	fprintf(debug, "%s %f\n", "get_read_ber", *read_ber);
    //	fclose(debug);
    return *read_ber;
}

double __attribute__((optimize("O0"))) get_write_ber(double *write_ber)
{
    //	debug = fopen("/tmp/memapproxlog", "w");
    //	fprintf(debug, "%s %f\n", "get_write_ber", *write_ber);
    //	fclose(debug);
    return *write_ber;
}

int __attribute__((optimize("O0"))) get_bit_depth(int *bit_depth)
{
    //	debug = fopen("/tmp/memapproxlog", "w");
    //	fprintf(debug, "%s %d\n", "set_bit_depth", bit_depth);
    //	fclose(debug);
    return *bit_depth;
}