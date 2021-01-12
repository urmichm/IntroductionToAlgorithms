#pragma once

/**
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 */

#include <vector>

#define K_LARGEST

using namespace std;

/* Public fundtion declaration */
int findKthLargest(vector<int>& nums, int k);

static void sortK(vector<int>& nums, int begin, int end, int iK);
static int partition(vector<int>& nums, int begin, int end);
static void swap(vector<int>& nums, int i, int j);

int findKthLargest(vector<int>& nums, int k) 
{
	int iK = nums.size() - k;
	sortK(nums, 0, nums.size(), iK);
	return nums[iK];
}


/**
 * @brief Based on quicksort algorithm, places K-th largest element on its place
 * nums - array to operate on
 * @params begin, end - starting and ending indecies of the subarray; [begin, end)
 * @param k - index of the K-th largest element, initially k = nums.size() - K
 */
static void sortK(vector<int>& nums, int begin, int end, int iK)
{
	if ((end - begin) <= 1)
		return;

	// pivot index;
	int iPivot = begin + (end - begin) / 2;  
	// place pivot at the begining of the subarray;
	swap(nums, begin, iPivot);

	iPivot = partition(nums, begin, end);

	if (iPivot > iK)
		sortK(nums, begin, iPivot, iK);
	if (iPivot < iK)
		sortK(nums, iPivot+1, end, iK);

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

