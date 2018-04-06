#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
const int SIZE = 25001;
int a[SIZE];
void process()
{
	for (int i = SIZE; i > 0; i--)
	{
		int j = SIZE - i;
		a[j] = i;
	}
}
void print()
{
	int size = SIZE;
	for (auto i = 0; i < size; i++)
	{
		cout << a[i] << "    ";
		if (i % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}
void merge(int a[], int temp[], int left, int mid, int right)
{
	int left_t, right_t, index_t;
	left_t = left;
	right_t = mid;
	index_t = left;
	while ((left_t <= mid - 1) && (right_t <= right))
	{
		if (a[left_t] < a[right_t])
		{
			temp[index_t++] = a[left_t++];
		}
		else
		{
			temp[index_t++] = a[right_t++];
		}
	}
	while (left_t < mid - 1)
	{
		temp[index_t++] = a[left_t++];
	}
	while (right_t <= right)
	{
		temp[index_t++] = a[right_t++];
	}
	for (int i = left; i <= right; i++)
	{
		a[i] = temp[i];
	}
}
void _mergesort(int a[], int temp[], int low, int high)
{
	if (low >= high) exit(EXIT_FAILURE);
	else if (high > low)
	{
		int mid = low + (high - low) / 2;
		_mergesort(a, temp, low, mid);
		_mergesort(a, temp, mid + 1, high);
		merge(a, temp, left, mid + 1, right);
	}
}
void mergesortOp(int a[], int n)
{
	int *temp = new int[n];
	_mergesort(a, temp, 0, n - 1);
}
int main()
{
	process();
	mergesortOp(a, SIZE);
	print();
	return 0;
}
