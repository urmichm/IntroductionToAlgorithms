#pragma once

/**
 * LeetCode: 984. String Without AAA or BBB
 * https://leetcode.com/problems/string-without-aaa-or-bbb/
 * 
 * Given two integers a and b, return any string s such that:
 *
 *  - s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
 *  - The substring 'aaa' does not occur in s, and
 *  - The substring 'bbb' does not occur in s.
 */

#define STR_WITHOUT_AAA_BBB

#include <string>
#include <iostream>
using namespace std;

void run(void);

string strWithout3a3b(int a, int b) 
{
	string result = "";
	unsigned char prev_a = 0;
	unsigned char prev_b = 0;
		
	while (a > 0 || b > 0)
	{
		if (prev_a == 2)
		{
			// force b
			result += "b";	b--;
			prev_b = 1; prev_a = 0;
			
			if (b < 0)	exit(EXIT_FAILURE);
		}
		else if (prev_b == 2)
		{
			// force a
			result += "a";	a--;
			prev_a = 1; prev_b = 0;
			
			if (a < 0)	exit(EXIT_FAILURE);
		}
		else
		{
			if (a > b)
			{
				result += "a";	a--;
				prev_a++; prev_b = 0;
			}
			else
			{
				result += "b";	b--;
				prev_b++; prev_a = 0;
			}
		}
	}

	return result;
}


void run(void)
{
	unsigned int test = 1;
	cout << "984. String Without AAA or BBB" << endl;
	{
		string res = strWithout3a3b(1, 2);
		cout << test++ << ": " << res << endl;
	}
	{
		string res = strWithout3a3b(4, 1);
		cout << test++ << ": " << res << endl;
	}
	{
		string res = strWithout3a3b(2, 6);
		cout << test++ << ": " << res << endl;
	}
	{
		string res = strWithout3a3b(10, 15);
		cout << test++ << ": " << res << endl;
	}
	{
		string res = strWithout3a3b(0, 2);
		cout << test++ << ": " << res << endl;
	}
	{
		string res = strWithout3a3b(2, 0);
		cout << test++ << ": " << res << endl;
	}
}
