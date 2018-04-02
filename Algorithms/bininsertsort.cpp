#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#define SIZE 20
using namespace std;
int a[SIZE];
void process()
{
	for (auto i = SIZE; i > 0; i--)
	{
		int j = SIZE - i;
		a[j] = i;
	}
}
void print()
{
	size_t size = SIZE;
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
size_t binlocator(size_t low, size_t high, int item)
{
	if (high <= low) return (item > a[low]) ? (low + 1) : low;
	size_t mid = (low + high) / 2;
	if (item == a[mid]) return mid + 1;
	else if (item > a[mid]) return binlocator(mid + 1, high, item);
	else return binlocator(low, mid - 1, item);
}
void binsort()
{
	size_t size = SIZE;
	for (auto i = 1; i < size; i++)
	{
		size_t j = i - 1;
		size_t item = a[i];
		size_t pos = binlocator(0, j, item);
		while (j >= pos)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = item;
	}
}
int main()
{
	process();
	binsort();
	print();

}