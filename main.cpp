#include <stdio.h>
#include <cassert>
#include <math.h>
#include <string.h>
#include "user_input_solver.h"
#include "testmode_solver.h"

const char testmode_flag[] = "-test";
const char terminal_solving_flag[] = "-term";
const char help_flag[] = "-h";

int main(int argc, const char* argv[]) {
    if (argc <= 1) {
        double a = 0;
        double b = 0;
        double c = 0;

        if (!read_from_console(&a, &b, &c)) {
            printf("Programm running was stopped by user.\n");
            printf("Thanks for choosing this solver. See you later!");
            return 0;
        }

        double x1 = 0;
        double x2 = 0;

        enum Num_of_roots root_number = solve_quadratic_equation(a, b, c, &x1, &x2);
        OLYA_ASSERT(isfinite(x1));
        OLYA_ASSERT(isfinite(x2));

        print_roots(x1, x2, root_number);

        printf("Solving completed successfully.\n");
        printf("Thanks for choosing this solver. See you later!");
        
        return 0;
    }

    if (strcmp(argv[1], testmode_flag) == 0) {
        testmode();
        return 0;
    }

    if (strcmp(argv[1], help_flag) == 0) {
        printf("List of existing commands:\n");
        printf("\t%s\tTest mode:            programm running unit tests\n", testmode_flag);
        printf("\t%s\tHelp mode:            output of existing commands\n", help_flag);
        printf("\t%s\tTerminal input mode:  solving with coefficients after %s\n", terminal_solving_flag, terminal_solving_flag);
        printf("Running programm without any command launch solving with console input coefficients");
        return 0;
    }

    if(strcmp(argv[1], terminal_solving_flag) == 0) {
        double a = 0;
        double b = 0;
        double c = 0;

        if (!read_from_terminal(argc, argv, &a, &b, &c)) {
            printf("Programm running was stopped.\n");
            printf("Thanks for choosing this solver. See you later!");
            return -1;
        }

        double x1 = 0;
        double x2 = 0;

        enum Num_of_roots root_number = solve_quadratic_equation(a, b, c, &x1, &x2);

        OLYA_ASSERT(isfinite(x1));
        OLYA_ASSERT(isfinite(x2));

        print_roots(x1, x2, root_number);

        printf("Solving completed successfully.\n");
        printf("Thanks for choosing this solver. See you later!");

        return 0;
    }

    printf("Error: unexpected terminal input");
    return -1;
}
