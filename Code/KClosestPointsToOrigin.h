#pragma once

/**
 * We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
 *
 * (Here, the distance between two points on a plane is the Euclidean distance.)
 *
 * You may return the answer in any order.  
 * The answer is guaranteed to be unique (except for the order that it is in.)
 *
 * Example 1:
 * Input: points = [[1,3],[-2,2]], K = 1
 * Output: [[-2,2]]
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
 * Example 2:
 * Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 * Output: [[3,3],[-2,4]]
 * (The answer [[-2,4],[3,3]] would also be accepted.)
 */


#include <vector>
#include <algorithm>
#include <time.h>

#define K_CLOSEST

using namespace std;


/* Public functions declaration */
vector<vector<int>> kClosest(vector<vector<int>>& points, int K);

/* Private functions declaration */
static void semisort(vector<vector<int>>& points, int begin, int end, int K);
static int  partition(vector<vector<int>>& points, int begin, int end);
static void swap(vector<vector<int>>& points, int i, int j);
static int dist(vector<vector<int>>& points, int p);


vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
{
	/* initialize random seed: */
	srand(time(NULL));
	semisort(points, 0, points.size(), K);
	vector<vector<int>> result(points.begin(), points.begin() + K);
	return result;
}

/**
 * @brief Based on quicksort, the function finds K points with closest distance to the origin
 * @params begin and end are starting and ending indecies of the subarray to be semisorted in form [begin, end)
 * @param K - number of points to be found
 */
static void semisort(vector<vector<int>>& points, int begin, int end, int K)
{
	// Base case
	if ((end - begin) <= 1) 
		return;
	int rnd = rand();
	// choose random pivot
	int pivot = begin + rnd % (end - begin);
	// place pivot at the begining of the subarray
	swap(points, begin, pivot);

	// mid is the index of the pivot after partition
	int mid = partition(points, begin, end);

	if (mid < K-1)
		semisort(points, mid + 1, end, K);
	if (mid > K-1)
		semisort(points, begin, mid, K);
	return;
}


/**
 * Partition the subarray with pivot given on the egin index
 */
static int  partition(vector<vector<int>>& points, int begin, int end)
{
	int pivot_index = begin;
	int pivot = dist(points, pivot_index);

	int i = begin + 1;
	int j = end - 1;

	while (i != j)
	{
		if (dist(points, i) <= pivot)
			i++;
		else
		{
			swap(points, i, j);
			j--;
		}
	}

	if (dist(points, i) > pivot)
	{
		i =i - 1;
	}

	swap(points, pivot_index, i);
	pivot_index = i;

	return pivot_index;
}

/**
 * Calculate distance from the point points[p] to the oriin
 */
static int dist(vector<vector<int>>& points, int p)
{
	return points[p][0] * points[p][0] + points[p][1] * points[p][1];
}


/**
 * Swap i-th and j-th element in the points
 */
static void swap(vector<vector<int>>& points, int i, int j)
{
	int t_x = points[i][0];
	int t_y = points[i][1];

	points[i][0] = points[j][0];
	points[i][1] = points[j][1];

	points[j][0] = t_x;
	points[j][1] = t_y;
}
