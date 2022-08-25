/*!
\file
\brief File with functions managing tests
\author Olga Terekhova (sqiportinhsa)
\date 24 august 2022

This file contains Unit tests for Equation solving module
*/

/*! \defgroup testmode_solver Unit tests for Equation solving
\brief This module contains unit tests for Equation solving module

This module contains functions needed to test functions from Equation solving module with prepared tests. 
Tests are keeped by stucture Test. 
test_completed function use this data to compare it with answers that Equation solving returns.
*/

#ifndef TESTMODE_SOLVER
#define TESTMODE_SOLVER

#include <cassert>
#include "solver.h"

/*! \defgroup testmode_solver Unit tests for Equation solving
    @{
*/

/*!
\brief Structure keeping quadratis equation coefficients and correct roots and its number
*/
struct Test {
    enum Num_of_roots roots_num;
    double a;
    double b;
    double c;
    double x1;
    double x2;
};

/*!
\brief Launching tests for quadratic equation function
*/
void testmode();

/*!
\brief Check whether roots calculated by function are equal to answer from tests 
For correct completing of test function returns true. 
If test completed incorrectly it prints number of test, evaluated answers and expected answers.

\param[in] test Test from array
\param[in] num_of_test Number of test

\return true if answers are correct, false otherwise
*/
bool test_completed(struct Test test, int num_of_test);

/*! @} */

#endif
