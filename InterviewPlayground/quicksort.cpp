//
//  quicksort.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "quicksort.hpp"
#include <random>
#include <limits>

unsigned long random_number()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, UINT_MAX);
    return dist6(rng);
}

size_t absolute_diff(const size_t lhs, const size_t rhs)
{
    if (lhs > rhs)
        return lhs - rhs;
    else
        return rhs - lhs;
}

void swap(std::vector<int> &arr, const size_t first, const size_t second)
{
    if (first == second)
        return;
    arr[first] = arr[first] ^ arr[second];
    arr[second] = arr[first] ^ arr[second];
    arr[first] = arr[first] ^ arr[second];
}

void quicksort(std::vector<int> &arr, const size_t start, const size_t end)
{
    if (absolute_diff(start, end) <= 1)
        return;
    size_t wall = start;
    size_t pivot_index = random_number() % (end - start) + start;
    
    for (size_t i = start; i < end; ++i)
    {
        if (i == pivot_index)
            continue;
        if (arr[i] < arr[pivot_index])
        {
            swap(arr, wall, i);
            ++wall;
            if (wall == pivot_index)
                ++wall;
        }
    }
    size_t swap_index = wall > pivot_index ? wall - 1 : wall;
    swap(arr, swap_index, pivot_index);
    quicksort(arr, start, swap_index);
    quicksort(arr, swap_index + 1, end);
}

void quicksort(std::vector<int> &arr)
{
    quicksort(arr, 0, arr.size());
}
