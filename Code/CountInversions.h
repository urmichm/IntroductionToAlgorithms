#pragma once


/**
 * Given an array A containing the numbers in some arbitrary order.
 * Count the number of inversions ( = number of pairs (i,j) of the array A where i < j and A[i] > A[j]
 */

#include<vector>
using namespace std;

int CountInversions(vector<int>& A);
static int CountInversionsRec(vector<int>& A, int begin, int end, vector<int>& buffer );
static int CountSplitInversions(vector<int>& A, int begin, int mid, int end, vector<int>& buffer);

int CountInversions(vector<int>& A)
{
	if (A.size() <= 1)
		return 0;
	vector<int> buffer(A);
	return CountInversionsRec(A, 0, A.size(), buffer);
}


/**
 * Sorts the array A using the merge sort and counts number of inversions
 * @param_inout A - an array to be sorted and numbers of inversions to be counted
 * @param_in begin and end are the start and end indecies of the array to be examined
 * @param_in buffer - copy of the A array, used as a buffer for mege sort :)
 */
static int CountInversionsRec(vector<int>& A, int begin, int end, vector<int>& buffer)
{
	if ( (end - begin) <= 1 )
		return 0;

	int mid = (begin + end) / 2;

	// Count inversion recursively in left and right parts
	int left_inver  = CountInversionsRec(buffer, begin, mid, A);
	int right_inver = CountInversionsRec(buffer, mid,   end, A);

	// count split inversions
	int split_inver = CountSplitInversions(A, begin, mid, end, buffer);

	// retun total number of inversions :)
	return left_inver + right_inver + split_inver;
}

/**
 *	@param_inout A - array, to be sorted on successful execution
 *	@param_in  buffer - buffer used to sort the array A
 *	@param_in begin - index of the 1st half of the array-split
 *	@param_in begin - index of the end of 1st half and begining of th 2nd half of the array-split
 *	@param_in begin - index of the end of 2nd half of the array-split
 *	@return number of split inversions
 */
static int CountSplitInversions(vector<int>& A, int begin, int mid, int end, vector<int>& buffer)
{
	int i = begin;  // Index of the first  half of the array
	int j = mid;    // Index of the second half of the array
	int k = begin;  // Index of the output array
	int split_inversions = 0;  // number of split inversions

	for (k = begin; k < end; k++)
	{  
		if (i < mid && (j >= end || buffer[i] <= buffer[j]))
		{
			// copy an element from the 1st half; no inversion
			A[k] = buffer[i];
			i += 1; 
		}
		else
		{
			// copy the element from the 2nd half; inversions
			A[k] = buffer[j];
			j += 1;
			// (mid - i) <- number of the elements left in the 1st half
			split_inversions += (mid - i);
		}
	}
	
	return split_inversions;
}

