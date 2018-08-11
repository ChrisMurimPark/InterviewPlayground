//
//  algorithm_library.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 8/11/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "algorithm_library.hpp"
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <random>
#include <iostream>

bool gt_5(const int &i)
{
    return i > 5;
}

bool is_odd(const int &i)
{
    return i % 2 == 1;
}

bool is_even(const int &i)
{
    return i % 2 == 0;
}

struct EvenNumberGenerator
{
    EvenNumberGenerator() : curr(0) {}
    int operator()()
    {
        curr += 2;
        return curr - 2;
    }
    int curr;
} even_num_gen;

void AllOf()
{
    std::vector<int> v {1, 3, 5, 7, 9};
    assert(!std::all_of(v.begin(), v.end(), gt_5));
    assert(std::all_of(v.begin(), v.end(), is_odd));
}

void AnyOf()
{
    std::vector<int> v {1, 3, 5, 7, 9};
    assert(std::any_of(v.begin(), v.end(), gt_5));
    assert(!std::any_of(v.begin(), v.end(), is_even));
}

void NoneOf()
{
    std::vector<int> v {1, 3, 5, 7, 9};
    assert(std::none_of(v.begin(), v.end(), [](const int &i) { return i == 4; }));
    assert(std::none_of(v.begin(), v.end(), is_even));
}

void ForEach()
{
    std::vector<int> v {1, 3, 5, 7, 9};
    std::for_each(v.begin(), v.end(), [](int &i) { i += 5; });
    std::vector<int> expected = {6, 8, 10, 12, 14};
    assert(v == expected);
}

void Count()
{
    std::vector<int> v {6, 8, 10, 12, 14};
    assert(std::count(v.begin(), v.end(), 6) == 1);
    assert(std::count_if(v.begin(), v.end(), [](const int &i) { return i % 6 == 0; }) == 2);
}

void Mismatch()
{
    std::vector<int> v {6, 8, 10, 12, 14};
    std::vector<int> diff_v {6, 8, 10};
    auto diff_pair = std::mismatch(v.begin(), v.end(), diff_v.begin(), diff_v.end());
    assert(*diff_pair.first == 12);
    assert(diff_pair.second == diff_v.end());
}

void Find()
{
    std::vector<int> v {6, 8, 10, 12, 14};
    assert(std::find(v.begin(), v.end(), 6) == v.begin());
    assert(std::find_if(v.begin(), v.end(), [](const int &i) { return i >= 10; }) == v.begin() + 2);
    assert(std::find_if_not(v.begin(), v.end(), [](const int &i) { return i <= 10; }) == v.begin() + 3);
}

void FindEnd()
{
    std::vector<int> v = {6, 8, 10, 12, 8, 10, 12};
    std::vector<int> to_find {8, 10, 12};
    assert(std::find_end(v.begin(), v.end(), to_find.begin(), to_find.end()) == v.begin() + 4);
}

void FindFirstOf()
{
    std::vector<int> v = {6, 8, 10, 12, 8, 10, 12};
    std::vector<int> to_find = {1, 2, 3, 4, 5, 6, 7, 8};
    assert(std::find_first_of(v.begin(), v.end(), to_find.begin(), to_find.end()) == v.begin());
}

void AdjacentFind()
{
    std::vector<int> v = {1, 3, 5, 6, 8, 10};
    assert(std::adjacent_find(v.begin(), v.end(), [](const int &lhs, const int &rhs) { return lhs + 1 == rhs; }) == v.begin() + 2);
}

void Search()
{
    std::vector<int> v = {1, 2, 3, 1, 2, 3};
    std::vector<int> to_find = {1, 2, 3};
    assert(std::search(v.begin(), v.end(), to_find.begin(), to_find.end()) == v.begin());
}

void Copy()
{
    std::vector<int> v = {1, 2, 3, 1, 2, 3};
    std::vector<int> to_fill;
    std::set<int> set_to_fill;
    std::copy(v.begin(), v.end(), std::back_inserter(to_fill));
    std::copy(v.begin(), v.end(), std::inserter(set_to_fill, set_to_fill.begin()));
    assert(v == to_fill);
    std::set<int> expected_set {1, 2, 3};
    assert(expected_set == set_to_fill);
}

void CopyIf()
{
    std::vector<int> v = {1, 2, 3, 1, 2, 3};
    std::vector<int> to_fill;
    std::copy_if(v.begin(), v.end(), std::back_inserter(to_fill), [](const int &i) { return i == 1; });
    std::vector<int> expected = {1, 1};
    assert(to_fill == expected);
}

void CopyBackward()
{
    std::vector<int> v = {3, 2, 1, 0};
    std::vector<int> to_fill = std::vector<int>(4, -1);
    std::copy_backward(v.begin(), v.end(), to_fill.end());
    assert(to_fill[0] == 3 && to_fill[1] == 2 && to_fill[2] == 1 && to_fill[3] == 0);
}

void Move()
{
    std::vector<int> v = {3, 2, 1, 0};
    std::vector<int> to_fill;
    std::move(v.begin(), v.end(), std::back_inserter(to_fill));
    assert(to_fill[0] == 3 && to_fill[1] == 2 && to_fill[2] == 1 && to_fill[3] == 0);
}

void MoveBackward()
{
    std::vector<int> v = {0, 1, 2};
    std::vector<int> to_fill = std::vector<int>(3, -1);
    std::move_backward(v.begin(), v.end(), to_fill.end());
    assert(to_fill[0] == 0 && to_fill[1] == 1 && to_fill[2] == 2);
}

