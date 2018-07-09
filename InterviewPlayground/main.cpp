//
//  main.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include <iostream>
#include "topological_sort.hpp"

int main(int argc, const char * argv[]) {
    TopologicalSort sorter;
    std::unordered_map<int, std::unordered_set<int>> graph;
    graph[1] = std::unordered_set<int>({2, 6});
    graph[2] = std::unordered_set<int>({8});
    graph[3] = std::unordered_set<int>();
    graph[4] = std::unordered_set<int>({3, 5, 9});
    graph[5] = std::unordered_set<int>({9});
    graph[6] = std::unordered_set<int>();
    graph[7] = std::unordered_set<int>({1, 2, 3});
    graph[8] = std::unordered_set<int>();
    graph[9] = std::unordered_set<int>({3});
    graph[10] = std::unordered_set<int>({5});
    std::vector<int> sorted = sorter.Sort(graph);
    for (const int &v : sorted)
    {
        std::cout << v << std::endl;
    }
    return 0;
}
