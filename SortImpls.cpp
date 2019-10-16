#include <iostream>
#include <vector>
#include <cmath>
#include "math.h"

using namespace std;


//1) SelectionSort
void SelectionSort(vector<int>& input, int start, int finish)
{
	int min = start;

	for (int i = start; i < finish; i++)
	{
		for (int j = i + 1; j < input.size(); j++)
		{
			if (input.at(min) > input.at(j))
			{
				min = j;
			}

		}
		if (min != i)
			swap(input.at(i), input.at(min));
	}
}
//2) BubbleSort
void BubbleSort(vector<int>& input, int start, int finish)
{
	bool swap = true;
	while (swap == true)
	{
		swap = false;
		for (size_t i = start; i < finish; i++)
		{
			if (input.at(i) > input.at(i + 1))
			{
				int temp = input.at(i);

				input.at(i) = input.at(i + 1);
				input.at(i + 1) = temp;
				swap = true;
			}
		}
	}
}

//3) InsertionSort
void InsertionSort(vector<int>& input, int start, int finish)
{
	int iterator, temp;

	for (int i = start + 1; i < finish + 1; i++)
	{
		iterator = i;
		temp = input.at(i);
		while (iterator > 0 && temp < input.at(iterator - 1))
		{
			input.at(iterator) = input.at(iterator - 1);
			iterator--;
		}
		input.at(iterator) = temp;
	}

}

//4)MergeSort
void merge(vector<int>& input, int first, int mid, int last)
{
	vector<int> temp(input.size());
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (input.at(first1) <= input.at(first2))
		{
			temp.at(index) = input.at(first1);
			first1++;
		}
		else
		{
			temp.at(index) = input.at(first2);
			first2++;
		}
		index++;
	}
	
	while (first1 <= last1)
	{
		temp.at(index) = input.at(first1);
		first1++;
		index++;
	}

	while (first2 <= last2)
	{
		temp.at(index) = input.at(first2);
		first2++;
		index++;
	}

	for (index = first; index <= last; index++)
	{
		input.at(index) = temp.at(index);
	}
}

void MergeSort(vector<int>& input, int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;

		MergeSort(input, first, mid);

		MergeSort(input, mid + 1, last);

		merge(input, first, mid, last);
	}
}


int min(int x, int y)
{
	return (x < y) ? x : y;
}

void iterativeMerge(vector<int>& arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	vector<int> L(n1);
	vector<int> R(n2);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L.at(i) = arr.at(l + i);
	for (j = 0; j < n2; j++)
		R.at(j) = arr.at(m + 1 + j);

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L.at(i) <= R.at(j))
		{
			arr.at(k) = L.at(i);
			i++;
		}
		else
		{
			arr.at(k) = R.at(j);
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr.at(k) = L.at(i);
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr.at(k) = R.at(j);
		j++;
		k++;
	}
}

/* Iterative mergesort function to sort arr[0...n-1] */
void IterativeMergeSort(vector<int>& arr, int start, int finish)
{
	int n = finish - start + 1;
	int curr_size; // For current size of subarrays to be merged 
					// curr_size varies from 1 to n/2 
	int left_start; // For picking starting index of left subarray 
					// to be merged 

	// Merge subarrays in bottom up manner. First merge subarrays of 
	// size 1 to create sorted subarrays of size 2, then merge subarrays 
	// of size 2 to create sorted subarrays of size 4, and so on. 
	for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
	{
		// Pick starting point of different subarrays of current size 
		for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
		{
			// Find ending point of left subarray. mid+1 is starting 
			// point of right 
			int mid = min(left_start + curr_size - 1, n - 1);

			int right_end = min(left_start + 2 * curr_size - 1, n - 1);

			// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end] 
			iterativeMerge(arr, left_start, mid, right_end);
		}
	}
}

//6) QuickSort
int partition(vector<int>& input, int start, int finish)
{
	int pivot = input.at(finish);

	int i = start - 1;

	for (int j = start; j < finish; j++)
	{
		if (input.at(j) <= pivot)
		{
			i++;
			swap(input.at(i), input.at(j));
		}
	}
	swap(input.at(i + 1), input.at(finish));
	return (i + 1);
}

void QuickSort(vector<int>& input, int start, int finish)
{
	int pi;
	if (start < finish)
	{
		pi = partition(input, start, finish);

		QuickSort(input, start, pi - 1);
		QuickSort(input, pi + 1, finish);
	}
}

//7) ShellSort
void ShellSort(vector<int>& input, int start, int finish)
{
	int gap, i, j, temp;
	int size = finish - start + 1;

	for (gap = size / 2; gap > start; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			temp = input.at(i);
			for (j = i; (j >= gap) && (input.at(j - gap) > temp); j -= gap)
			{
				input.at(j) = input.at(j - gap);
			}
			input.at(j) = temp;
		}
	}
}