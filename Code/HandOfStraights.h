#pragma once

/**
 * LeetCode: 846 https://leetcode.com/problems/hand-of-straights/
 * Alice has a hand of cards, given as an array of integers.
 * Now she wants to rearrange the cards into groups so that each group is size groupSize, 
 * and consists of groupSize consecutive cards.
 *
 * Return true if and only if she can.
 */

#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

void run(void);
bool isNStraightHand(vector<int>& hand, int groupSize);

/**
Constraints:
 1 <= hand.length <= 10000
 0 <= hand[i] <= 109
 1 <= groupSize <= hand.length
 */
bool isNStraightHand(vector<int>& hand, int groupSize) 
{
	const unsigned int N = hand.size();
	if ( (N % groupSize) != 0 )
		return false;
	const unsigned int numGroups = N / groupSize;
	vector<vector<int>> groups;

	sort(hand.begin(), hand.end()); /* O( N logN ) */

	/* O(N*g) */
	for (int card : hand) {
		bool isInserted = false;
		if (card != 0) 
		{
			for (unsigned int i = 0; i < groups.size() && !isInserted; i++) 
			{
				unsigned int group_size = groups[i].size();
				if (group_size < groupSize) {
					if (groups[i][group_size - 1] + 1 == card) {
						groups[i].push_back(card);
						isInserted = true;
					}
				}
			}
		}
		// insert card into a new group
		if (!isInserted) {
			// check if an empty group available
			if (groups.size() < numGroups)
			{
				vector<int> new_group;
				new_group.push_back(card);
				groups.push_back(new_group);
			}
			else
			{
				// no empty group found -> return false
				return false;
			}
		}
	}

	for (vector<int> g : groups)
		if (g.size() != groupSize)
			return false;

	return true;
}


void run(void)
{
	unsigned int test = 1;
	{
		vector<int> hand({ 1, 2, 3, 6, 2, 3, 4, 7, 8 });
		int groupSize = 3;
		bool expected = true;
		// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
		bool actual = isNStraightHand(hand, groupSize);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> hand({ 1,2,3,4,5 });
		int groupSize = 4;
		bool expected = false;
		bool actual = isNStraightHand(hand, groupSize);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
}
