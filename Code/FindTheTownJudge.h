/**
 * In a town, there are N people labelled from 1 to N.
 * There is a rumor that one of these people is secretly the town judge.
 * If the town judge exists, then:
 *  - The town judge trusts nobody.
 *  - Everybody (except for the town judge) trusts the town judge.
 *  - There is exactly one person that satisfies properties 1 and 2.
 *
 * You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.
 * If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.
 */

#pragma once
#define FIND_THE_TOWN_JUDGE
#include <vector>
#include <iostream>
using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {

	int result = -1;
	vector<int> in_degree(N, 0);
	vector<int> out_degree(N, 0);
	
	for (vector<int> p : trust) {
		out_degree[p[0] - 1]++;
		in_degree[p[1] - 1]++;
	}

	for (int i = 0; i < N; i++) {
		if (in_degree[i] == (N - 1) && out_degree[i] == 0) {
			// impossible to have two judges
			result = i + 1;
			break;
		}
	}

	return result;
}


void run()
{
	{
		int N = 3;
		vector<vector<int>> trust({{1, 2}, { 2, 3 }});
		int expected = -1;
		int actual = findJudge(N, trust);
		cout << (expected == actual ? "ok" : "ERROR") << endl;
	} 
	{
		int N = 4;
		vector<vector<int>> trust({ {1, 3},{1, 4},{2, 3},{2, 4},{4, 3} });
		int expected = -1;
		int actual = findJudge(N, trust);
		cout << (expected == actual ? "ok" : "ERROR") << endl;
	}
}
