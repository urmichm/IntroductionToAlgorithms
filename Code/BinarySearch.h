#pragma once
/**
Simple Binary Search
*/

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& nums, int target);
void testBinarySearch(void);

int binarySearch(const vector<int>& nums, int target)
{
	unsigned int left = 0;
	unsigned int right = nums.size();

	while (left < right)
	{
		unsigned int mid = left + (right - left) / 2;
		if (nums[mid] > target)
			right = mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			return mid;
	}

	return -1;
}


void testBinarySearch(void)
{
	unsigned int test = 1;
	cout << "Simple Binary Search" << endl;
	{
		vector<int> nums({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13 });
		int target = 6;
		int expected = 6;
		int actual = binarySearch(nums, target);
		cout << test++ << ": " <<(expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> nums({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13 });
		int target = 66;
		int expected = -1;
		int actual = binarySearch(nums, target);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> nums({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13 });
		int target = -6;
		int expected = -1;
		int actual = binarySearch(nums, target);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> nums({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13 });
		int target = 13;
		int expected = 13;
		int actual = binarySearch(nums, target);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> nums({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13 });
		int target = 0;
		int expected = 0;
		int actual = binarySearch(nums, target);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> nums;
		int target = 6;
		int expected = -1;
		int actual = binarySearch(nums, target);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> nums({ 0 });
		int target = 6;
		int expected = -1;
		int actual = binarySearch(nums, target);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
}
