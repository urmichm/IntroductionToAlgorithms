#pragma once

#define THREE_SUM_PROBLEM

/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 * 
 * Notice that the solution set must not contain duplicate triplets.
*/

#include <vector>
#include <map>

#include <set>
#include <unordered_set>
#include <unordered_map>

#include <iostream>
#include <algorithm>
using namespace std;

void run(void);

vector<vector<int>> threeSum(vector<int>& nums);
void _twoSumII__twoPointers(vector<int>& nums, int goal, unsigned int start_idx, vector<vector<int>> &result);
void _twoSumII__hashSet(vector<int>& nums, int goal, unsigned int start_idx, vector<vector<int>> &result);

vector<vector<int>> threeSum_noSort(vector<int>& nums);

vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> result;
	if (nums.size() >= 3)
	{
		// the quickest we do is O(n^2) so sorting in O(n*log(n)) is fine
		sort(nums.begin(), nums.end());
		// once nums[i] > 0, quit the loop, since no triple will be found
		for (unsigned int i = 0; i < nums.size() && nums[i] <= 0; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1]) 
				continue;
			
			_twoSumII__hashSet(nums, (-1)*nums[i], i+1, result);
			//_twoSumII__twoPointers(nums, (-1)*nums[i], i+1, result);

		}
	}
	return result;
}

void _twoSumII__hashSet(vector<int>& nums, int goal, unsigned int start_idx, vector<vector<int>> &result)
{
	unsigned int i = start_idx;
	unordered_set<int> set;
	for (i = start_idx; i < nums.size(); i++)
	{
		int complement = goal - nums[i];
		if (set.count(complement) > 0) 
		{
			result.push_back({ nums[i], complement, (-1)*goal });
			// skip duplicates
			while (i + 1u < nums.size() && nums[i] == nums[i + 1u]) i++;
		}
		set.insert(nums[i]);
	}
	return;
}

void _twoSumII__twoPointers(vector<int>& nums, int goal, unsigned int start_idx, vector<vector<int>> &result)
{
	int i = start_idx;
	int j = nums.size()-1;

	while (i < j)
	{
		if (nums[i] + nums[j] == goal)
		{
			vector<int>a({ nums[i++], nums[j--], (-1)*goal });
			result.push_back( a );
			// skip duplicates
			while (i < j && nums[i] == nums[i - 1]) i++;
		}
		else if (nums[i] + nums[j] > goal) j--;
		else i++;
	}

	return ;
}



vector<vector<int>> threeSum_noSort(vector<int>& nums)
{
	set<vector<int>> res;    // set of vectors :)
	unordered_set<int> dups;
	unordered_map<int, int> seen;

	for (unsigned int i = 0; i < nums.size(); i++)
	{
		// insert method returns a pair<iterator,bool> object 
		// first element is an iterator pointing either to the newly inserted element in the container or to the element whose key is equivalent
		// second elemtnt is a bool value indicating whether the element was successfully inserted or not.
		if (dups.insert(nums[i]).second)
		{
			for (unsigned int j = i + 1u; j < nums.size(); j++)
			{
				int complement = (-1)*nums[i] - nums[j];
				auto it = seen.find(complement);
				// was complement found? was it found for our i?
				if (it != seen.end() && it->second == i)
				{
					vector<int> triplet({nums[i], nums[j], complement});
					// sort triplet to avoid permutations in set 
					sort(triplet.begin(), triplet.end());
					res.insert(triplet);
				}
				// we found nums[j] when we were dealing with i
				seen[nums[j]] = i;
			}
		}
	}

	// return vector of vectors
	return vector<vector<int>>(res.begin(), res.end());
}


void run() 
{
	vector<int> nums({ -1,0,1,2,-1,-4,0,0,0,0,0,8,1,1,-2,-4 });
	vector<vector<int>> res;
	// res = threeSum(nums);
	res = threeSum_noSort(nums);
	for (vector<int> arr : res)
	{
		for (int n : arr)
			cout << n << " ";
		cout << endl;
	}
}