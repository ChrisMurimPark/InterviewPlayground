//
//  min_heap.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 8/4/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "min_heap.hpp"



MinHeap min_heapify(const std::vector<int> &v)
{
    MinHeap q;
    for (const int &i : v)
        q.push(i);
    return q;
}
