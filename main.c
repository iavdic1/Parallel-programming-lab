#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include "sum_algorithms.h"

#define ORDERS_OF_MAGNITUDE 1.0e9

void cpu_timer_start(struct timespec *tstart_cpu) {
clock_gettime(CLOCK_MONOTONIC, tstart_cpu);
}

double cpu_timer_stop(struct timespec tstart_cpu) {
struct timespec tstop_cpu;

clock_gettime(CLOCK_MONOTONIC, &tstop_cpu);

double result = (double)(tstop_cpu.tv_sec - tstart_cpu.tv_sec)
+ (double)(tstop_cpu.tv_nsec - tstart_cpu.tv_nsec) * 1.0e-9;

return result;
}

int main(int argc, char *argv[]) {

printf("========================================\n");
printf("Lab 5 - Summation methods\n");

for (int pow_of_two = 10; pow_of_two <= 27; pow_of_two++) {

long ncells = (long)pow(2.0, (double)pow_of_two);
long ncellsdiv2 = ncells / 2;

printf("\n========================================\n");
printf("TESTING WITH 2^%d = %ld elements\n", pow_of_two, ncells);
printf("========================================\n");

double high_value = 1.0e-1;
double low_value = 1.0e-1 / ORDERS_OF_MAGNITUDE;

double accurate_sum = (double)ncellsdiv2 * high_value
+ (double)ncellsdiv2 * low_value;

double *energy = malloc(ncells * sizeof(double));

if (energy == NULL) {
printf("Memory allocation failed\n");
return 1;
}

for (long i = 0; i < ncells; i++) {
energy[i] = (i < ncellsdiv2) ? high_value : low_value;
}

printf("Expected sum: %.16g\n\n", accurate_sum);

double test_sum;
long double long_result;
struct timespec cpu_timer;
double cpu_time;

cpu_timer_start(&cpu_timer);
test_sum = do_sum(energy, ncells);
cpu_time = cpu_timer_stop(cpu_timer);

printf("Standard double\n");
printf("Sum: %.16g\n", test_sum);
printf("Error: %.10g\n", fabs(test_sum - accurate_sum));
printf("Runtime: %lf seconds\n\n", cpu_time);

cpu_timer_start(&cpu_timer);
long_result = do_long_double_sum(energy, ncells);
cpu_time = cpu_timer_stop(cpu_timer);

printf("Long double\n");
printf("Sum: %.16Lg\n", long_result);
printf("Error: %.10Lg\n",
fabsl(long_result - (long double)accurate_sum));
printf("Runtime: %lf seconds\n\n", cpu_time);

cpu_timer_start(&cpu_timer);
test_sum = do_pair_sum(energy, ncells);
cpu_time = cpu_timer_stop(cpu_timer);

printf("Pairwise\n");
printf("Sum: %.16g\n", test_sum);
printf("Error: %.10g\n", fabs(test_sum - accurate_sum));
printf("Runtime: %lf seconds\n\n", cpu_time);

cpu_timer_start(&cpu_timer);
test_sum = do_kahan_sum(energy, ncells);
cpu_time = cpu_timer_stop(cpu_timer);

printf("Kahan\n");
printf("Sum: %.16g\n", test_sum);
printf("Error: %.10g\n", fabs(test_sum - accurate_sum));
printf("Runtime: %lf seconds\n\n", cpu_time);

cpu_timer_start(&cpu_timer);
test_sum = do_knuth_sum(energy, ncells);
cpu_time = cpu_timer_stop(cpu_timer);

printf("Knuth\n");
printf("Sum: %.16g\n", test_sum);
printf("Error: %.10g\n", fabs(test_sum - accurate_sum));
printf("Runtime: %lf seconds\n\n", cpu_time);

free(energy);
}

printf("========================================\n");
printf("All tests complete!\n");

return 0;
}