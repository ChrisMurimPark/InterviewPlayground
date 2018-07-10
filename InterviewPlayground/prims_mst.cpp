//
//  prims_mst.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/10/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "prims_mst.hpp"

#include <limits.h>

void UpdateDistances(const Graph &g, const int point, std::unordered_map<int, int> *distances, std::unordered_map<int, int> *parents)
{
    for (auto itr = g.at(point).begin(), end = g.at(point).end(); itr != end; ++itr)
    {
        const AdjNode &adj_node = *itr;
        if ((*distances)[adj_node.id] > adj_node.dist)
        {
            (*distances)[adj_node.id] = adj_node.dist;
            (*parents)[adj_node.id] = point;
        }
    }
}

EdgeSet PrimsMST(const Graph &g)
{
    std::unordered_set<int> mst;
    // initialize min distances
    std::unordered_map<int, int> distances;
    std::unordered_map<int, int> parents;
    for (auto itr = g.begin(), end = g.end(); itr != end; ++itr)
        distances[itr->first] = INT_MAX;
    
    // pick an arbitrary starting point
    int first_point = g.begin()->first;
    distances[first_point] = 0;
    mst.emplace(first_point);
    UpdateDistances(g, first_point, &distances, &parents);
    
    std::unordered_set<Edge, EdgeHasher, EdgeComparator> edges;
    while (mst.size() != g.size())
    {
        // find smallest distance
        int smallest_id = INT_MAX;
        int smallest_dist = INT_MAX;
        for (auto itr = g.begin(), end = g.end(); itr != end; ++itr)
        {
            if (mst.find(itr->first) != mst.end())
                continue;
            if (distances[itr->first] < smallest_dist)
            {
                smallest_id = itr->first;
                smallest_dist = distances[itr->first];
            }
        }
        edges.emplace(Edge({parents[smallest_id], smallest_id}));
        mst.emplace(smallest_id);
        UpdateDistances(g, smallest_id, &distances, &parents);
    }

    return edges;
}
