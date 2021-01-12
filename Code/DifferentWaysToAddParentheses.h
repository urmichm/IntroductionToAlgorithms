#pragma once

#define DIFFERENT_WAYS_TO_ADD_PARENTHESES

/**
 * Given a string of numbers and operators, 
 * return all possible results from computing all the different possible ways 
 * to group numbers and operators. The valid operators are +, - and *.
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> diffWaysToCompute(string input);
static vector<int> DnC_diffWaysToCompute(string input, int start, int end);


vector<int> diffWaysToCompute(string input)
{
	return DnC_diffWaysToCompute(input, 0, input.length());
}

/**
 * @brief Calculates all possible results from computing all 
 * the different possible ways to group numbers and operators. 
 * The valid operators are +, - and *
 * @params input, start,end - input substring and its range in form [start, end)
 * @return vector of integers calculated according to the algorithm
 */
vector<int> DnC_diffWaysToCompute(string input, int start, int end)
{
	vector<int> result;
	bool oper = false;

	// Check if any operator present
	for (int i = start; i < end && !oper; i++)
		if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			oper = true;

	// If no operator present, convert the number into an int 
	if (!oper) {
		string s(input, start, end - start);
		result.push_back(stoi(s));
		return result;
	}

	// Go throught the str and calculate the result
	for (int i = start; i < end; i++)
	{
		if (input[i] == '+')
		{
			vector<int> left = DnC_diffWaysToCompute(input, start, i);
			vector<int> right = DnC_diffWaysToCompute(input, i + 1, end);
			for (int l : left)
				for (int r : right)
					result.push_back(l + r);
		}
		if (input[i] == '-')
		{
			vector<int> left = DnC_diffWaysToCompute(input, start, i);
			vector<int> right = DnC_diffWaysToCompute(input, i + 1, end);
			for (int l : left)
				for (int r : right)
					result.push_back(l - r);
		}
		if (input[i] == '*')
		{
			vector<int> left = DnC_diffWaysToCompute(input, start, i);
			vector<int> right = DnC_diffWaysToCompute(input, i + 1, end);
			for (int l : left)
				for (int r : right)
					result.push_back(l * r);
		}
	}

	return result;
}
