#pragma once

#define IS_GRAPH_BIPARTITE

/**
 * Given an undirected graph, return true if and only if it is bipartite.
 *
 * Recall that a graph is bipartite if we can split its set of nodes into two independent subsets A and B, 
 * such that every edge in the graph has one node in A and another node in B.
 *
 * The graph is given in the following form: 
 *   graph[i] is a list of indexes j for which the edge between nodes i and j exists.  
 *   Each node is an integer between 0 and graph.length - 1.  
 * There are no self edges or parallel edges: 
 *   graph[i] does not contain i, and it doesn't contain any element twice.
 *
 * Constrains:
 *   1 <= graph.length <= 100
 *   0 <= graph[i].length < 100
 *   0 <= graph[i][j] <= graph.length - 1
 *   graph[i][j] != i
 *   All the values of graph[i] are unique.
 *   The graph is guaranteed to be undirected.
 */

#include <vector>
#include <map>
#include <unordered_set>
using namespace std;


bool isBipartite(vector<vector<int>>& graph);
static bool DFS_hasOddCycle(vector<vector<int>>& graph, unordered_set<int>& seen, map<int, int>& depth,  int v, int prev);

/**
 * @brief Function check if the graph is biipartite
 * @param graph - the graph to be checked
 * @return True if graph is bipartite, False otherwise
 */
bool isBipartite(vector<vector<int>>& graph) 
{
	bool hasOddCycle = false;
	unordered_set<int> seen;
	map<int, int> depth;

	for (int v = 0; v < graph.size() && !hasOddCycle; v++)
	{
		if (seen.find(v) != seen.end())
			continue;
		depth[v] = 0;
		hasOddCycle = DFS_hasOddCycle(graph, seen, depth, v, -1);
		depth.clear();
	}

	// G is bipartite iff G has NO odd Cycle
	return !hasOddCycle;
}


/**
 * @brief Function uses the DFS algorith to check if the graph has an odd cycle
 * @param graph - The graph to check
 * @param seen - the set of visited verticies
 * @param depth - the depth of vertex with respect to original source vertex
 * @param v - vertex to be a new source 
 * @param prev - previous vertex, if prev is -1, then it is the first call and v is an original source vertex
 * @return True if the graph has an odd cycle, False otherwise
 */
static bool DFS_hasOddCycle(vector<vector<int>>& graph, unordered_set<int>& seen, map<int, int>& depth, int v, int prev)
{
	// If vertex v is visited before, we found a cycle
	if (seen.find(v) != seen.end())
	{
		int v_depth = depth[prev] + 1;
		// if the cycle is even return false
		if ((v_depth - depth[v]) % 2 == 0)
			return false;
		else
			return true;
	}

	// mark vertex as visited
	seen.insert(v);
	
	// calculate its depth from original vertex, 
	// if prev == -1, the vertex v is the original and has depth 0
	depth[v] = (prev == -1) ? 0 : depth[prev] + 1;

	for (int u : graph[v])
	{	
		/* v-u edge */
		// skip back-edge to avoid an extra recursive call :) could be removed 
		if (u == prev)
			continue;

		// Go recursively via all the edges of v
		if (true == DFS_hasOddCycle(graph, seen, depth, u, v))
			// once an odd cyle found, stop algorithm
			return true;
	}

	// no odd cycle found
	return false;
}


/**
 * Property:
 * A graph is bipartite if and only if it does not contain an odd cycle
 */
