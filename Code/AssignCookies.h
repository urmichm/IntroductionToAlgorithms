#pragma once

/**
 * LeetCode: 455 Assign Cookies
 * https://leetcode.com/problems/assign-cookies/
 *
 * Assume you are an awesome parent and want to give your children some cookies. 
 * But, you should give each child at most one cookie.
 * 
 * Each child i has a greed factor g[i], 
 * which is the minimum size of a cookie that the child will be content with; 
 * and each cookie j has a size s[j].
 *
 * If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
 * Your goal is to maximize the number of your content children and output the maximum number.
 */


/*
1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1

*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s);
void run(void);

int findContentChildren(vector<int>& g, vector<int>& s) 
{
	int result = 0;
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	int i = 0, j = 0;

	while (i < g.size() && j < s.size())
	{
		if (g[i] <= s[j])
		{
			i++; j++;
			result++;
		}
		else
		{
			j++;
		}
	}

	return result;
}




void run(void)
{
	unsigned int test = 1;
	cout << "455. Assign Cookies" << endl;
	{
		vector<int> g({ 1,2,3 });
		vector<int> s({ 1,1});
		int expected = 1;
		int actual = findContentChildren(g, s);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> g({ 1,2 });
		vector<int> s({ 1,2,3 });
		int expected = 2;
		int actual = findContentChildren(g, s);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
}

