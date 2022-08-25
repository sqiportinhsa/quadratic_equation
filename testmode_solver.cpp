#include "testmode_solver.h"

#include <stdio.h>

struct Test test_data[] = {
    {INF_ROOTS,  0,    0,    0,    0,    0},
    {NO_ROOTS,   0,    0,    5,    0,    0},
    {NO_ROOTS,  10,    0,    7,    0,    0},
    {NO_ROOTS,   3,    1,   15,    0,    0},
    {ONE_ROOT,   0,    5,   20,   -4,    0},
    {ONE_ROOT,   0,  -14,    7,  0.5,    0},
    {ONE_ROOT,   5,   10,    5,   -1,    0},
    {ONE_ROOT,   9,  -54,   81,    3,    0},
    {ONE_ROOT,   7,    0,    0,    0,    0},
    {TWO_ROOTS,  8,    0,   -2,  0.5, -0.5},
    {TWO_ROOTS,  5,  -20, -105,    7,   -3},
    {TWO_ROOTS, 12,    6,    0,    0,  0.5}, //incorrect test to show how test failure looks
};
const int ntests = sizeof(test_data) / sizeof(test_data[0]);

void testmode() {
    printf("Entering testmode..\n");
    int failed_tests_counter = 0;
    for (int i = 0; i < ntests; ++i) {
        if (!test_completed(test_data[i], i)) {
            ++failed_tests_counter;
            continue;
        }
        printf("test %d completed successfully\n", i);
    }
    printf("Testing finished. Number of failed tests: %d", failed_tests_counter);
}

bool test_completed(struct Test test, int num_of_test) {
    double calculated_x1;
    double calculated_x2;
    enum Num_of_roots calculated_roots_num = solve_quadratic_equation(test.a, test.b, test.c, &calculated_x1, &calculated_x2);

    if (is_zero(test.roots_num - calculated_roots_num)) {
        switch (test.roots_num) {
        case NO_ROOTS:
            return true;
        
        case ONE_ROOT:
            if (is_zero(test.x1 - calculated_x1)) {
                return true;
            }
            printf("TEST %d FAILED\n\tCoefficients: a = %lg, b = %lg, c = %lg\n", num_of_test, test.a, test.b, test.c);
            printf("\tAnswer:          x = %5g\n", calculated_x1);
            printf("\tExpected answer: x = %5g\n", test.x1);
            return false;

        case TWO_ROOTS:
            if (is_zero(calculated_x1 - test.x1) && is_zero(calculated_x2 - test.x2)) {
                return true;
            }
            if (is_zero(calculated_x1 - test.x2) && is_zero(calculated_x1 - test.x1)) {
                return true;
            }
            printf("TEST %d FAILED\n\tCoefficients: a = %lg, b = %lg, c = %lg\n", num_of_test, test.a, test.b, test.c);
            printf("\tAnswer:          x1 = %5g, x2 = %5g\n", calculated_x1, calculated_x2);
            printf("\tExpected answer: x1 = %5g, x2 = %5g\n", test.x1, test.x2);
            return false;    

        case INF_ROOTS:
            return true;

        default:
            printf("Error: unexpected number of roots: %d", test.roots_num);
            ERROR_IF(0);
        }
    }

    printf("TEST %d FAILED.\n", num_of_test);
    printf("\tCoefficients: a = %lg, b = %lg, c = %lg\n\t", test.a, test.b, test.c);
    printf("Calculated number of roots: %d", calculated_roots_num);
    printf("Expected number of roots: %d\n\t", test.roots_num);

    switch (calculated_roots_num) {
    case NO_ROOTS:
        break;
    
    case ONE_ROOT:
        printf("Calculated root: %lg", calculated_x1);
        break;

    case TWO_ROOTS:
        printf("Calculated roots: x1 = %lg and x2 = %lg", calculated_x1, calculated_x2);
        break;

    case INF_ROOTS:
        break;

    default:
        printf("Error: unexpected number of roots: %d", test.roots_num);
        ERROR_IF(0);
    }

    switch (test.roots_num) {
    case NO_ROOTS:
        break;
    
    case ONE_ROOT:
        printf("Expected root: %lg", calculated_x1);
        break;

    case TWO_ROOTS:
        printf("Expected roots: x1 = %lg and x2 = %lg", calculated_x1, calculated_x2);
        break;

    case INF_ROOTS:
        break;

    default:
        printf("Error: unexpected number of roots: %d", test.roots_num);
        ERROR_IF(0);
    }

    return false;
}
