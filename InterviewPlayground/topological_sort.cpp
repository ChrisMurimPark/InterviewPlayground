//
//  topological_sort.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/9/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "topological_sort.hpp"

std::vector<int> TopologicalSort::Sort(const std::unordered_map<int, std::unordered_set<int>> &graph)
{
    std::stack<int> s;
    for (auto itr = graph.begin(), end = graph.end(); itr != end; ++itr)
    {
        int v = itr->first;
        if (m_visited.find(v) == m_visited.end())
            SortHelper(graph, v, &s);
    }
    std::vector<int> sorted;
    while (!s.empty())
    {
        sorted.emplace_back(s.top());
        s.pop();
    }
    return sorted;
}

void TopologicalSort::SortHelper(const std::unordered_map<int, std::unordered_set<int>> &graph, const int v, std::stack<int> *s)
{
    m_visited.emplace(v);
    const std::unordered_set<int> &adj = graph.at(v);
    for (auto itr = adj.begin(), end = adj.end(); itr != end; ++itr)
    {
        int u = *itr;
        if (m_visited.find(u) == m_visited.end())
            SortHelper(graph, u, s);
    }
    s->push(v);
}
