#pragma once

#define QUICK_SORT

#include <vector>
using namespace std;


void quicksort(vector<int>& nums);

static void quicksort(vector<int>& nums, int begin, int end);
static int partition(vector<int>& nums, int begin, int end);
static void swap(vector<int>& nums, int i, int j);

void quicksort(vector<int>& nums)
{
	quicksort(nums, 0, nums.size());
	return;
}

static void quicksort(vector<int>& nums, int begin, int end)
{
	if ((end - begin) <= 1)
		return;

	// pivot index;
	int iPivot = begin + (end - begin) / 2;
	// place pivot at the begining of the subarray;
	swap(nums, begin, iPivot);
	// do partitions and update iPivot
	iPivot = partition(nums, begin, end);

	// sort left part
	quicksort(nums, begin, iPivot);
	// sort right part
	quicksort(nums, iPivot + 1, end);

	return;
}

static int partition(vector<int>& nums, int begin, int end)
{
	int pivot = nums[begin];
	int i = begin + 1;
	int j = end - 1;

	while (i != j)
	{
		if (nums[i] < pivot)
		{
			i++;
		}
		else
		{
			swap(nums, i, j);
			j--;
		}
	}

	// get pivot's right place
	i = (nums[i] > pivot) ? i - 1 : i;
	// place pivot at its place
	swap(nums, begin, i);

	// return pivot's index
	return i;
}


/** Swap i-th and j-th elenemts in the array nums **/
static void swap(vector<int>& nums, int i, int j)
{
	int t = nums[i];
	nums[i] = nums[j];
	nums[j] = t;
	return;
}

