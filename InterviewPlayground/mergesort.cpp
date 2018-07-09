//
//  mergesort.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/4/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "mergesort.hpp"

std::vector<int> merge(const std::vector<int> &lhs, const std::vector<int> &rhs)
{
    // assume lhs and rhs are sorted
    size_t i = 0, j = 0, n = lhs.size(), m = rhs.size();
    std::vector<int> result;
    
    while (i < n && j < m)
    {
        if (lhs[i] < rhs[j])
        {
            result.emplace_back(lhs[i]);
            ++i;
        } else {
            result.emplace_back(rhs[j]);
            ++j;
        }
    }
    if (i != n)
    {
        // place rest of lhs in result
        for (; i < n; ++i)
            result.emplace_back(lhs[i]);
    }
    else if (j != m)
    {
        // place rest of rhs in result
        for (; j < m; ++j)
            result.emplace_back(rhs[j]);
    }
    return result;
}

std::vector<int> mergesort(const std::vector<int> &arr)
{
    const size_t len = arr.size();
    if (len <= 1)
        return arr;
    std::vector<int> lhs(arr.begin(), arr.begin() + len / 2);
    std::vector<int> rhs(arr.begin() + len / 2, arr.end());
    lhs = mergesort(lhs);
    rhs = mergesort(rhs);
    return merge(lhs, rhs);
}
