#pragma once
/**
 * General Heap Implementation 
 */

#define HEAP_GENERAL
#define RANDOM_TEST_SIZE	555

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/** Public fuction declaration **/
void test_heap(void);


/**
 * Maximum Heap class 
 */
template <class T>
class HeapMax {
private:
	vector<T> heap;

public:

	/* Used std library to check if the heap is valid */
	bool std_is_heap(void)
	{
		return is_heap(heap.begin(), heap.end());
	}

	/* Used std library to make a heap */
	void std_make_heap(void)
	{
		make_heap(heap.begin(), heap.end());
	}

	/* Insert and Bubble Up */
	void push(T _val)
	{
		unsigned int v_idx = heap.size();
		unsigned int parent = (v_idx % 2u) ? (v_idx / 2u) : (v_idx / 2u - 1u);

		heap.push_back(_val);

		while (v_idx != 0 && heap[parent] < heap[v_idx])
		{
			// swap elements
			T tmp = heap[parent];
			heap[parent] = heap[v_idx];
			heap[v_idx] = tmp;

			// refresh indexes
			v_idx = parent;
			parent = (v_idx % 2u) ? (v_idx / 2u) : (v_idx / 2u - 1u);
		}
	}

	/* Extract Max and Bubble Down */
	T pop(void)
	{
		T result = heap[0];
		T tmp;
		unsigned int cur   = 0;
		unsigned int left  = 1;
		unsigned int right = 2;

		heap[cur] = heap[heap.size() - 1u];
		heap.pop_back();

		// both children exist
		while (left < heap.size() && right < heap.size())
		{
			if (heap[cur] < heap[left] && heap[cur] < heap[right])
			{
				if (heap[left] > heap[right])
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
			else if (heap[cur] < heap[left])
			{
				// swap with left child
				tmp = heap[left];
				heap[left] = heap[cur];
				heap[cur] = tmp;
				cur = left;
			}
			else if (heap[cur] < heap[right])
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
			left  = cur * 2 + 1;
			right = cur * 2 + 2;
		}


		// single child case (only left)
		if (left < heap.size() && right >= heap.size())
		{
			if (heap[cur] < heap[left])
			{
				// swap with left child
				tmp = heap[left];
				heap[left] = heap[cur];
				heap[cur] = tmp;
			}
		}

		return result;
	}

	/** Standard methods **/

	/* Return heap size */
	unsigned int size(void)
	{
		return heap.size();
	}

	/* Operator [] */
	T operator[](const unsigned int index) 
	{
		return heap[index];
	}

	/* return iterator begin */
	typename vector<T>::iterator begin() {
		return heap.begin();
	}

	/* return iterator end */
	typename vector<T>::iterator end() {
		return heap.end();
	}
};


/** Public function definition **/

void test_heap(void)
{
	HeapMax<int> heap;

	cout << "Random test" << endl ;
	cout << "Insert values.." << endl;
	for (int i = 0; i < RANDOM_TEST_SIZE; i++)
	{
		int val = rand() % 1000;
		heap.push(val);
		if (false == heap.std_is_heap())
		{
			cout << "FAIL inserting a value" << endl;
			exit(EXIT_FAILURE);
		}
	}

	cout << "Clear heap.." << endl;
	while (heap.size() > 0)
	{
		heap.pop();
		if (false == heap.std_is_heap())
		{
			cout << "ERROR poping a value" << endl;
			exit(EXIT_FAILURE);
		}
	}

	cout << "Test passed !" << endl;

	return;
}