void Fill()
{
    std::vector<int> v(3);
    std::fill(v.begin(), v.end(), 2);
    assert(v[0] == 2 && v[1] == 2 && v[2] == 2);
}

void Transform()
{
    std::vector<int> transformed;
    std::vector<int> v1 {1, 2};
    std::vector<int> v2 {2, 3, 4};
    std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(transformed), [](const int &lhs, const int &rhs) { return lhs * rhs; });
    assert(transformed[0] == 2 && transformed[1] == 6 && transformed.size() == 2);
}

void Generate()
{
    std::vector<int> even_nums(3);
    std::generate(even_nums.begin(), even_nums.end(), even_num_gen);
    assert(even_nums[0] == 0 && even_nums[1] == 2 && even_nums[2] == 4);
}

void Remove()
{
    std::vector<int> even_nums {0, 2, 4};
    even_nums.erase(std::remove(even_nums.begin(), even_nums.end(), 2), even_nums.end());
    assert(even_nums[0] == 0 && even_nums[1] == 4 && even_nums.size() == 2);
}

void RemoveIf()
{
    std::vector<int> even_nums {0, 2, 4};
    even_nums.erase(std::remove_if(even_nums.begin(), even_nums.end(), [](const int &i) { return i % 2 == 0; }), even_nums.end());
    assert(even_nums.size() == 0);
}
    
void RemoveCopyIf()
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v_copy;
    std::remove_copy_if(v.begin(), v.end(), std::back_inserter(v_copy), [](const int &i) { return i % 2 == 0; });
    assert(v_copy.size() == 5 && v_copy[0] == 1 && v_copy[1] == 3 && v_copy[2] == 5 && v_copy[3] == 7 && v_copy[4] == 9);
}

void Replace()
{
    std::vector<int> v {0, 5, 0, 5};
    std::replace(v.begin(), v.end(), 0, 5);
    std::vector<int> expected (4, 5);
    assert(v == expected);
}

void ReplaceIf()
{
    std::vector<int> v {1, 2, 3, 4};
    std::replace_if(v.begin(), v.end(), [](const int &i) { return i > 2; }, -1);
    std::vector<int> expected {1, 2, -1, -1};
    assert(v == expected);
}

void ReplaceCopy()
{
    std::vector<int> v {0, 5, 0, 5};
    std::vector<int> result;
    std::replace_copy(v.begin(), v.end(), std::back_inserter(result), 0, 5);
    std::vector<int> expected (4, 5);
    assert(result == expected);
}

void ReplaceCopyIf()
{
    std::vector<int> v {1, 2, 3, 4};
    std::vector<int> result;
    std::replace_copy_if(v.begin(), v.end(), std::back_inserter(result), [](const int &i) { return i > 2; }, -1);
    std::vector<int> expected {1, 2, -1, -1};
    assert(result == expected);
}

void Swap()
{
    int a = 10;
    int b = 15;
    std::swap(a, b);
    assert(a == 15 && b == 10);
}

void SwapRanges()
{
    std::vector<int> a {1, 2, 3};
    std::vector<int> b {4, 3, 2, 4};
    std::swap_ranges(a.begin(), a.end(), b.begin());
    std::vector<int> a_expected {4, 3, 2};
    std::vector<int> b_expected {1, 2, 3, 4};
    assert(a == a_expected);
    assert(b == b_expected);
}

void IterSwap()
{
    std::vector<int> a {1};
    std::vector<int> b {2};
    std::iter_swap(a.begin(), b.begin());
    assert(a[0] == 2 && b[0] == 1);
}

void Reverse()
{
    std::vector<int> v {9, 8, 7};
    std::reverse(v.begin(), v.end());
    std::vector<int> expected {7, 8, 9};
    assert(v == expected);
}

void ReverseCopy()
{
    std::vector<int> v {9, 8, 7};
    std::vector<int> result;
    std::reverse_copy(v.begin(), v.end(), std::back_inserter(result));
    std::vector<int> expected {7, 8, 9};
    assert(result == expected);
}

void Rotate()
{
    std::vector<int> v {4, 1, 2, 3};
    std::rotate(v.begin(), v.begin() + 1, v.end());
    std::vector<int> expected {1, 2, 3, 4};
    assert(v == expected);
}

void RotateCopy()
{
    std::vector<int> v {4, 1, 2, 3};
    std::vector<int> result;
    std::rotate_copy(v.begin(), v.begin() + 1, v.end(), std::back_inserter(result));
    std::vector<int> expected {1, 2, 3, 4};
    assert(result == expected);
}

void Shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<int> v {1, 2, 3, 4};
    std::shuffle(v.begin(), v.end(), g);
    for (int i : v)
        std::cout << i << std::endl;
}

void Unique()
{
    std::vector<int> v {1, 1, 2, 2, 3, 4, 1, 1, 1};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    std::vector<int> expected {1, 2, 3, 4, 1};
    assert(v == expected);
}

void UniqueCopy()
{
    std::vector<int> v {1, 1, 2, 2, 3, 4, 1, 1, 1};
    std::vector<int> result;
    std::unique_copy(v.begin(), v.end(), std::back_inserter(result));
    std::vector<int> expected {1, 2, 3, 4, 1};
    assert(result == expected);
}
