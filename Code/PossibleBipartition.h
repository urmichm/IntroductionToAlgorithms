/**
 * Given a set of N people (numbered 1, 2, ..., N), 
 * we would like to split everyone into two groups of any size.
 *
 * Each person may dislike some other people, and they should not go into the same group.
 *
 * Formally, if dislikes[i] = [a, b],
 * it means it is not allowed to put the people numbered a and b into the same group.
 *
 * Return true if and only if it is possible to split everyone into two groups in this way.
 */

#define POSSIBLE_BIPARTITION

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iostream>
using namespace std;

/// You can simplify data structure to use less space 
/// However, it won't make change in an asymptotic view
/// multiple different data structs are used for practise and clear code

static void run(void);
bool possibleBipartition(int N, vector<vector<int>>& dislikes);


bool possibleBipartition(int N, vector<vector<int>>& dislikes)
{
	vector<vector<int>> graph;
	set<int> seen;
	map<int, int> v_color;
	queue<int> q;

	bool result = true;

	for (int i = 0; i < N; i++) {
		vector<int> list;
		graph.push_back(list);
	}

	for (vector<int> edge : dislikes) {
		int u = edge[0] - 1;
		int v = edge[1] - 1;
		// graph is undirected 
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// for every connected component
	for (int i = 0; result && i < N; i++)
	{
		if (seen.count(i) > 0) continue;

		// do colouring with BFS
		v_color[i] = 1;
		q.push(i);
		seen.insert(i);

		while (result && !q.empty())
		{
			int v = q.front();
			q.pop();
			int next_colour = (v_color[v] + 1) % 2;

			// go through edges v -> u
			for (int u : graph[v]) {
				if (seen.count(u) == 0) {
					seen.insert(u);
					v_color[u] = next_colour;
					q.push(u);
				}
				else {
					if (next_colour != v_color[u])
						result = false;
				}
			}
		}
	}
	return result;
}

static void run(void)
{
	int test_num = 1;
	// 1
	{	
		int  N = 4;
		vector<vector<int>>	dislikes({ {1, 2},{1, 3},{2, 4} });
		bool expected = true;
		bool actual = possibleBipartition(N, dislikes);
		cout << test_num++ << ": " << (expected == actual ? "OK" : "ERROR") << endl;
	}
	// 2
	{
		int  N = 3;
		vector<vector<int>>	dislikes({ {1, 2},{1, 3},{2, 3} });
		bool expected = false;
		bool actual = possibleBipartition(N, dislikes);
		cout << test_num++ << ": " << (expected == actual ? "OK" : "ERROR") << endl;
	}
	// 3
	{
		int  N = 5;
		vector<vector<int>>	dislikes({ {1, 2},{2, 3},{3, 4},{4, 5},{1, 5} });
		bool expected = false;
		bool actual = possibleBipartition(N, dislikes);
		cout << test_num++ << ": " << (expected == actual ? "OK" : "ERROR") << endl;
	}
	// 4
	{
		int  N = 5;
		vector<vector<int>>	dislikes({ {1, 2},{3, 4},{4, 5},{3, 5} });
		bool expected = false;
		bool actual = possibleBipartition(N, dislikes);
		cout << test_num++ << ": " << (expected == actual ? "OK" : "ERROR") << endl;
	}
	// 5
	{
		int  N = 10;
		vector<vector<int>>	dislikes({ {1, 2},{3, 4},{5, 6},{6, 7},{8, 9},{7, 8} });
		bool expected = true;
		bool actual = possibleBipartition(N, dislikes);
		cout << test_num++ << ": " << (expected == actual ? "OK" : "ERROR") << endl;
	}
	
	return;
}


 /**
  * Properties:
  * A bipartite graph has a colour index equal to 2 [used in the solution]
  *
  * A graph is bipartite if and only if it does NOT contain an odd cycle
  */



