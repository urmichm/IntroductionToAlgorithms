#pragma once

/**
 * Given an array arr. 
 * You can choose a set of integers and remove all the occurrences of these integers in the array.
 *
 * Return the minimum size of the set so that at least half of the integers of the array are removed.
 */


#define REDUCE_ARRAY_SIZE_TO_THE_HALF
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

void run(void);
int minSetSize(vector<int>& arr);


int minSetSize(vector<int>& arr) 
{
	unsigned int N = arr.size();
	unsigned int popped = 0;
	int result = 0;

	map<int, int> m;
	vector<int> freq;

	for (int n : arr)
		m[n] += 1;

	for (map<int,int>::iterator it = m.begin(); it != m.end(); it++)
		freq.push_back(it->second);

	make_heap(freq.begin(), freq.end());

	while (popped < N / 2)
	{
		pop_heap(freq.begin(), freq.end());
		popped += freq.back();
		freq.pop_back();
		result++;
	}


	return result;
}

void run(void)
{
	unsigned int test = 1;
	{
		vector<int> arr({ 3,3,3,3,5,5,5,2,2,7 });
		int expected = 2;
		int actual = minSetSize(arr);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
		/* Explanation: 
		Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 
		(i.e equal to half of the size of the old array).
		Possible sets of size 2 are {3,5},{3,2},{5,2}.
		Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] 
		which has size greater than half of the size of the old array.*/
	}
	{
		vector<int> arr({ 7,7,7,7,7,7,7 });
		int expected = 1;
		int actual = minSetSize(arr);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> arr({ 7,9 });
		int expected = 1;
		int actual = minSetSize(arr);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> arr({ 1,1,7,9 });
		int expected = 1;
		int actual = minSetSize(arr);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<int> arr({ 1,2,3,4,5,6,7,8,9,10 });
		int expected = 5;
		int actual = minSetSize(arr);
		cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}

}


