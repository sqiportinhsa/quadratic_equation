#include "user_input_solver.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cassert>
#include <ctype.h>
#include "solver.h"

bool read_from_terminal(int argc, const char *argv[], double *pa, double *pb, double *pc) {
    ERROR_IF(pa == NULL);
    ERROR_IF(pb == NULL);
    ERROR_IF(pc == NULL);

    if (argc != 5) {
        printf("Incorrect input: 3 coefficients expected.\n");
        return false;
    }

    char temp_char = 0;
    
    if(!( 
           sscanf (argv[2], "%lg%c", pa, &temp_char) == 1
        && sscanf (argv[3], "%lg%c", pb, &temp_char) == 1
        && sscanf (argv[4], "%lg%c", pc, &temp_char) == 1
    )) {
        printf("Incorrect input: NAN coefficients\n");
        return false;
    }

    return true;
}

bool read_from_console(double *pa, double *pb, double *pc) {
    ERROR_IF(pa == NULL);
    ERROR_IF(pb == NULL);
    ERROR_IF(pc == NULL);

    printf("It's square equation solver. Please, bring your equation to \"ax^2 + bx + c = 0\" form.\n\n");

    printf("Enter a coefficient: ");
    if (read_coefficient(pa) == false) {
        return false;
    }

    printf("Enter b coefficient: ");
    if (read_coefficient(pb) == false) {
        return false;
    }

    printf("Enter c coefficient: ");
    if (read_coefficient(pc) == false) {
        return false;
    }

    return true;
}

void print_roots(double x1, double x2, enum Num_of_roots root_number) {
    switch (root_number) {
    case INF_ROOTS:
        printf("There is infinite number of roots.\n");
        break;

    case ONE_ROOT:
        printf("There is one root: x = %lg.\n", x1);
        break;

    case TWO_ROOTS:
        printf("There are two roots: x1 = %lg and x2 = %lg.\n", x1, x2);
        break;

    case NO_ROOTS:
        printf("There are no roots :(\n");
        break;

    default:
        printf("Error: unexpected number of roots: %d\n", root_number);
        ERROR_IF("root error" && 0);
    }
}

bool read_coefficient(double *coef) {
    ERROR_IF(coef == NULL);

    int exit = 1;
    int num_of_read_numbers = 0;

    while(true) {
        num_of_read_numbers = scanf("%lg", coef);

        if(num_of_read_numbers == EOF){
            printf("End of programm running: EOF was entered");
            return false;
        }

        if (num_of_read_numbers == 1 && isfinite(*coef) && isspace(getchar())) {
            printf("\n");
            return true;
        }

        clear_input();
        
        printf("This coefficient is incorrect. Please, try again.\n");
        printf("If you want to try again enter any number exept 0. If you want to exit enter 0: ");

        scanf("%d", &exit);

        if (exit == 0) {
            return false;
        }

        printf("Enter coefficient again: ");
    }
}

void clear_input() {
    while (getchar() != '\n');
}