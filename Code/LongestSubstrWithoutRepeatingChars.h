#pragma once
/**
Longest Substring Without Repeating Characters
LeetCode 3. https://leetcode.com/problems/longest-substring-without-repeating-characters/
Given a string s, find the length of the longest substring without repeating characters.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void run(void);
int lengthOfLongestSubstring(string s);


int lengthOfLongestSubstring(string s) 
{
	if (s.length() <= 1) return s.length();

	unsigned int result = 1;
	unsigned int i = 0, j = 1;
	__uint128_t  map = 0, mask = 0;
	__uint128_t  ONE = 1;
	mask = (ONE << (s[0]));
	map = map | mask;

	while (j < s.length())
	{
		mask = (ONE << (s[j]));
		if ((map & mask) == 0)
		{
			// add j-th symbol into the substr
			map = map | mask;
			j++;
			result = max(result, (j - i));
		}
		else
		{
			// remove i-th symbol from the substr
			mask = (ONE << (s[i]));
			map = map & (~mask);
			i++;
		}
	}

	return (int)result;
}


void run(void)
{
	unsigned int test = 0;
	{
		string s = "pwwkew";
		int actual = lengthOfLongestSubstring(s);
		int expected = 3;
		cout << ++test << ": " << (actual == expected ? "OK" : "ERROR") << " " <<
			actual << (actual == expected ? " == " : " != ") << expected << endl;
	}
	{
		string s = "abcabcbb";
		int actual = lengthOfLongestSubstring(s);
		int expected = 3;
		cout << ++test << ": " << (actual == expected ? "OK" : "ERROR") << " " <<
			actual << (actual == expected ? " == " : " != ") << expected << endl;
	}
	{
		string s = "bbbbbbb";
		int actual = lengthOfLongestSubstring(s);
		int expected = 1;
		cout << ++test << ": " << (actual == expected ? "OK" : "ERROR") << " " <<
			actual << (actual == expected ? " == " : " != ") << expected << endl;
	}
	{
		string s = "";
		int actual = lengthOfLongestSubstring(s);
		int expected = 0;
		cout << ++test << ": " << (actual == expected ? "OK" : "ERROR") << " " <<
			actual << (actual == expected ? " == " : " != ") << expected << endl;
	}
}