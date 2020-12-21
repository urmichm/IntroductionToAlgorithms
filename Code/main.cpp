#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


#include "KClosestPointsToOrigin.h"
#include <iostream>

static void ClosestPair_test(void);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<vector<int>> points{ {0,10},{0,1},{0,5},{0,2},{0,4},{0,9},{0,3},{0,6},{0,8},{0,7}, };

	vector<vector<int>> result = kClosest(points, 4);

	for (auto p : result)
		cout << "(" << p[0] << "," << p[1] << ") ";
	//vector<int> nums({ -2,1,-3,4,-1,2,1,-5,4 });
	//cout << "Expected max subarray is 6, actual is " << MaxSubArray(nums) << endl;

	cout << endl << endl;
	return 0;
}


static void ClosestPair_test(void)
{
	//vector<Point> arr(
	//	{
	//		Point(-7,-7),
	//		Point(0,0),
	//		Point(4,-1),
	//		Point(6,1),
	//		Point(7,4),
	//		Point(5,5),
	//		Point(10,6),
	//		Point(-2,-3),
	//		Point(3,3),
	//		Point(8,-2),
	//		Point(13,7),
	//		Point(2,2)
	//	});
	//cout << "Vector created" << endl;

	//pair<Point, Point> pair = ClosestPair(arr);

	//cout << "p(" << pair.first.x << "," << pair.first.y << ") "
	//	<< "q(" << pair.second.x << "," << pair.second.y << ")";


}
