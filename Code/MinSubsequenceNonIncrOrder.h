#pragma once

/**
 * LeetCode: 1403.
 * https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
 *
 * Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than 
 * the sum of the non included elements in such subsequence. 
 *
 * If there are multiple solutions, 
 * return the subsequence with minimum size and if there still exist multiple solutions, 
 * return the subsequence with the maximum total sum of all its elements. 
 * A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 
 *
 * Note that the solution with the given constraints is guaranteed to be unique. 
 * Also return the answer sorted in non-increasing order.
 */

#define MIN_SUBSEQUENCE_IN_NON_INCREASING_ORDER

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> minSubsequence(vector<int>& nums);
void run(void);

vector<int> minSubsequence(vector<int>& nums)
{
	// NOTE: subsequence is NOT a subarray
	int sum = 0;
	int subsum = 0;
	const unsigned int size = nums.size();
	vector<int> result;

	for (int n : nums)
		sum += n;

	sort(nums.begin(), nums.end(), greater<int>());

	for (int i = 0; (i < size) && (subsum <= sum - subsum) ; i++)
	{
		result.push_back(nums[i]);
		subsum += nums[i];
	}

	return result;
}

void run(void)
{
	cout << "LeetCode: 1403. Minimum Subsequence in Non-Increasing Order" << endl;
	cout << "Please, make your own test cases or follow the link in the description" << endl;
}
