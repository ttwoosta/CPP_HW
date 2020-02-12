/*
In this assignment you will be implementing the sorting algorithms 
that we have discussed so far to compare how their actual run times 
compare to their time complexities.

1.) In c++, implement a 'List' class that represents a list of numbers 
of a given size and create a function that is able to randomize your 
list of numbers

2.) Implement the following methods to sort your List class:
- insertion sort
- merge sort
- quick sort
- median sort

3.) Run each of these methods and record the run time of each at 
List lengths of 10, 100, 1000, 10000, and 100000. Run each of 
these 10 times and record the average of each run time - write 
these out to a csv file

4.) In excel (or similar tool) graph the average run time for 
each sorting method on the same plot to compare how each performs 
on each List size.

5.) Repeat steps 3-4 when you attempt to sort an already-sorted list 
of numbers and record the findings

6.) Repeat steps 3-4 when you attempt to sort a reverse-sorted list 
of numbers and record the findings

*/

#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>
#include <stdio.h>
using namespace std;

void generate_random_list(vector<int> &list, int n);
void print_list(string desc, vector<int> list);
void print_result_list(string desc, vector<int> result, clock_t t, FILE* csv_file);

void insertionSort(vector<int> &a);
void mergeSort(vector<int> &a, int p, int r);
void merge(vector<int>& a, int p, int q, int r);

void quickSort(vector<int> &a, int p, int r);
int partition(vector<int>& a, int p, int r);

int findMedian(vector<int> a, int left, int right);
void medianSort(vector<int>& a, int left, int right);

int main()
{
    clock_t tStart, tEnd;
    int f = 10;
    vector<int> list_reserve;
    vector<int> list;
    vector<int> result;
    clock_t timeResults[4][10];
    FILE* csv_file = NULL;
    int eleCounts[5] = { 10, 100, 1000, 10000, 100000 };

    //generate_random_list(list, f);
    //std::sort(list.begin(), list.begin() + list.size());
    //std::reverse(list.begin(), list.end());
	list.push_back(9);
	list.push_back(6);
	list.push_back(1);
	list.push_back(3);
	list.push_back(7);
	
    list_reserve = list;

    /*std::sort(list.begin(), list.begin() + list.size());
    std::reverse(list.begin(), list.end());*/
    print_list("Before", list);
    //std::printf("Insertion Sort begin...\n");
    tStart = clock();
    //mergeSort(list, 0, f - 1);
	int median = findMedian(list, 0, list.size());
	medianSort(list, 0, list.size());
    tEnd = clock() - tStart;
    //print_list("After", list);
    printf(" ended. It took: %dms\n", tEnd);
    print_list("After", list);
	cout << "Median value: " << median << endl;
    return 0;

    fopen_s(&csv_file, "C:\\Bob\\sort_bench.csv", "w");
    std::fprintf(csv_file, "Element Count,Round #,Insertion,Quick,Merge,Built-in\n");
    
    for (int z=0; z < 5; z++)
    {
        f = eleCounts[z];

        for (int round = 0; round < 10; round++)
        {
            generate_random_list(list, f);
            std::sort(list.begin(), list.begin() + list.size());
            //std::reverse(list.begin(), list.end());

            list_reserve = list;

            std::printf("Working on array %d elements round %d ...\n", f, round);
            //std::fprintf(csv_file, "%d,%d,", f, round);

            // skip Insertion sort if list contains more than 10,000 elements
            std::printf("Insertion Sort begin...\n");
            tStart = clock();
            insertionSort(list);
            tEnd = clock() - tStart;
            //print_result_list("Insertion Sort", result, tEnd, csv_file);
            timeResults[0][round] = tEnd;

            // make copy of the org list
            list = list_reserve;

            std::printf("Quick Sort begin...\n");
            tStart = clock();
            quickSort(list, 0, f - 1);
            tEnd = clock() - tStart;
            //print_result_list("Quick Sort", result, tEnd, csv_file);
            timeResults[1][round] = tEnd;

            // make copy of the org list
            list = list_reserve;

            std::printf("Merge Sort begin...\n");
            tStart = clock();
            mergeSort(list, 0, f - 1);
            tEnd = clock() - tStart;
            //print_result_list("Merge Sort", result, tEnd, csv_file);
            timeResults[2][round] = tEnd;

            // make copy of the org list
            list = list_reserve;

            std::printf("Built-in Sort begin...\n");
            tStart = clock();
            std::sort(list.begin(), list.begin() + list.size());
            tEnd = clock() - tStart;
            //print_result_list("Built-in Sort", list, tEnd, csv_file);
            timeResults[3][round] = tEnd;

            //std::fprintf(csv_file, "\n");
        }

        
        std::fprintf(csv_file, "Average (%d),_,", f);
        clock_t timeSum = 0;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                timeSum += timeResults[i][j];
            }

            std::fprintf(csv_file, "%4.2f,", timeSum / 10.00);
            timeSum = 0;
        }
        std::fprintf(csv_file, "\n");
    }

    std::fclose(csv_file);
    return 0;
}

