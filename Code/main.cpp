#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "Search2DMatrixII.h"

#include <iostream>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#ifdef SEARCH_2D_MATRIX_II
	{
		vector<vector<int>> matrix = {
			{ 1 }, 
			{ 3 },
			{ 5 }
		};
		int target = 5;
		bool expected = true;
		cout << "Search 2D Matrix II " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	}
	{
		vector<vector<int>> matrix = {
			{ 1,  3,  5}
		};
		int target = 3;
		bool expected = true;
		cout << "Search 2D Matrix II " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	} 
	{
		vector<vector<int>> matrix = {
			{ 1,  4,  7, 11, 15},
			{ 2,  5,  8, 12, 19},
			{ 3,  6,  9, 16, 22},
			{10, 13, 14, 17, 24},
			{18, 21, 23, 26, 30}
		};
		int target = 5;
		bool expected = true;
		cout << "Search 2D Matrix II " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	}
	{
		vector<vector<int>> matrix = {
			{ 1,  4,  7, 11, 15},
			{ 2,  5,  8, 12, 19},
			{ 3,  6,  9, 16, 22},
			{10, 13, 14, 17, 24},
			{18, 21, 23, 26, 30}
		};
		int target = 24;
		bool expected = true;
		cout << "Search 2D Matrix II " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	} 
	{
		vector<vector<int>> matrix({
			{ 1,  4,  7, 11, 15}, 
			{ 2,  5,  8, 12, 19}, 
			{ 3,  6,  9, 16, 22},
			{10, 13, 14, 17, 24}, 
			{18, 21, 23, 26, 30}
		});
		int target = 20;
		bool expected = false;
		cout << "Search 2D Matrix II " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	}
	{
		vector<vector<int>> matrix({
			{ 1,  4,  7, 11, 15, 18},
			{ 2,  5,  8, 12, 19, 21},
			{ 3,  6,  9, 16, 22, 23},
			{10, 13, 14, 17, 24, 26}
		});
		int target = 20;
		bool expected = false;
		cout << "Search 2D Matrix II " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	}
#endif // SEARCH_2D_MATRIX_II

#ifdef K_LARGEST
	//{	
	//	vector<int> arr({ 3, 2, 1, 5, 6, 4 });
	//	int k = 2;
	//	int expected = 5;
	//	cout << "K Largets is " << expected << ", returned "
	//		<< findKthLargest(arr, k) << endl;
	//}
	{
		vector<int> arr({ 3, 2, 3, 1, 2, 4, 5, 5, 6 });
		int k = 4;
		int expected = 4;
		cout << "K Largets is " << expected << ", returned "
			<< findKthLargest(arr, k) << endl;
	}
#endif // K_LARGEST

#ifdef QUICK_SORT
	{
		vector<int> arr({ 3, 2, 3, 1, 2, 4, 5, 5, 6 });
		quicksort(arr);
		for (auto a : arr)
			cout << a << " ";

	}
#endif // QUICK_SORT
	
#ifdef K_CLOSEST
	vector<vector<int>> points{ {0,10},{0,1},{0,5},{0,2},{0,4},{0,9},{0,3},{0,6},{0,8},{0,7}, };
	vector<vector<int>> result = kClosest(points, 4);
	for (auto p : result)
		cout << "(" << p[0] << "," << p[1] << ") ";
#endif // K_CLOSEST

#ifdef CLOSEST_PAIR
	{
		cout << "Closest Pair" << endl;
		vector<Point> arr(
			{
				Point(-7,-7),
				Point(0,0),
				Point(4,-1),
				Point(6,1),
				Point(7,4),
				Point(5,5),
				Point(10,6),
				Point(-2,-3),
				Point(3,3),
				Point(8,-2),
				Point(13,7),
				Point(2,2)
			});
		cout << "Vector created" << endl;

		pair<Point, Point> pair = ClosestPair(arr);

		cout << "p(" << pair.first.x << "," << pair.first.y << ") "
			<< "q(" << pair.second.x << "," << pair.second.y << ")";
	}
#endif // CLOSEST_PAIR


	cout << endl << endl;
	return 0;
}
