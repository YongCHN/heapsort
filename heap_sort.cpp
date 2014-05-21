// heap_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <utility>
#include <cmath>
using namespace std;


void maximum_heapify(int A[], int length, int nodeIndex)
{
	int left = nodeIndex << 1;
	int right = (nodeIndex << 1) + 1;

	int largest = nodeIndex;
	if (left <= length && A[left - 1] > A[nodeIndex - 1])
		largest = left;
	if (right <= length && A[right  - 1] > A[largest - 1])
		largest = right;

	if (largest != nodeIndex)
	{
		std::swap(A[largest - 1], A[nodeIndex - 1]);

		maximum_heapify(A, length, largest);
	}
}

void build_maximum_heap(int A[], int length)
{
	int nodeIndex = static_cast<int>( length / 2);

	for (; nodeIndex >= 1; nodeIndex--)
		maximum_heapify(A, length, nodeIndex);
}

void heap_sort(int A[], int length)
{
	build_maximum_heap(A, length);

	do
	{
		std::swap(A[length - 1], A[0]);
		maximum_heapify(A, length - 1, 1);
		length--;
	} while (length > 0);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = { 2, 7, 12, 8, 11, 9, 10, 23 };
	heap_sort(A, 8);

	for (int i = 0; i < 8; i++)
		cout << A[i] << " ";
	cout << endl;


	return 0;
}

