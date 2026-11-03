#include <stdlib.h>
#include <math.h>
#include "sum_algorithms.h"

double do_sum(double *restrict var, long ncells) {
    double sum = 0.0;

    for (long i = 0; i < ncells; i++) {
        sum += var[i];
    }

    return sum;
}

double do_pair_sum(double *restrict var, long ncells) {
    if (ncells <= 0) return 0.0;
    if (ncells == 1) return var[0];

    long nmax = ncells / 2;
    double *pwsum = malloc(nmax * sizeof(double));

    if (pwsum == NULL) {
        return NAN;
    }

    for (long i = 0; i < nmax; i++) {
        pwsum[i] = var[i * 2] + var[i * 2 + 1];
    }

    for (long j = 1; j < log2(ncells); j++) {
        nmax /= 2;

        for (long i = 0; i < nmax; i++) {
            pwsum[i] = pwsum[i * 2] + pwsum[i * 2 + 1];
        }
    }

    double sum = pwsum[0];
    free(pwsum);

    return sum;
}


long double do_long_double_sum(double *restrict var, long ncells) {
    long double sum = 0.0L;

    for (long i = 0; i < ncells; i++) {
        sum += (long double)var[i];
    }

    return sum;
}

double do_kahan_sum(double *restrict var, long ncells) {
    double sum = 0.0;
    double c = 0.0;

    for (long i = 0; i < ncells; i++) {
        double y = var[i] - c;
        double t = sum + y;

        c = (t - sum) - y;
        sum = t;
    }

    return sum;
}

double do_knuth_sum(double *restrict var, long ncells) {
    double sum = 0.0;
    double correction = 0.0;

    for (long i = 0; i < ncells; i++) {
        double x = var[i];
        double t = sum + x;

        double z = t - sum;
        double error = (sum - (t - z)) + (x - z);

        correction += error;
        sum = t;
    }

    return sum + correction;
}