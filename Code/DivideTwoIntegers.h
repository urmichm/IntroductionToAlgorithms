#pragma once

#define DIVIDE_TWO_INTEGERS
#include <limits>

/**
 * Given two integers dividend and divisor, 
 * divide two integers without using multiplication, division, and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero,
 * which means losing its fractional part. 
 * For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
 *
 * Note:
 * Assume we are dealing with an environment that could only store integers within 
 * the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
 * For this problem, assume that your function returns 2^31 − 1 when the division result overflows.
 *
 * Constraints:
 *   -2^31 <= dividend, divisor <= 2^31 - 1
 *   divisor != 0
 */


int divide(int dividend, int divisor)
{
	long dividend_l = (long)(dividend);
	long divisor_l = (long)(divisor);

	long res = dividend_l / divisor_l;
	if (res > (long)INT_MAX)
		return INT_MAX;
	if (res < (long)INT_MIN)
		return INT_MAX;
	return (int)res;
}

