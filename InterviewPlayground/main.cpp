//
//  main.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include <iostream>
#include "min_heap.hpp"

int main(int argc, const char * argv[]) {
    std::vector<int> v {5, 2, 7, 2, 4, 1, 90};
    MinHeap q = min_heapify(v);
    while (!q.empty())
    {
        std::cout << q.top() << std::endl;
        q.pop();
    }
    return 0;
}
