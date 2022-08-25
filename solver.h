/*!
\file
\brief File with equation solver functions
\author Olga Terekhova (sqiportinhsa)
\date 24 august 2022

This file contains Equation solving module

*/

/*! \defgroup solver Equation solving
\brief This module contains functions for solving square and linear equations

Right now it supports solving linear and guadratic equations
*/

#pragma once

#include <stdio.h>

/*! \defgroup solver Equation solving
    @{
*/

///Roots number variations set
enum Num_of_roots {
    NO_ROOTS = 0, ///< equation has no roots
    ONE_ROOT = 1, ///< equation has one root
    TWO_ROOTS = 2, ///< equation has two roots
    INF_ROOTS = -1 ///< equation has infinite number of roots
};

const double calc_error = 10e-7;

/*!
\brief Solves quadratic equation in form ax^2 + bx + c = 0

\param[in] a Quadratic coefficient
\param[in] b Linear coefficient
\param[in] c Free term
\param[out] x1, x2 Pointers to roots

\return Number of roots  
*/
enum Num_of_roots solve_quadratic_equation(double a, double b, double c, double *x1, double *x2);


/*!
\brief Solves linear equation in form ax + b = 0

\param[in] a Linear coefficient
\param[in] b Free term
\param[out] x Pointer to root

\return Number of roots
*/
enum Num_of_roots solve_linear_equation(double a, double b, double *x);


/*!
\brief Checks if double number is equal to zero taking into account the calculation error

\param[in] num Double number that is needed to be checked

\return true if num is equal to zero and false if not
*/
bool is_zero(double num);

/*!
\brief print message about error if condition is true
*/
#define ERROR_IF(condition)                                                                                          \
	if (condition)                                                                                                   \
		printf("Error %s.\nFunction: %s\nLine: %d\nFile: %s\n", #condition, __PRETTY_FUNCTION__, __LINE__, __FILE__);

/*!
\brief Assert analog 
*/
#define OLYA_ASSERT(condition)                                                                                               \
    if (!condition)                                                                                                          \
		printf("Error %s is false.\nFunction: %s\nLine: %d\nFile: %s\n", #condition, __PRETTY_FUNCTION__, __LINE__, __FILE__);
/*! @} */
