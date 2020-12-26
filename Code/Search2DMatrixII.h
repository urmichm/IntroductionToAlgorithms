#pragma once

/**
 * Search a 2D Matrix II
 * Write an efficient algorithm that searches for a target value in an m x n integer matrix. 
 * The matrix has the following properties:
 *  Integers in each row are sorted in ascending from left to right.
 *  Integers in each column are sorted in ascending from top to bottom.
 *
 * Constraints:
 *   m == matrix.length
 *   n == matrix[i].length
 *   1 <= n, m <= 300
 *  -109 <= matix[i][j] <= 109
 *  All the integers in each row are sorted in ascending order.
 *  All the integers in each column are sorted in ascending order.
 *  -109 <= target <= 109
 */

#define SEARCH_2D_MATRIX_II

#include <vector>
#include <algorithm>
using namespace std;

/* Public functions declaration */
bool searchMatrix(vector<vector<int>>& matrix, int target);

/* Private functions declaration */
static bool DnC_searchMatrix(vector<vector<int>>& matrix, int rBegin, int rEnd, int cBegin, int cEnd, int target);
static bool BT_searchMatrix(vector<vector<int>>& matrix, int target);


bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	/* Choose the appraoch by commenting and uncommenting the function calls */
	//return DnC_searchMatrix(matrix, 0, matrix.size(), 0, matrix[0].size(), target);
	return BT_searchMatrix(matrix, target);
}


/**
 * @brief SearhMatrix algorithm, algorithm treats matrix as a Binary Search tree with root to be the element on the right upper conner.
 * Each node matrix[i][j] has two children: The left child matrix[i][j-1] < matrix[i][j] and the right one matrix matrix[i+1][j]
 * The alg travers the tree to find the target element;
 * @param matrix - matrix to travers
 * @param target - the value to find in the matrix
 * @return TRUE if the target element is in the matrix, FALSE otherwise
 */
static bool BT_searchMatrix(vector<vector<int>>& matrix, int target)
{
	const int M = matrix.size(); // number of rows, M <= 300
	const int N = matrix[0].size(); // number of columns, N >= 1
	
	int row = 0;    // row index
	int col = N-1;  // col index

	while (true)
	{
		if (matrix[row][col] > target)
		{
			col--;
		}
		else if (matrix[row][col] < target)
		{
			row++;
		}
		else
		{
			return true;
		}
		if (col < 0 || row >= M)
		{
			return false;
		}
	}

	/* Defence code; This line shall never be executed */
	return false;
}

/**
 * @brief Algoritm to find a target element in a 2D matrix. First, divide matrix in four parts:
 *  left-up, right-up, down-left, down-right. Recursively examine the remaining parts. The target element, if exist, shall be at least maatrix[0][0] and 
 *  at most matrix[matrix.size()-1][matrix[0].size()]. 
 * @params rBegin, cBegin starting indecies of the subarray 
 * @params rEnd, cEnd ending indecies of the subarray 
 *         [begin, end) format :)
 * @param target - the target element to find
 * @return True if element exist, False otherwise
 */
static bool DnC_searchMatrix(vector<vector<int>>& matrix, int rBegin, int rEnd, int cBegin, int cEnd, int target)
{
	// Check base case with a single element matrix
	if (((rEnd - rBegin) <= 1) && ((cEnd - cBegin) <= 1))
		return matrix[rBegin][cBegin] == target; 
	
	// Result variable 
	bool result = false;

	// target is less than all the elements in the array
	if (target < matrix[rBegin][cBegin])
		return result;

	// target is greater than all elements in the array
	if (target > matrix[max(0,rEnd - 1)][max(0,cEnd - 1)])
		return result;

	// Row's middle index
	int rMid = rBegin + (rEnd - rBegin) / 2;
	// Column's middle index
	int cMid = cBegin + (cEnd - cBegin) / 2;
	
	// Check Left-Upper section
	result = DnC_searchMatrix(matrix, rBegin, rMid, cBegin, cMid, target);

	// Check Right-Upper section
	if(false == result)
		result = DnC_searchMatrix(matrix, rBegin, rMid, cMid, cEnd, target);

	// Check Left-Down section
	if(false == result)
		result = DnC_searchMatrix(matrix, rMid, rEnd, cBegin, cMid, target);

	// Check Right-Down section
	if(false == result)
		result = DnC_searchMatrix(matrix, rMid, rEnd, cMid, cEnd, target);

	return result;
}

