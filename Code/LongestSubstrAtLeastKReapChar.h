#pragma once

#define LONGEST_SUBSTRING_WITH_AT_LEASET_K_REPEAT_CHAR

/**
 * Given a string s and an integer k, return the length of the longest substring of s 
 * such that the frequency of each character in this substring is greater than or equal to k.
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubstring(string s, int k);

static int DnC_longestSubstring(string& s, int start, int end, int k);


int longestSubstring(string s, int k) 
{
	return DnC_longestSubstring(s, 0, s.length(), k);
}


/**
 * @brief Find the longest substring according to the requirements. The function checks string in range [start, end)
 * @param s - target string
 * @param start, end - starting and ending indecies in form [start, end)
 * @param k - minimum number of each character in the substring
 * @return length of the longest substring with at least k repeating characters
 */
static int DnC_longestSubstring(string& s, int start, int end, int k)
{
	if (end - start <= 0) return 0;
	 
	int counts[26] = { 0 };

	// count the characters number
	for (int i = start; i < end; i++)
		counts[s[i] - 'a']++;

	// find mid points for recursive approach
	for (int mid = start; mid < end; mid++)
	{
		if (counts[s[mid] - 'a'] >= k)
			continue;
		
		int midNext = mid + 1;

		// skip subsequent invalid chars
		while (midNext < end && counts[s[midNext] - 'a'] < k)
			midNext++;

		// end loop with recursive call 
		return max(DnC_longestSubstring(s, start, mid, k),
			       DnC_longestSubstring(s, midNext, end, k)
		       );
	}

	// return the current str len
	return (end - start);
}


 
 /**
 * Approach: 
 * Use D&C approach. We divide the string on invalide character. An invlid character is the one with a frequency of less than k.
 * As we know, the invalid character cannot be part of the result. We shall split the string at the index where we find the invalid character. 
 * Recursively check for each split and combine the result.
 */

