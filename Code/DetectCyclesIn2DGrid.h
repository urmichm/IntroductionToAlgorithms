#pragma once

#define DETECT_DYCLES_IN_2D_GRID

/**
 * Given a 2D array of characters grid of size m x n, 
 * you need to find if there exists any cycle consisting of the same value in grid.
 *
 * A cycle is a path of length 4 or more in the grid that starts and ends at the same cell.
 * From a given cell, you can move to one of the cells adjacent to it - in one of the four 
 * directions(up, down, left, or right), if it has the same value of the current cell.
 *
 * Also, you cannot move to the cell that you visited in your last move.For example, 
 * the cycle(1, 1) -> (1, 2) -> (1, 1) is invalid because from(1, 2) we visited(1, 1) which was the last visited cell.
 *
 * Return true if any cycle of the same value exists in grid, otherwise, return false.
 */

#include <vector>
#include <iostream>
using namespace std;

void run(void);

bool containsCycle(vector<vector<char>>& grid);
bool DFS(vector<vector<char>>& grid, vector<vector<bool>>& seen, int prev_r, int prev_c, int row, int col);

bool containsCycle(vector<vector<char>>& grid)
{
	bool result = false;
	if (grid.size() < 1) return result;
	if (grid[0].size() < 1) return result;

	vector<bool> row(grid[0].size(), false);
	vector<vector<bool>> seen(grid.size(), row);


	for (unsigned int r = 0; r < grid.size() && !result; r++)
	{
		for(unsigned int c = 0; c < grid[0].size() && !result; c++)
			if(seen[r][c] == false)
				result = DFS(grid, seen, -1, -1, r, c);
	}
	

	return result;
}


bool DFS(vector<vector<char>>& grid, vector<vector<bool>>& seen, int prev_r, int prev_c, int row, int col)
{
	bool result = false;
	if (prev_c == -1)
	{
		seen[row][col] = true;
		result =           DFS(grid, seen, row, col, row + 1, col);
		result = result || DFS(grid, seen, row, col, row - 1, col);
		result = result || DFS(grid, seen, row, col, row, col + 1);
		result = result || DFS(grid, seen, row, col, row, col - 1);
		return result;
	}
	
	if (row >= (int)grid.size()    || row < 0) return false;
	if (col >= (int)grid[0].size() || col < 0) return false;

	if (grid[row][col] != grid[prev_r][prev_c]) return false;

	if( seen[row][col] == true) 
		return true;
	
	seen[row][col] = true;

	if (prev_r != row + 1)	result =           DFS(grid, seen, row, col, row + 1, col);
	if (prev_r != row - 1)	result = result || DFS(grid, seen, row, col, row - 1, col);
	
	if (prev_c != col + 1)	result = result || DFS(grid, seen, row, col, row, col + 1);
	if (prev_c != col - 1)	result = result || DFS(grid, seen, row, col, row, col - 1);

	return result;
}


void run(void)
{
	{
		vector<vector<char>> grid(
			{
			{'d', 'b', 'b'},
			{'c', 'a', 'a'},
			{'b', 'a', 'c'},
			{'c', 'c', 'c'},
			{'d', 'd', 'a'}
			}
		);

		bool expected = false;
		bool actual = containsCycle(grid);
		cout << (expected == actual ? "OK" : "WRONG") << endl;
	}
	{
		vector<vector<char>> grid(
			{
			{'a', 'b', 'b', 'b', 'b'},
			{'a', 'b', 'c', 'a', 'c'},
			{'a', 'b', 'b', 'a', 'b'},
			{'a', 'b', 'b', 'b', 'b'}
			}
		);

		bool expected = true;
		bool actual = containsCycle(grid);
		cout << (expected == actual ? "OK" : "WRONG") << endl;
	}
	return;
}
