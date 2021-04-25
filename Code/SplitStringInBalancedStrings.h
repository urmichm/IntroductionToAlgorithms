/**
 * LeetCode: 1221
 * https://leetcode.com/problems/split-a-string-in-balanced-strings/
 * 
 * Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
 * Given a BALANCED string s, split it in the maximum amount of balanced strings.
 * Return the maximum amount of split balanced strings.
 */

#pragma once

#define SPLIT_STRING_IN_BALANCED_STRINGS

#include <iostream>
#include <string>
using namespace std;

int balancedStringSplit(string s);

void run(void);


/**
 * @brief 
 * @param input BALANCED string
 * @return number of balanced substrings
 */
int balancedStringSplit(string s) 
{
	int res = 0;
	int turn = 0;

	// turn as string goes
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'L')
			turn++;
		else
			turn--;

		// when turn goes to zero, we finished balanced substring
		if (turn == 0)
			res++;
	}

	return res;
}


void run(void)
{
	unsigned int test = 1;
	{
		string s = "RLRRLLRLRL";
		int expected = 4;
		int actual = balancedStringSplit(s);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		string s = "RLLLLRRRLR";
		int expected = 3;
		int actual = balancedStringSplit(s);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		string s = "LLLLRRRR";
		int expected = 1;
		int actual = balancedStringSplit(s);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		string s = "RLRRRLLRLL";
		int expected = 2;
		int actual = balancedStringSplit(s);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
}
