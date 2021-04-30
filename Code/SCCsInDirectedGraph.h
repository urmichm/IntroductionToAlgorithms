#define SCC_IN_DIRECTED_GRAPH

/**
 * Give a directed Graph G. Find all Strongly Connected Components (SCCs).
 * the Strongly Connected Component of a directed graph G are the equivalance classes of the relation
 * u~v <=> there exists a path u -> v and a path v -> u in the graph G
 *
 * Kosaraju's two-pass algorithm
 */

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Node {
public:
	/* value of the node */
	char val;
	/* leader of the component, this node belongs to */
	char component_leader;
	/* boolean filed to distinguish if the node has been discovered */
	bool visited;
	/* adjacent neightbors */
	vector<Node*> neighbors;

	/* Constuctor */
	Node(char _id) : val(_id){
		this->component_leader = (-1);
		this->visited = (false);
	}
};



static void SCCs_DirectedGraph(const unsigned char N, vector<vector<char>> edges);

static void SCCs_DFSLoop(vector<Node> &adjList, deque<char> &q, const bool forward);
static void SCCs_DFSWork(Node* &node, char &S, deque<char> &q, const bool forward);

static void SCCs_DirectedGraph(const unsigned char N, vector<vector<char>> edges);

static void print_graph(vector<Node>& adjList);
void run(void);


static void SCCs_DFSLoop(vector<Node>& adjList, deque<char>& q, const bool forward)
{
	char S = 0;    // source (used for component leaders)
	// safety check
	if (q.size() != adjList.size()) 
	{
		cout << "ERROR";
		exit(EXIT_FAILURE);
	}

	for (int lc = 0; lc < adjList.size(); lc++)
	{
		int n = forward ? q.front() : q.back(); 
		int i = n - 'A';
		forward ? q.pop_front() : q.pop_back();
		
		if(adjList[i].visited == false)
		{
			Node* node = &adjList[i];
			S = i + 'A';

			SCCs_DFSWork(node, S, q, forward);
		}
	}

	if (q.size() != adjList.size())
	{
		cout << "ERROR";
		exit(EXIT_FAILURE);
	}
}

static void SCCs_DFSWork(Node* &node, char &S, deque<char> &q, const bool forward)
{
	node->visited = true;
	node->component_leader = S;
	for (Node* next : node->neighbors)
	{
		if (next->visited == false)
		{
			SCCs_DFSWork(next, S, q, forward);
		}
	}
	forward ? q.push_back(node->val) : q.push_front(node->val);
}


static void SCCs_DirectedGraph(const unsigned char N, vector<vector<char>> edges)
{
	cout << "Strongly connected components in a directed graph" << endl;
	
	/* construct a graph and its reverse based on input parameters */
	vector<Node> adjList;    // actual graph
	vector<Node> adjListRev; // reverse graph
	deque<char> q;           // Queue to track the order of nodes
	for (unsigned char i = 0; i < N; i++) 
	{
		Node node('A' + i);
		adjList.push_back(node);
		adjListRev.push_back(node);
		q.push_back(node.val);
	}
	for (vector<char> edge : edges)
	{
		char idx_u = edge[0] - 'A';
		char idx_v = edge[1] - 'A';
		// edge u -> v
		adjList[idx_u].neighbors.push_back( &adjList[idx_v] );
		// reverse edge v -> u
		adjListRev[idx_v].neighbors.push_back( &adjListRev[idx_u] );
	}

	// Run DFS-loop on the reverse graph to obtain the finishing time of each node
	// Deque is used to store nodes in their finishing time order (finishing array)
	// Initially, we fill the queue with all the nodes in an orbitrary way.
	SCCs_DFSLoop(adjListRev, q, true);
	// after the first call the queue is filled according to nodes finishing time
	// so we shall go in reverse way.
	SCCs_DFSLoop(adjList, q, false);
	// now adjList graph contains information about its components
	// each node has a component-leader of the component it belongs to :)

	// to print the graph
	// print_graph(adjList);

	return;
}


void run(void)
{
	{
		vector<vector<char>> edges({ {'H','G'}, {'G','I'}, {'I','H'},  {'F','H'},
									 {'F','A'}, {'A','E'}, {'E','F'},  {'D','E'},
									 {'D','C'}, {'C','B'}, {'B','D'}, });
		const int N = 9;
		SCCs_DirectedGraph(N, edges);
	}
	return;
}



static void print_graph(vector<Node>& adjList)
{
	for (unsigned int i = 0; i < adjList.size(); i++)
	{
		cout << adjList[i].val << " belongs to " << adjList[i].component_leader << "." << endl;
	}
}

