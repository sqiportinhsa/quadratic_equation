/*!
\file
\brief Solving equation with coefficients obtained by user
\author Olga Terekhova (sqiportinhsa)
\date 24 august 2022

This file contains User input solver module
*/


/*! \defgroup user_input_solver User input solver
\brief Solving equation with user's input coefficients using Equation solving module

This module contains functions needed to interact with user and manage solving using Solver module. 
It gets coefficients of equation by reading it one by one from console or reading from command line.
All coefficients pass correctness checkup.
In case of incorrect coefficient user need to enter the correct one for interctive mode to continue solving or stop it.
For command line mode there is no such options, so programm wil be stopped.  
After getting coefficients it launches functions from "Equation solving" module to get solution.
Finally it prints solution: all roots and its number.
*/

#ifndef USER_INPUT_SOLVER
#define USER_INPUT_SOLVER

#include "solver.h"

/*! \defgroup user_input_solver User input solver
    @{
*/

/*!
\brief Managing reading user's input from command line
Reading coefficients, check it's correctness by number of coefficients and conformity to double type

\param[in] argc Number of arguments given from command line
\param[in] argv Array of strings read from command line
\param[out] pa Pointer to a coefficient
\param[out] pb Pointer to b coefficient
\param[out] pc Pointer to c coefficient

\return True if input is correct, false if incorrect
*/
bool read_from_command_line(int argc, const char *argv[], double *pa, double *pb, double *pc);

/*!
\brief Managing reading user's input from console by using read_coefficient() function

\param[out] pa Pointer to the a coefficient
\param[out] pb Pointer to the b coefficient
\param[out] pc Pointer to the c coefficient

\return True if input was done successfully or false if user stopped running programm
*/
bool read_from_console(double *pa, double *pb, double *pc);

/*!
\brief Printing roots and it's number.
Default x1 and x2 have zero values that would be gived to function if real values do not exist.
If there is only one root its value should be in x1, and only it would be printed.  

\param[in] x1, x2 Roots
\param[in] root_number Number of roots
*/
void print_roots(double x1, double x2, enum Num_of_roots root_number);

/*!
\brief Reading coefficient and record it
If coefficient is incorrect asks user to choose between retry entering coefficient and stop running programm.
Correct coefficients would be recorded using pointers.

\param[out] coef Pointer to reading coefficient

\return true if reading completed correctly or false if user stopped running programm
*/
bool read_coefficient(double *coef);

/*!
\brief Cleaning buffer (fflush analogue)
Used if input is incorrect to clear buffer from not-number symbols.
*/
void clear_input();

/*! @} */

#endif
