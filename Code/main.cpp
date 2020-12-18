#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <vector>
#include <iostream>

#include "CountInversions.h"
#include "MaximumSubarray.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<int> arr({7,1,3,5,2,4,6});
	cout << "Vector created" << endl;

	cout << "Inversions: " << CountInversions(arr) << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;


	//vector<int> nums({ -2,1,-3,4,-1,2,1,-5,4 });
	//cout << "Expected max subarray is 6, actual is " << MaxSubArray(nums) << endl;

	cout << endl << endl;
	return 0;
}