#pragma once

/**
 * LeetCode: 135. Candy
 * https://leetcode.com/problems/candy/
 * 
 * There are n children standing in a line. 
 * Each child is assigned a rating value given in the integer array ratings.
 *
 * You are giving candies to these children subjected to the following requirements:
 *  - Each child must have at least one candy.
 *  - Children with a higher rating get more candies than their neighbors.
 * Return the minimum number of candies you need to have to distribute the candies to the children.
 */


#define CANDY

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int candy(vector<int>& ratings);
int count(int n);

int candy_extraspace(vector<int>& ratings);

void run(void);

int candy_extraspace(vector<int>& ratings)
{
	if (ratings.size() == 0)	return 0;

	const unsigned int N = ratings.size();
	vector<int> buffer(N, 0); // N zeros
	int result = 0;

	buffer[0] = 1;

	for (unsigned int i = 1; i < N; i++)
	{
		if (ratings[i - 1] < ratings[i])
			buffer[i] = buffer[i - 1] + 1;
		else
			buffer[i] = 1;
	}

	for (int i = N - 2; i >= 0; i--)
	{
		if (ratings[i] > ratings[i + 1])
			buffer[i] = max(buffer[i], buffer[i + 1] + 1);
	}

	for (int b : buffer)
		result += b;

	return result;
}

int count(int n) 
{
	return (n * (n + 1)) / 2;
}

int candy(vector<int>& ratings)
{
	const unsigned int N = ratings.size();
	if (N <= 1) 
		return N;

	int candies = 0;

	int up = 0,			down = 0;
	int oldSlope = 0,	newSlope = 0;
	
	for (unsigned int i = 1; i < N; i++) 
	{
		// calculate new slope
		if (ratings[i] > ratings[i - 1])	
			newSlope = 1;
		else if (ratings[i] < ratings[i - 1])	
			newSlope = -1;
		else 
			newSlope = 0;

		if ((oldSlope > 0 && newSlope == 0) || (oldSlope < 0 && newSlope >= 0)) 
		{
			candies += count(up) + count(down) + max(up, down);
			up = down = 0;
		}

		if (newSlope > 0) 
			up++;
		else if (newSlope < 0) 
			down++;
		else 
			candies++;

		oldSlope = newSlope;
	}
	candies += count(up) + count(down) + max(up, down) + 1;
	return candies;
}



void run(void)
{
	unsigned int test = 1;
	cout << "135. Candy" << endl;
	/*{
		vector<int> ratings({ 1,2,3,4,5,3,2,1});
		int expected = 21;
		int actual = candy(ratings);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}*/
	{
		vector<int> ratings({ 1,2,3,4,5,3,2,1,2,6,5,4,3,3,2,1,1,3,3,3,4,2 });
		int expected = 47;
		int actual = candy(ratings);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> ratings({ 1, 0, 2 });
		int expected = 5;
		int actual = candy(ratings);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> ratings({ 1, 2, 2 });
		int expected = 4;
		int actual = candy(ratings);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> ratings({ 5, 4, 3 });
		int expected = 6;
		int actual = candy(ratings);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> ratings({ 5 });
		int expected = 1;
		int actual = candy(ratings);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> ratings;
		int expected = 0;
		int actual = candy(ratings);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
}

