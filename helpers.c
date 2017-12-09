/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

bool binsearch(int value, int values[], int start, int end);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n <= 0)
    {
        return false;
    }

    if (binsearch(value, values, 0, n))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool binsearch(int value, int values[], int start, int end)
{
    if (start > end)
    {
        return false;
    }

    int mid = 0;
    if (start == end)
        mid = start;
    else
        mid = (start + (end - 1)) / 2;

    if (value == values[mid])
    {
        return true;
    }
    else if (value > values[mid])
        return binsearch(value, values, mid + 1, end);
    else
        return binsearch(value, values, start, mid - 1);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    // TODO: implement a sorting algorithm

    int counting_array[65537] = {0};

    for (long i = 0; i < n; i++)
        counting_array[values[i]] += 1;

    int count = 0;

    // iterates through counting array
    for (long j = 0; j < 65537; j++)
    {
        // transfer jth element to values[] by k times
        if (counting_array[j] > 0)
        {
            for (int k = 0; k < counting_array[j]; k++)
            {
                values[count] = j;
                count += 1;
            }
        }
    }
}
