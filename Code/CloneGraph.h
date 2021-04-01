#pragma once

/**
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 * Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
 *
 * Test case format:
 *  For simplicity sake, each node's value is the same as the node's index (1-indexed). 
 *   For example, the first node with val = 1, the second node with val = 2, and so on. 
 *   The graph is represented in the test case using an adjacency list.
 *
 * Adjacency list is a collection of unordered lists used to represent a finite graph. 
 * Each list describes the set of neighbors of a node in the graph.
 *
 * The given node will always be the first node with val = 1. 
 * You must return the copy of the given node as a reference to the cloned graph.
 */

#define CLONE_GRAPH
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

class Node {
public:
	char val;
	bool visited;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();

		visited = false;
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();

		visited = false;
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;

		visited = false;
	}
};

void run(void);
static void print_graph(const vector<Node*>& adjList);
static void print_from_vertex( Node*& node);

Node* cloneGraph(Node* node);


Node* cloneGraph(Node* node) 
{
	if (node == nullptr)
		return nullptr;

	Node* root = new Node(node->val);

	queue<Node*> queue;
	map<char, Node*> new_list;
	set<char> seen;

	new_list[root->val]=root;
	seen.insert(node->val);

	for (Node* n : node->neighbors)
	{
		Node* u = new Node(n->val);
		root->neighbors.push_back(u);
		u->neighbors.push_back(root);
		new_list[u->val] = u;
		queue.push(n);
	}

	while (!queue.empty())
	{
		Node* old_v = queue.front();
		queue.pop();
		Node* new_v = new_list[old_v->val];

		for (Node* old_u : old_v->neighbors)
		{
			if (seen.count(old_u->val) != 0) 
				continue;
			
			if (new_list[old_u->val] == 0) 
			{
				Node* new_u = new Node(old_u->val);
				new_v->neighbors.push_back(new_u);
				new_u->neighbors.push_back(new_v);
				new_list[new_u->val] = new_u;
				queue.push(old_u);
			}
			else 
			{
				Node* new_u = new_list[old_u->val];
				new_v->neighbors.push_back(new_u);
				new_u->neighbors.push_back(new_v);
			}
		}
	
		seen.insert(old_v->val);
	}

	return root;
}




void run(void)
{
	vector<Node*> adjList;
	Node* a= new Node('a');
	Node* b = new Node('b');
	Node* c = new Node('c');
	Node* d = new Node('d');
	Node* e = new Node('e');

	// edge a-b
	a->neighbors.push_back(b);	b->neighbors.push_back(a);

	// edge a-c
	a->neighbors.push_back(c);	c->neighbors.push_back(a);
	
	// edge a-d
	a->neighbors.push_back(d);	d->neighbors.push_back(a);

	// edge b-d
	d->neighbors.push_back(b);	b->neighbors.push_back(d);

	// edge e-d
	d->neighbors.push_back(e);	e->neighbors.push_back(d);

	adjList.push_back(a);  adjList.push_back(c);
	adjList.push_back(b);  adjList.push_back(d);
	adjList.push_back(e);
	
	// print_graph(adjList);
	
	print_from_vertex(a);
	cout << endl;
	
	Node* copy = cloneGraph(a);

	print_from_vertex(copy);
	for (Node* n : adjList)
		delete n;

	return;
}


static void print_from_vertex( Node*& node)
{
	cout << node->val << " ";
	node->visited = true;
	for (Node* n : node->neighbors) {
		if (!n->visited) {
			print_from_vertex(n);
		}
	}

}


static void print_graph(const vector<Node*>& adjList)
{
	for (Node* n : adjList) 
	{
		cout << n->val << ": ";
		for (Node* e : n->neighbors)
		{
			cout << e->val << " ";
		}
		cout << endl;
	}
}


