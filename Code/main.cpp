#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
#ifdef FIND_THE_TOWN_JUDGE
		run();
#endif // FIND_THE_TOWN_JUDGE

#ifdef THREE_SUM_PROBLEM
	run();
#endif // DETECT_DYCLES_IN_2D_GRID


#ifdef DETECT_DYCLES_IN_2D_GRID
	run();
#endif // DETECT_DYCLES_IN_2D_GRID


#ifdef SCC_IN_DIRECTED_GRAPH
	SCCs_DirectedGraph();
#endif // SCC_IN_DIRECTED_GRAPH

#ifdef DIVIDE_TWO_INTEGERS
	{
		int dividend = 10, divisor = 3;
		int expected = 3;
		//  Explanation : 10 / 3 = truncate(3.33333..) = 3.
	}
	{
		int dividend = 7, divisor = -3;
		int expected = -2;
		//  Explanation : 7 / -3 = truncate(-2.33333..) = -2.
	}
	{
		int dividend = 0, divisor = 1;
		int expected = 0;
	}
	{
		int dividend = 1, divisor = 1;
		int expected = 1;
	}
#endif  // DIVIDE_TWO_INTEGERS

#ifdef IS_GRAPH_BIPARTITE
	{
		vector<vector<int>> g{ {{1,3},{0,2},{1,3},{0,2}} };
		bool expected = true;
		cout << "Is Graph bipatite? " << expected << " | " << isBipartite(g) << endl;
	}
	{
		vector<vector<int>> g{ {{1,3,2},{0,2},{0,1,3},{0,2}} };
		bool expected = false;
		cout << "Is Graph bipatite? " << expected << " | " << isBipartite(g) << endl;
	}
	{
		vector<vector<int>> g{ 
			{},				// 0
			{2,4,6},		// 1
			{1,4,8,9},		// 2
			{7,8},			// 3
			{1,2,8,9},		// 4
			{6,9},			// 5
			{1,5,7,8,9},	// 6
			{3,6,9},		// 7
			{2,3,4,6,9},	// 8
			{2,4,5,6,7,8}	// 9
		};
		bool expected = false;
		cout << "Is Graph bipatite? " << expected << " | " << isBipartite(g) << endl;
	}
	{
		vector<vector<int>> g{
			{3, 4, 6},		// 0
			{3, 6},			// 1
			{3, 6},			// 2
			{0, 1, 2, 5},	// 3
			{0, 7, 8},		// 4 
			{3},			// 5 
			{0, 1, 2, 7},	// 6
			{4, 6},			// 7
			{4},			// 8 
			{}				// 9
		};
		bool expected = true;
		cout << "Is Graph bipatite? " << expected << " | " << isBipartite(g) << endl;
	}
#endif // IS_GRAPH_BIPARTITE

#ifdef DIFFERENT_WAYS_TO_ADD_PARENTHESES
	{
		vector<int> res = diffWaysToCompute("2*3-4*5");
		for (int n : res)
			cout << n << " ";
		cout << endl;
	}
	{
		vector<int> res = diffWaysToCompute("25");
		for (int n : res)
			cout << n << " ";
		cout << endl;
	}
	{
		vector<int> res = diffWaysToCompute("23-4*5");
		for (int n : res)
			cout << n << " ";
		cout << endl;
	}
#endif // DIFFERENT_WAYS_TO_ADD_PARENTHESES

#ifdef LONGEST_SUBSTRING_WITH_AT_LEASET_K_REPEAT_CHAR

	{
		string s = "aaabb";
		int k = 3;
		int expected = 3;
		cout << "Longest substr with at least K repeated chars " << expected << ", returned "
			<< longestSubstring(s, k) << endl;
	}
	{
		string s = "ababbc";
		int k = 2;
		int expected = 5;
		cout << "Longest substr with at least K repeated chars " << expected << ", returned "
			<< longestSubstring(s, k) << endl;
	}
	{
		string s = "a";
		int k = 1;
		int expected = 1;
		cout << "Longest substr with at least K repeated chars " << expected << ", returned "
			<< longestSubstring(s, k) << endl;
	}
	{
		string s = "c";
		int k = 2;
		int expected = 0;
		cout << "Longest substr with at least K repeated chars " << expected << ", returned "
			<< longestSubstring(s, k) << endl;
	}
	{
		string s = "abxabbc";
		int k = 2;
		int expected = 2;
		cout << "Longest substr with at least K repeated chars " << expected << ", returned "
			<< longestSubstring(s, k) << endl;
	}

#endif // LONGEST_SUBSTRING_WITH_AT_LEASET_K_REPEAT_CHAR

#ifdef SEARCH_2D_MATRIX_I

	{
		vector<vector<int>> matrix = {
			{ 1 },
			{ 3 },
			{ 5 }
		};
		int target = 5;
		bool expected = true;
		cout << "Search 2D Matrix I " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	}
	{
		vector<vector<int>> matrix = {
			{ 1,  3,  5}
		};
		int target = 3;
		bool expected = true;
		cout << "Search 2D Matrix I " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	}
	{
		vector<vector<int>> matrix = {
			{  1,   3,   5},
			{ 11,  13,  15},
			{ 21,  23,  25}
		};
		int target = 24;
		bool expected = false;
		cout << "Search 2D Matrix I " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	}
	{
		vector<vector<int>> matrix = {
			{  1,   3,   5,  6},
			{ 11,  13,  15, 17},
			{ 21,  23,  25, 19},
			{ 31,  53,  65, 79}
		};
		int target = 24;
		bool expected = false;
		cout << "Search 2D Matrix I " << expected << ", returned "
			<< searchMatrix(matrix, target) << endl;
	}
#endif // SEARCH_2D_MATRIX_I

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
		cout << "Search 2D Matrix II" << expected << ", returned "
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
		cout << "Search 2D Matrix II" << expected << ", returned "
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


	return 0;
}
