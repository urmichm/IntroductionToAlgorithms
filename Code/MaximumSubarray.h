/**
 *  53. Maximum Subarray
 * Given an integer array nums,
 * find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 *
 * Follow up: If you have figured out the O(n) solution,
 * try coding another solution using the divide and conquer approach,
 * which is more subtle.
 */

#include <vector>
#include <algorithm>
using namespace std;

int dp_maxSubArray(vector<int>& nums);
int MaxSubArray(vector<int>& nums);

static int FindMaximumSubarray(vector<int>& nums, int begin, int end);
static int FindMaximumCrossingSubarray(vector<int>& nums, int begin, int mid, int end);

int MaxSubArray(vector<int>& nums)
{
	return FindMaximumSubarray(nums, 0, nums.size());
}

/**
 * Find Maximum Subarray recursively 
 * @param nums - array of int
 * @param being - first index of array (inclusively)
 * @param end - last index of the array (exclusively)
 */
static int FindMaximumSubarray(vector<int>& nums, int begin, int end)
{
	// If we have a single element - return
	if (end - begin == 1) return nums[begin];
	
	int mid = (begin + end) / 2;

	// Check the Maximum subarray in the left part [begin, mid)
	int left = FindMaximumSubarray(nums, begin, mid);

	// Check the Maximum subarray in the right part [mid, end)
	int right = FindMaximumSubarray(nums, mid, end);

	// Check if the maximum subarray on the crossign section
	int crossing = FindMaximumCrossingSubarray(nums, begin, mid, end);

	return max( crossing, max(left, right)  );
}


/**
 * Find the Max Subarray that croses the midpoint.
 * It solves a subproblem that is NOT a smaller instance of the original problem.
 * We consider it to be the combine part :)
 * @param nums - the subarray that starts at begin, ends on end and has a midpoint mid
 * Left-side of the array [begin, mid)
 * Right-side of the array [mid, end)
 * [ . . . . . * * * * | * * * * . . . ]  // max subarray indicated in *
 *   ^begin              ^mid          ^end      
 */
static int FindMaximumCrossingSubarray(vector<int>& nums, int begin, int mid, int end)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;
	
	// find a maximum subarray of the left half
	for (int i = mid - 1; i >= 0; i--)
	{
		sum += nums[i];
		left_sum = max(left_sum, sum);
	}
	// reset temp sum
	sum = 0;
	// find a maximum subarray of the right half
	for (int i = mid; i < end; i++)
	{
		sum += nums[i];
		right_sum = max(right_sum, sum);
	}

	return right_sum + left_sum;
}

int dp_maxSubArray(vector<int>& nums) 
{
	if (0 == nums.size()) return 0;
	int res_sum = nums[0];
	int window_sum = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		int new_window = (window_sum + nums[i]);
		if (new_window < nums[i])
			window_sum = nums[i];
		else
			window_sum = new_window;

		if (window_sum > res_sum)
			res_sum = window_sum;
	}

	return res_sum;
}
