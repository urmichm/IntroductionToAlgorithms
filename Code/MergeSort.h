

#include <vector>
using namespace std;

void MergeSort(vector<int>& arr);
static void TopDownMergeSort(vector<int>& A, vector<int>& B);
static void TopDownSplitMerge(vector<int>& buffer, int iBegin, int iEnd, vector<int>& A);
static void TopDownMerge(vector<int>& A, int iBegin, int iMiddle, int iEnd, vector<int>& B);

void MergeSort(vector<int>& arr)
{
	vector<int> buffer(arr);  // Make a copy of an arr
	TopDownMergeSort(arr, buffer);
}


/**
 * Array A has the items to sort; array B is a work array.
 */
static void TopDownMergeSort(vector<int>& A, vector<int>& buffer)
{
	const int N = A.size();
	TopDownSplitMerge(buffer, 0, N, A);
}

/** 
 * Sort the given run of array A[] using array B[] as a source.
 * iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
 */
static void TopDownSplitMerge(vector<int>& buffer, int iBegin, int iEnd, vector<int>& A)
{
	if (iEnd - iBegin <= 1) return;
	int iMiddle = (iBegin + iEnd) / 2;

	// recursively sort both runs from array A[] into B[]
	TopDownSplitMerge(A, iBegin, iMiddle, buffer);
	TopDownSplitMerge(A, iMiddle, iEnd, buffer);

	// merge the resulting runs from array B[] into A[]
	TopDownMerge(buffer, iBegin, iMiddle, iEnd, A);
}

/**
 * Left  source half is  src[ iBegin:iMiddle-1].
 * Right source half is  src[iMiddle:iEnd-1   ].
 * Result is            dest[ iBegin:iEnd-1   ].
 */
static void TopDownMerge(vector<int>& src, int iBegin, int iMiddle, int iEnd, vector<int>& dest)
{
	int i = iBegin;
	int j = iMiddle;

	// While there are elements in the left or right runs...
	for (int k = iBegin; k < iEnd; k++) {

		// If left run head exists and is <= existing right run head.
		if (i < iMiddle && (j >= iEnd || src[i] <= src[j])) {
			dest[k] = src[i];
			i = i + 1;
		}
		else {
			dest[k] = src[j];
			j = j + 1;
		}
	}
}