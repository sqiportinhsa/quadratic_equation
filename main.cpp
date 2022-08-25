#include <stdio.h>
#include <cassert>
#include <math.h>
#include <string.h>
#include "user_input_solver.h"
#include "testmode_solver.h"

const char Testmode_flag[] = "-test";
const char Command_line_solving_flag[] = "-cl";
const char Help_flag[] = "-h";

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

    if (strcmp(argv[1], Testmode_flag) == 0) {
        testmode();
        return 0;
    }

    if (strcmp(argv[1], Help_flag) == 0) {
        printf("List of existing commands:\n");
        printf("\t%s\tTest mode:            programm running unit tests\n", Testmode_flag);
        printf("\t%s\tHelp mode:            output of existing commands\n", Help_flag);
        printf("\t%s\tCommand line input mode:  solving with coefficients after %s\n", Command_line_solving_flag, Command_line_solving_flag);
        printf("Running programm without any command launch solving with console input coefficients");
        return 0;
    }

    if(strcmp(argv[1], Command_line_solving_flag) == 0) {
        double a = 0;
        double b = 0;
        double c = 0;

        if (!read_from_command_line(argc, argv, &a, &b, &c)) {
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

    printf("Error: unexpected command line input");
    return -1;
}
