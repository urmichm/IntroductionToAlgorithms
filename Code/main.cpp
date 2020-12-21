#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <vector>
#include <iostream>

#include "CountInversions.h"
#include "MaximumSubarray.h"
#include "ClosestPair.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<Point> arr(
		{
			Point(0,0),
			Point(4,-1),
			Point(6,1),
			Point(7,4),
			Point(5,5),
			Point(3,3),
			Point(1,5)
		});
	cout << "Vector created" << endl;

	pair<Point, Point> pair = ClosestPair(arr);

	cout << "p(" << pair.first.x << "," << pair.first.y << ") "
		<< "q(" << pair.second.x << "," << pair.second.y << ")";


	//vector<int> nums({ -2,1,-3,4,-1,2,1,-5,4 });
	//cout << "Expected max subarray is 6, actual is " << MaxSubArray(nums) << endl;

	cout << endl << endl;
	return 0;
}