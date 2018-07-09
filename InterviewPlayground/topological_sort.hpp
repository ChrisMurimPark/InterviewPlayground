//
//  topological_sort.hpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/9/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#ifndef topological_sort_hpp
#define topological_sort_hpp

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

class TopologicalSort
{
public:
    std::vector<int> Sort(const std::unordered_map<int, std::unordered_set<int>> &graph);
private:
    void SortHelper(const std::unordered_map<int, std::unordered_set<int>> &graph, const int v, std::stack<int> *s);
    std::unordered_set<int> m_visited;
};

#endif /* topological_sort_hpp */