void insertionSort(vector<int> &a) {
    for (int j = 1; j < a.size(); j++)
    {
        int key = a[j];
        int i = j - 1;

        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }

        a[i + 1] = key;
    }
}

// merge sort function
void mergeSort(vector<int> &a, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

// function to merge the subarrays
void merge(vector<int> &a, int p, int q, int r)
{
    vector<int> b(a.size());   //same size of a[]
    int i, j, k;
    k = 0;
    i = p;
    j = q + 1;
    while (i <= q && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];    // same as b[k]=a[i]; k++; i++;
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while (i <= q)
    {
        b[k++] = a[i++];
    }

    while (j <= r)
    {
        b[k++] = a[j++];
    }

    for (i = r; i >= p; i--)
    {
        a[i] = b[--k];  // copying back the sorted list to a[]
    }
}

void generate_random_list(vector<int>& list, int n) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, n);
    list.clear();
    for (size_t i = 0; i < n; i++)
        // generates number in the range 1..n 
        list.push_back(distribution(generator));
}

void print_list(string desc, vector<int> list) {
    cout << desc << ": ";
    for (size_t i = 0; i < list.size() - 1; i++)
        cout << list[i] << ",";
    cout << list[list.size() - 1] << endl;
}

void print_result_list(string desc, vector<int> result, clock_t t, FILE* csv_file) {
    print_list(desc, result);
    cout << desc;
    printf(" ended. It took: %dms\n", t);
    std::fprintf(csv_file, "%d,", t);
}

void quickSort(vector<int> &a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

// https://stackoverflow.com/questions/37288359/quick-sort-stack-overflow-c-big-numbers
int partition(vector<int>& a, int p, int r) {
    int x = a[r];
    int temp;

    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] <= x) {
            i += 1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;

    return i + 1;
}

int findMedian(vector<int> a, int left, int right) {
	std::sort(a.begin() + left, a.begin() + right);
	int size = right - left;
	int median;

	if (size % 2 == 0)
		return a[left + (size / 2)];
	else
		return a[left + ((size - 1) / 2)];
}

int findMedianPosition(vector<int> a, int left, int right) {
	vector<int> copied = a;
	std::sort(copied.begin()+ left, copied.begin() + right);
	int size = right - left;
	int median;

	if (size % 2 == 0)
		median = copied[left + (size / 2)];
	else
		median = copied[left + ((size - 1) / 2)];

	for (size_t i = left; i < right; i++)
	{
		if (a[i] == median)
			return i;
	}
}

/*int findMedian(vector<int>& a, int left, int right) {
	int max, min;
	int median;
	int mid = a.size() / 2; // mid position
	int leftCount = 0, rightCount = 0;

	if (a[left] > a[left+1]) {
		max = a[left];
		min = a[left+1];
	}
	else {
		max = a[left+1];
		min = a[left];
	}

	for (size_t i = left; i < right; i++)
	{
		if (max < a[i])
			max = a[i];
		else if (min > a[i])
			min = a[i];
	}

	median = (max + min) / 2.0;
	for (size_t i = left; i < right; i++)
	{
		if (a[i] < median)
			leftCount++;
		else if (a[i] >= median)
			rightCount++;
	}

	int direction = 0;

	if (leftCount == rightCount) {
		direction = 0;
	}
	else if (leftCount > rightCount) {
		direction = (leftCount - rightCount) / 2;
	}
	else {  // right > left
		direction = (rightCount - leftCount) / 2;

		
	}

	return median;
}*/

void medianSort(vector<int>& a, int left, int right) {

	if (left < right) {
		if (right - left == 1) {

			return;
		}

		int mid = (left + right) / 2 ;
		int medianPos = findMedianPosition(a, left, right);
		int temp;

		temp = a[mid];
		a[mid] = a[medianPos];
		a[medianPos] = temp;

		for (size_t i = left; i < mid - 1; i++)
		{
			if (a[i] > a[mid]) {
				for (size_t k = mid; k < right; k++)
				{
					if (a[k] <= a[mid]) {
						temp = a[i];
						a[i] = a[k];
						a[k] = temp;
						
						

					}
				}
			}

			
		}

		medianSort(a, left, mid - 1);
		medianSort(a, mid + 1, right);
	}
}