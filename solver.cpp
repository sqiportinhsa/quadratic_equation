#include "solver.h"

#include <cmath>
#include <stdlib.h>
#include <cassert>

enum Num_of_roots solve_quadratic_equation(double a, double b, double c, double *x1, double *x2) {

    ERROR_IF(x1 == NULL);
    ERROR_IF(x2 == NULL);

    if (is_zero(a)) {
        return solve_linear_equation(b, c, x1);
    }

    if (is_zero(b)) {
        if (is_zero(c)) {
            *x1 = 0;
            return ONE_ROOT;
        } 

        double square_x = -c / a;

        if (square_x > calc_error) {
            *x1 = sqrt(square_x);
            *x2 = -1 * (*x1);
            return TWO_ROOTS;
        } else {
            return NO_ROOTS;
        }
    }

    if (is_zero(c)) {
        *x1 = 0;
        *x2 = -b/a;
        return TWO_ROOTS;
    }
        
    double D = b*b - 4*a*c;
 
    if (is_zero(D)) {
        *x1 = -b/(2*a);
        return ONE_ROOT;
    }

    if (D < -calc_error) {
        return NO_ROOTS;
    }
    
    double D_sqrt = sqrt(D);
    *x1 = (-b + D_sqrt) / (2*a);
    *x2 = (-b - D_sqrt) / (2*a);
    return TWO_ROOTS;
}

enum Num_of_roots solve_linear_equation(double a, double b, double *x) {
    if (is_zero(a)) {
        if (is_zero(b)) {
            return INF_ROOTS;
        }
        return NO_ROOTS;
    }
    *x = -1 * b/a;
    return ONE_ROOT;
}

bool is_zero(double num) {
    return (abs(num) < calc_error);
}
