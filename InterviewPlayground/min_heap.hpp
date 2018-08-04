//
//  min_heap.hpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 8/4/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#ifndef min_heap_hpp
#define min_heap_hpp

#include <queue>
#include <vector>

struct MinComparator
{
    bool operator()(const int &lhs, const int &rhs) const
    {
        return rhs < lhs;
    }
};

typedef std::priority_queue<int, std::vector<int>, MinComparator> MinHeap;

MinHeap min_heapify(const std::vector<int> &v);

#endif /* min_heap_hpp */
