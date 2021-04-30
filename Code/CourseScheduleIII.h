#pragma once


/**
 * LeetCode: 630. Course Schedule III
 * https://leetcode.com/problems/course-schedule-iii/
 * 
 * There are n different online courses numbered from 1 to n. 
 * Each course has some duration(course length) t and closed on dth day. 
 * A course should be taken continuously for t days and must be finished before or on the dth day. 
 * You will start at the 1st day.
 *
 * Given n online courses represented by pairs (t,d), 
 * your task is to find the maximal number of courses that can be taken.
 * 
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void run(void);
bool helper(vector<int> i, vector<int> j);
int scheduleCourse_slow(vector<vector<int>>& courses);
int scheduleCourse(vector<vector<int>>& courses);

/**
 * @brief Helper function to compare course based on their end date. 
 */
bool helper(vector<int> i, vector<int> j)
{
	return i[1] < j[1];
}

/**
 * Max Heap based on the course's duration (time)
 */
class CoursesHeap
{
private:
	vector<vector<int>> heap;
public:
	unsigned int size(void) { return heap.size(); }

	/**
	 * Pop the course with max-duration and return its duration
	 */
	int pop(void)
	{
		// (time,deadline) */
		int duration = heap[0][0];
		vector<int> tmp;
		unsigned int cur = 0;
		unsigned int left = 1;
		unsigned int right = 2;

		// swap in the heap first element and the last 
		heap[cur] = heap[heap.size() - 1u];
		// remove last element
		heap.pop_back();

		// both children exist
		while (left < heap.size() && right < heap.size())
		{
			if (heap[cur][0] < heap[left][0] && heap[cur][0] < heap[right][0])
			{
				if (heap[left][0] > heap[right][0])
				{
					// swap with left child
					tmp = heap[left];
					heap[left] = heap[cur];
					heap[cur] = tmp;
					cur = left;
				}
				else
				{
					// swap with right child
					tmp = heap[right];
					heap[right] = heap[cur];
					heap[cur] = tmp;
					cur = right;
				}
			}
			else if (heap[cur][0] < heap[left][0])
			{
				// swap with left child
				tmp = heap[left];
				heap[left] = heap[cur];
				heap[cur] = tmp;
				cur = left;
			}
			else if (heap[cur][0] < heap[right][0])
			{
				// swap with right child
				tmp = heap[right];
				heap[right] = heap[cur];
				heap[cur] = tmp;
				cur = right;
			}
			else
			{
				// no child greater that self
				break;
			}
			left = cur * 2 + 1;
			right = cur * 2 + 2;
		}


		// single child case (only left)
		if (left < heap.size() && right >= heap.size())
		{
			if (heap[cur][0] < heap[left][0])
			{
				// swap with left child
				tmp = heap[left];
				heap[left] = heap[cur];
				heap[cur] = tmp;
			}
		}

		return duration;
	}

	/**
	 * Push new course into the heap
	 */
	void push(vector<int> course)
	{
		unsigned int v_idx = heap.size();
		unsigned int parent = (v_idx % 2u) ? (v_idx / 2u) : (v_idx / 2u - 1u);

		heap.push_back(course);

		while (v_idx != 0 && heap[parent][0] < heap[v_idx][0])
		{
			// (time,deadline) */

			// swap elements
			int tmp_t = heap[parent][0];
			int tmp_d = heap[parent][1];

			heap[parent][0] = heap[v_idx][0];
			heap[parent][1] = heap[v_idx][1];

			heap[v_idx][0] = tmp_t;
			heap[v_idx][1] = tmp_d;

			// refresh indexes
			v_idx = parent;
			parent = (v_idx % 2u) ? (v_idx / 2u) : (v_idx / 2u - 1u);
		}
	}

	/**
	 * Get max-duration value
	 */
	int front(void)
	{
		if (heap.size() == 0)
			return 0;
		else
			return heap[0][0];
	}
};

// since we access max-duration course frequently, we shall using heap to accelerate the running time
int scheduleCourse(vector<vector<int>>& courses)
{
	const unsigned int N = courses.size();
	CoursesHeap taken;
	int time = 0;

	sort(courses.begin(), courses.end(), helper);

	// (time,deadline)
	for (unsigned int i = 0; i < N; i++)
	{
		if (time + courses[i][0] <= courses[i][1])
		{
			time = time + courses[i][0];
			taken.push(courses[i]);
		}
		else
		{
			// substitute max-duration course that is already taken with i-th course 
			// if duration of i-th course less than max-duration
			int max_dur = taken.front();
			if (courses[i][0] < max_dur)
			{
				taken.pop();
				taken.push(courses[i]);
				time = time - max_dur + courses[i][0];
			}
		}
	}

	return taken.size();
}

void run(void)
{
	unsigned int test = 1;

	std::cout << "Course Schedule III" << endl;
	{
		vector<vector<int>> courses({ {1000, 1250}, {2000, 3200}, {100, 200}, {200, 1300} });
		int actual = scheduleCourse(courses);
		int expected = 3;
		std::cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<vector<int>> courses({ {5, 15}, {3, 19}, {6, 7}, {2, 10}, {5, 16}, {8, 14}, {10, 11}, {2, 19} });
		int actual = scheduleCourse(courses);
		int expected = 5;
		std::cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}
	{
		vector<vector<int>> courses({{7, 16}, { 2, 3}, { 3, 12}, { 3, 14}, { 10, 19}, { 10, 16}, { 6, 8}, { 6, 11}, { 3, 13}, {6, 16}});
		int actual = scheduleCourse(courses);
		int expected = 4;
		std::cout << test++ << ": " << (expected == actual ? "OK" : "ERR") << endl;
	}

	return;
}




// https://leetcode.com/problems/course-schedule-iii/solution/
int scheduleCourse_slow(vector<vector<int>>& courses)
{
	const unsigned int N = courses.size();

	int time = 0;
	int count = 0;

	sort(courses.begin(), courses.end(), helper);

	// (time,deadline)
	for (unsigned int i = 0; i < N; i++)
	{
		// skip unavailable courses
		if (courses[i][0] == -1)
			continue;

		if (time + courses[i][0] <= courses[i][1])
		{
			time += courses[i][0];
			count++;
		}
		else
		{
			// substitute max-duration course that is already taken with i-th course 
			// if duration of i-th course less than max-duration
			unsigned int max_i = 0;
			for (unsigned int j = 0; j < i; j++)
			{
				if (courses[j][0] > courses[max_i][0])
					max_i = j;
			}

			if (courses[i][0] < courses[max_i][0])
			{
				time -= courses[max_i][0];
				time += courses[i][0];
				courses[max_i][0] = -1;
			}
			else
			{
				courses[i][0] = -1;
			}
		}
	}

	return count;
}
