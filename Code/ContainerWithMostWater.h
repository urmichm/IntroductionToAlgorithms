#pragma once
/**
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, 
such that the container contains the most water.

Notice that you may not slant the container.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void run(void);
int maxArea(vector<int>& height);

int maxArea(vector<int>& height) 
{
	int result = 1;

	int l = 0, r = height.size() - 1;
	result = (r - l) * min(height[l], height[r]);

	while (l != r)
	{
		int tmp = (r - l) * min(height[l], height[r]);
		result = max(result, tmp);
		if (height[l] < height[r])
			l++;
		else
			r--;
	}

	return result;
}


void run(void)
{
	vector<int> h({1,2,4,3});
	maxArea(h);
}
