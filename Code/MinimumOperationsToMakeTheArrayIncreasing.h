#pragma once

/**
 * LeetCode: 1827
 * https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
 *
 * You are given an integer array nums (0-indexed). In one operation, 
 * you can choose an element of the array and increment it by 1.
 *
 * For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
 *
 * Return the minimum number of operations needed to make nums strictly increasing.
 */

#define MIN_OPERATIONS_TO_MAKE_ARRAY_INCR

#include <vector>
#include <iostream>
using namespace std;

void run(void);
int minOperations(vector<int>& nums);


int minOperations(vector<int>& nums) 
{
	int res = 0;

	if (nums.size() > 1)
	{
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] >= nums[i])
			{

				int delta = nums[i - 1] - nums[i] + 1;
				nums[i] += delta;
				res += delta;
			}
		}
	}

	return res;
}


void run(void)
{
	unsigned int test = 1;
	{
		vector<int> nums({1,1,1});
		int expected = 3;
		int actual = minOperations(nums);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> nums({ 1,5,2,4,1 });
		int expected = 14;
		int actual = minOperations(nums);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> nums({ 1 });
		int expected = 0;
		int actual = minOperations(nums);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}

}
