#pragma once


/**
 * NOTE: casting from double to int is not perfect
 * Given a set of n points P, find a pair of closest points
 * Distance between points is Euclidean distance 
 * Ass: Each point has its unique x and y coordinates
 */


#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/**
 * Class Point
 */
class  Point {
public:
	int x;
	int y;

	Point(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}

	bool operator==(Point& other)
	{
		return this->x == other.x && this->y == other.y;
	};
};


/* Public functions declaration */
pair<Point,Point> ClosestPair(vector<Point>& points);

/* Private functions declaration */
static pair<Point,Point> ClosestPair_BruteForce(vector<Point>& points);
static pair<Point, Point> DnC_ClosestPair(vector<Point>& Px, vector<Point>& Py);
static pair<Point, Point> ClosestSplitPair(vector<Point>& Px, vector<Point>& Py, int delta);
static int EuclideanDistance(pair<Point, Point>& pair);
static int EuclideanDistance(Point& p, Point& q);


/**
 * @brief Algorithm to solve the Closest Pair problem
 * @param points - the problem set, never empty, contains at least 2 points
 */
pair<Point, Point> ClosestPair(vector<Point>& points)
{
	if (points.size() == 2)
		return make_pair(points[0], points[1]);

	vector<Point> Px(points); 
	vector<Point> Py(points); 
	// points sorted by x-coord
	sort(Px.begin(), Px.end(), [](Point a, Point b) {
		return a.x < b.x;
	});
	// points sorted by y-coord
	sort(Py.begin(), Py.end(), [](Point a, Point b) {
		return a.y < b.y;
	});

	return DnC_ClosestPair(Px, Py);
}


/**
 * Brute Force method to solve the Problem in the base case (when numbers of points is at most 3)
 */
static pair<Point, Point> ClosestPair_BruteForce(vector<Point>& points)
{
	if (points.size() == 2)
		return make_pair(points[0], points[1]);

	int p01 = EuclideanDistance(points[0], points[1]);
	int p02 = EuclideanDistance(points[0], points[2]);
	int p12 = EuclideanDistance(points[1], points[2]);

	if (p01 <= p02 && p01 <= p12)
	{
		return make_pair(points[0], points[1]);
	}
	else if (p02 <= p01 && p02 <= p12)
	{
		return make_pair(points[0], points[2]);
	}
	return make_pair(points[1], points[2]);
}


/**
 * Divide and Conquer apprach to solve the Closest Pair problem
 */
static pair<Point, Point> DnC_ClosestPair(vector<Point>& Px, vector<Point>& Py)
{
	const int N = Px.size();
	if (N <= 3) // N could be 2 or 3, since the problem set is non-empty
		return ClosestPair_BruteForce(Px);
	int mid = N / 2;
	int delta = INT_MAX;
	pair<Point, Point> result(Point(INT_MIN, INT_MIN), Point(INT_MAX, INT_MAX));

	Point m = Px[mid];

	// Extra space used !
	vector<Point> Lx(Px.begin(), Px.begin() + mid);
	vector<Point> Ly;

	vector<Point> Rx(Px.begin() + mid, Px.end());
	vector<Point> Ry;

	for (Point p : Py){
		if (p.x < m.x)  Ly.push_back(p);
		else			Ry.push_back(p);
	}

	// Go recursively on left and right halves
	pair<Point, Point> left = DnC_ClosestPair(Lx, Ly);
	pair<Point, Point> right = DnC_ClosestPair(Rx, Ry);

	// find delta
	if (EuclideanDistance(left) < EuclideanDistance(right))
	{
		result = left;
		delta = EuclideanDistance(left);
	}
	else
	{
		result = right;
		delta = EuclideanDistance(right);
	}

	// find the closest pair in the strip
	pair<Point, Point> split = ClosestSplitPair(Px, Py, delta);
	if (delta > EuclideanDistance(split))
		result = split;

	// return the result
	return result;
}

/**
 * Check if closest pair of points are split between L and R halves
 */
static pair<Point, Point> ClosestSplitPair(vector<Point>& Px, vector<Point>& Py, int delta)
{
	const int N = Px.size();
	// Calculate midle point on X axis
	int mid = N / 2;
	// Get X axis of the middle point
	int X = Px[mid - 1].x;


	pair<Point, Point> result_pair(Point(INT_MIN, INT_MIN), Point(INT_MAX, INT_MAX));

	// Points in the critical strip
	vector<Point> Sy;
	for (Point p : Py) {
		// Add points in the script sorted by Y-axis
		if ( X-delta < p.x &&  p.x < X + delta)  
			Sy.push_back(p);
	}

	// Go through each point in the critical strip
	for (unsigned int i = 0; i < Sy.size(); i++)
	{
		// Compare each point up to its 7 closest neighbors
		for (unsigned int j = 1; j < min(8U, Sy.size() - i); j++)
		{
			Point p = Sy[i];
			Point q = Sy[i + j];

			// If we find a closer pair of points, update the result
			if (EuclideanDistance(p, q) < delta)
			{
				result_pair = make_pair(p, q);
				delta = EuclideanDistance(p, q);
			}
		}
	}

	return result_pair;
}

/**
 * Find EuclideanDistance^2 between a pair of points
 * @param p,q - a pair of points
 */static int EuclideanDistance(Point& p, Point& q)
{
	if (p.x == INT_MIN || p.x == INT_MAX)		return INT_MAX;
	if (p.y == INT_MIN || p.y == INT_MAX)		return INT_MAX;
	if (q.x == INT_MIN || q.x == INT_MAX)		return INT_MAX;
	if (q.y == INT_MIN || q.y == INT_MAX)		return INT_MAX;

	int dx = abs(p.x - q.x);
	int dy = abs(p.y - q.y);
	return ceil(sqrt(dx*dx + dy*dy));
}


/**
 * Find EuclideanDistance^2 between a pair of points
 * @param pair - a pair of points
 */
static int EuclideanDistance(pair<Point, Point>& pair)
{
	Point& p = pair.first;
	Point& q = pair.second;

	if (p.x == INT_MIN || p.x == INT_MAX)		return INT_MAX;
	if (p.y == INT_MIN || p.y == INT_MAX)		return INT_MAX;
	if (q.x == INT_MIN || q.x == INT_MAX)		return INT_MAX;
	if (q.y == INT_MIN || q.y == INT_MAX)		return INT_MAX;

	int dx = abs(p.x - q.x);
	int dy = abs(p.y - q.y);
	return ceil( sqrt(dx*dx + dy*dy) );
}


