#pragma once


/**
 * Given a set of n points P, find a pair of closest points
 * Distance between points is Euclidean distance 
 * Ass: Each point has its unique x and y coordinates
 */


#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

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



pair<Point,Point> ClosestPair(vector<Point>& points);
static pair<Point,Point> ClosestPair_BruteForce(vector<Point>& points);
static pair<Point, Point> DnC_ClosestPair(vector<Point>& Px, vector<Point>& Py);
static pair<Point, Point> ClosestSplitPair(vector<Point>& Px, vector<Point>& Py, int delta);
static int EuclideanDistance2(pair<Point, Point>& pair);
static int EuclideanDistance2(Point& p, Point& q);

pair<Point, Point> ClosestPair(vector<Point>& points)
{
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

static pair<Point, Point> ClosestPair_BruteForce(vector<Point>& points)
{
	if (points.size() == 2)
		return make_pair(points[0], points[1]);

	int p01 = EuclideanDistance2(points[0], points[1]);
	int p02 = EuclideanDistance2(points[0], points[2]);
	int p12 = EuclideanDistance2(points[1], points[2]);

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


static pair<Point, Point> DnC_ClosestPair(vector<Point>& Px, vector<Point>& Py)
{
	const int N = Px.size();
	if (N <= 3) // N could be 2 or 3
		return ClosestPair_BruteForce(Px);
	int mid = N / 2;
	int delta = INT_MAX;
	pair<Point, Point> result(Point(INT_MIN, INT_MIN), Point(INT_MAX, INT_MAX));

	Point m = Px[mid];

	vector<Point> Lx(Px.begin(), Px.begin() + mid);
	vector<Point> Ly;

	vector<Point> Rx(Px.begin() + mid, Px.end());
	vector<Point> Ry;

	for (Point p : Py){
		if (p.x < m.x)  Ly.push_back(p);
		else			Ry.push_back(p);
	}

	pair<Point, Point> left = DnC_ClosestPair(Lx, Ly);
	pair<Point, Point> right = DnC_ClosestPair(Rx, Ry);


	if (EuclideanDistance2(left) < EuclideanDistance2(right))
	{
		result = left;
		delta = EuclideanDistance2(left);
	}
	else
	{
		result = right;
		delta = EuclideanDistance2(right);
	}


	pair<Point, Point> split = ClosestSplitPair(Px, Py, delta);
	if (delta > EuclideanDistance2(split))
		result = split;

	return result;
}


static pair<Point, Point> ClosestSplitPair(vector<Point>& Px, vector<Point>& Py, int delta)
{
	const int N = Px.size();

	int mid = N / 2;
	int best = delta;
	pair<Point, Point> pair(Point(INT_MIN, INT_MIN), Point(INT_MAX, INT_MAX));

	Point m = Px[mid-1];
	int X = m.x;

	vector<Point> Sy;

	for (Point p : Px) {
		if ( X-delta < p.x &&  p.x < X + delta)  
			Sy.push_back(p);
	}

	for (unsigned int i = 0; i < Sy.size(); i++)
	{
		for (unsigned int j = 1; j < min(7U, Sy.size() - i); j++)
		{
			Point p = Sy[i];
			Point q = Sy[i + j];

			if (EuclideanDistance2(p, q) < best)
			{
				pair = make_pair(p, q);
				best = EuclideanDistance2(p, q);
			}
		}
	}

	return pair;
}

static int EuclideanDistance2(Point& p, Point& q)
{
	if (p.x == INT_MIN || p.x == INT_MAX)		return INT_MAX;
	if (p.y == INT_MIN || p.y == INT_MAX)		return INT_MAX;
	if (q.x == INT_MIN || q.x == INT_MAX)		return INT_MAX;
	if (q.y == INT_MIN || q.y == INT_MAX)		return INT_MAX;

	int dx = abs(p.x - q.x);
	int dy = abs(p.y - q.y);
	return dx * dx + dy * dy;
}


static int EuclideanDistance2(pair<Point, Point>& pair)
{
	Point& p = pair.first;
	Point& q = pair.second;

	if (p.x == INT_MIN || p.x == INT_MAX)		return INT_MAX;
	if (p.y == INT_MIN || p.y == INT_MAX)		return INT_MAX;
	if (q.x == INT_MIN || q.x == INT_MAX)		return INT_MAX;
	if (q.y == INT_MIN || q.y == INT_MAX)		return INT_MAX;

	int dx = abs(p.x - q.x);
	int dy = abs(p.y - q.y);
	return dx*dx + dy*dy;
}


