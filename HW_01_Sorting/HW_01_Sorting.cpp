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
using namespace std;

vector<int> generate_random_list(int n) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, n);

    vector<int> list;
    for (size_t i = 0; i < n; i++)
        // generates number in the range 1..n 
        list.push_back(distribution(generator));
    
    return list;
}

void print_list(vector<int> list) {
    cout << "The list: ";
    for (size_t i = 0; i < list.size() - 1; i++)
        cout << list[i] << ",";
    cout << list[list.size() - 1] << endl;
}

int main()
{
    clock_t t;
    int f = 0;

    while (f >= 0)
    {
        cout << "Please enter a value from 1 to inf:  ";
        cin >> f;
        if (f < 0) {
            cout << "Bye, bye";
            return 1;
        }
        
        vector<int> list = generate_random_list(f);

        t = clock();
        printf("Calculating...\n");

        sort(list.begin(), list.begin() + 4);

        print_list(list);

        t = clock() - t;
        printf("It took me %dms clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
    }

    return 0;
}