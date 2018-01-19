// File:        sorting.cpp
// Author:      Geoffrey Tien
//              Duc-Phuong Nguyen
// Date:        2016-02-08
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

// Selection Sort
// (your comments here)
#include <stdlib.h>

template <class T>
int SelectionSort(T arr[], int n)
{
	int count = 0; // counter for barometer operations
	for (int i = 0; i < n - 1; i ++) {
		int smallest = i;
		for (int k = i + 1; k < n; k ++) {
			count ++;
			if (arr[k] < arr[smallest])
				smallest = k;
		}
		
		T temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
		
	}
	return count;
}

// Quicksort
// (your comments here)
template <class T>
int Quicksort(T arr[], int n)
{
  int count = 0;
  QuicksortHelper(arr, 0, n - 1, count);
  return count;
}

template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
	if (low < high) {
		int pivot = QSPartition(arr, low, high, counter);
		QuicksortHelper(arr, low, pivot - 1, counter);
		QuicksortHelper(arr, pivot + 1, high, counter);
	}
}

template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
	int pivotindex = high;
	int left = low, right = high - 1;
	while (left < right) {
		while (arr[left] < arr[pivotindex]) {
			counter ++;
			left ++;
		}
		while (right > low && arr[right] > arr[pivotindex]) {
			counter ++;
			right --;
		}

		if (left < right) {
			T temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			left ++;
			right --;
		}
	}

	if (arr[left] < arr[pivotindex]) left ++; 
		
	T temp = arr[pivotindex];
	arr[pivotindex] = arr[left];
	arr[left] = temp;

	pivotindex = left;
	return pivotindex;
}

// Randomized Quicksort
// (your comments here)
template <class T>
int RQuicksort(T arr[], int n)
{
	int count = 0;
	RQuicksortHelper(arr, 0, n - 1, count);
	return count;
}

template <class T>
void RQuicksortHelper(T arr[], int low, int high, int& counter)
{
	if (low < high) {
		int pivot = RQSPartition(arr, low, high, counter);
		RQuicksortHelper(arr, low, pivot - 1, counter);
		RQuicksortHelper(arr, pivot + 1, high, counter);
	}
}

template <class T>
int RQSPartition(T arr[], int low, int high, int& counter)
{
	int pivotindex = rand() % (high - low + 1) + low; //randomize a number in the range of [low...high]
	T temp = arr[pivotindex];
	arr[pivotindex] = arr[high];
	arr[high] = temp;
	pivotindex = high;

	int left = low, right = high - 1;
	while (left < right) {
		while (arr[left] < arr[pivotindex]) {
			counter ++;
			left ++;
		}
		while (right > low && arr[right] > arr[pivotindex]) {
			counter ++;
			right --;
		}

		if (left < right) {
			T temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			left ++;
			right --;
		}
	}

	if (arr[left] < arr[pivotindex]) left ++;

	temp = arr[pivotindex];
	arr[pivotindex] = arr[left];
	arr[left] = temp;

	pivotindex = left;
	return pivotindex;
}

// Mergesort
// (your comments here)
template <class T>
int Mergesort(T arr[], int n)
{
	int count = 0;
	MergesortHelper(arr, 0, n - 1, n, count);
	return count;
}

template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
	if (low < high) {
		int mid = (high - low) / 2 + low;
		MergesortHelper(arr, low, mid, n, counter);
		MergesortHelper(arr, mid + 1, high, n, counter);
		Merge(arr, low, mid, high, n, counter);
	}
}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
	int length = high - low + 1;
	T* temp = new T[length];
	int first_index = low, second_index = mid + 1;
	for (int i = 0; i < length; i ++) {
		if (first_index > mid) {
			counter ++;
			temp[i] = arr[second_index];
			second_index ++;
			continue;
		}

		if (second_index > high) {
			counter ++;
			temp[i] = arr[first_index];
			first_index ++;
			continue;
		}

		if (arr[first_index] < arr[second_index]) {
			counter ++;
			temp[i] = arr[first_index];
			first_index ++;
		} else {
			counter ++;
			temp[i] = arr[second_index];
			second_index ++;
		}
	}
	
	for (int i = 0; i < length; i ++) arr[i + low] = temp[i];
	delete [] temp;
}

// Shell Sort
// (your comments here)
template <class T>
int ShellSort(T arr[], int n)
{
	int count = 0;
	
	int length = n / 2;
	while (length > 0) {
		for (int i = length; i < n; i ++) {
			T temp = arr[i];
			int k;
			for (k = i; k >= length; k -= length) {
				count ++;
				if (arr[k - length] > temp)
					arr[k] = arr[k - length];
				else break;
			}
			arr[k] = temp;
		}
		length /= 2;
	}
	
	return count;
}