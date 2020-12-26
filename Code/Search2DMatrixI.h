#pragma once

/**
 * Search a 2D Matrix I
 * Write an efficient algorithm that searches for a target value in an m x n integer matrix.
 * The matrix has the following properties:
 *  Integers in each row are sorted from left to right.
 *  The first integer of each row is greater than the last integer of the previous row.
 *
 * Constraints:
 *   m == matrix.length
 *   n == matrix[i].length
 *   1 <= n, m <= 100
 *  -10^4 <= matrix[i][j], target <= 10^4
 */

#define SEARCH_2D_MATRIX_I

#include <vector>
#include <algorithm>
using namespace std;

/* Public functions declaration */
bool searchMatrix(vector<vector<int>>& matrix, int target);


/**
 * @brief The function uses binary search to find the target value.
 * Binary search sees matrix as a sorted array constracted by concatanating all the rows of the matrix
 * @param the 2D matrix to traverse
 * @param target -  the value to look for
 * @return TRUE if target value is in the matrix, FALSE otherwise
 */
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int left = 0;
	int right = matrix.size() * matrix[0].size() - 1;

	const int N = matrix[0].size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (matrix[mid / N][mid % N] > target)
			right = mid;
		if (matrix[mid / N][mid % N] < target)
			left = mid + 1;

		if (matrix[mid / N][mid % N] == target)
			return true;
	}

	return matrix[left / N][left % N] == target;
}

