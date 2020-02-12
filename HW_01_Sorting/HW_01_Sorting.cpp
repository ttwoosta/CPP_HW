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

void generate_random_list(vector<int>& list, int n);
void print_list(string desc, vector<int> list);
void print_result_list(string desc, vector<int> result, clock_t t, FILE* csv_file);

void insertionSort(vector<int>& a);
void mergeSort(vector<int>& a, int p, int r);
void merge(vector<int>& a, int p, int q, int r);

void quickSort(vector<int>& a, int p, int r);
int partition(vector<int>& a, int p, int r);

void swap(vector<int>& a, int p, int t);
int findMedian(vector<int> a, int left, int right);
int findMedianPosition(vector<int> a, int left, int right);
void medianSort(vector<int>& a, int left, int right);

int main()
{
    clock_t tStart, tEnd;
    int f = 0;
    vector<int> list_reserve;
    vector<int> list;
    vector<int> result;
    clock_t timeResults[4][10];
    FILE* csv_file = NULL;
    const int num_test = 4;
    int eleCounts[num_test] = { 10, 100, 1000, 10000 };

    fopen_s(&csv_file, "C:\\Bob\\sort_bench.csv", "w");
    std::fprintf(csv_file, "Element Count,Round #,Insertion,Quick,Merge,Median\n");

    for (int z = 0; z < num_test; z++)
    {
        f = eleCounts[z];

        for (int round = 0; round < 10; round++)
        {
            generate_random_list(list, f);
            std::sort(list.begin(), list.begin() + list.size());
            std::reverse(list.begin(), list.end());

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

            std::printf("Median Sort begin...\n");
            tStart = clock();
            medianSort(list, 0, f - 1);
            tEnd = clock() - tStart;
            //print_result_list("Built-in Sort", list, tEnd, csv_file);
            timeResults[3][round] = tEnd;

            //std::fprintf(csv_file, "\n");
        }

        std::fprintf(csv_file, "Average (%d),_,", f);
        clock_t timeSum = 0;

        for (int i = 0; i < num_test; i++)
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

void insertionSort(vector<int>& a) {
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
void mergeSort(vector<int>& a, int p, int r)
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
void merge(vector<int>& a, int p, int q, int r)
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

void quickSort(vector<int>& a, int p, int r) {
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
    temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;

    return i + 1;
}

int findMedian(vector<int> a, int left, int right) {
    return a[findMedianPosition(a, left, right)];
}

int findMedianPosition(vector<int> a, int left, int right) {

    int size = right - left;
    int median;
    int leftCount = (size % 2) == 0 ? size / 2 : (size - 1) / 2;
    int count = 0;

    for (size_t i = left; i < right + 1; i++)
    {
        median = a[i];
        count = 0;
        for (size_t j = left + 1; j < right + 1; j++)
        {
            if (a[j] < median)
                count++;
        }

        if (count == leftCount)
            return i;
    }

    return 0;
}

void swap(vector<int>& a, int p, int t) {
    int temp;
    temp = a[p];
    a[p] = a[t];
    a[t] = temp;
}

void medianSort(vector<int>& a, int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;
        int medianPos = findMedianPosition(a, left, right);
        int j = mid;

        swap(a, mid, medianPos);

        for (int i = left; i < mid; i++)
        {
            if (a[i] > a[mid]) {
                for (int k = j + 1; k < a.size(); k++)
                {
                    j = k;
                    if (a[k] <= a[mid]) {
                        break;
                    }
                }
                swap(a, i, j);
            }
        }

        for (j = j + 1; j < right + 1; j++) {
            if (a[j] <= a[mid]) {

                swap(a, mid, mid + 1);

                if (right - left > 1) {
                    swap(a, mid, j);
                }

                mid++;
            }
        }

        medianSort(a, left, mid - 1);
        medianSort(a, mid + 1, right);
    }
}