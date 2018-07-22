//
//  dijkstra.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/21/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "dijkstra.hpp"

#include <iostream>
#include <limits.h>
#include <algorithm>

DijkstraResult Dijkstra::dijsktra(const Graph &graph, const char start)
{
    const size_t V = graph.size();
    distance_from_start.clear();
    parents.clear();
    explored.clear();
    
    distance_from_start[start] = 0;
    
    while (explored.size() < V)
    {
        std::shared_ptr<char> c = FindClosestVertex();
        if (!c)
        {
            std::cout << "No closest vertex found." << std::endl;
            return DijkstraResult();
        }
        ExploreVertex(*c, graph);
    }
    
    return DijkstraResult {CalculatePaths(graph), distance_from_start};
}

std::shared_ptr<char> Dijkstra::FindClosestVertex() const
{
    std::shared_ptr<char> result;
    unsigned int min_dist = UINT_MAX;
    for (auto itr = distance_from_start.begin(), end = distance_from_start.end(); itr != end; ++itr)
    {
        if (explored.find(itr->first) != explored.end())
            continue;
        if (itr->second < min_dist)
        {
            result = std::make_shared<char>(itr->first);
            min_dist = itr->second;
        }
    }
    return result;
}

void Dijkstra::ExploreVertex(const char c, const Graph &graph)
{
    const std::unordered_set<WeightedVertex> &adjacent_nodes = graph.at(c);
    const unsigned int distance_up_to_c = distance_from_start[c];
    for (auto itr = adjacent_nodes.begin(), end = adjacent_nodes.end(); itr != end; ++itr)
    {
        const char id = itr->id;
        const unsigned int total_distance = itr->weight + distance_up_to_c;
        const bool first_time = distance_from_start.find(id) == distance_from_start.end();
        if (first_time || total_distance < distance_from_start[id])
        {
            distance_from_start[id] = total_distance;
            parents[id] = c;
        }
    }
    explored.emplace(c);
}

std::unordered_map<char, std::vector<char>> Dijkstra::CalculatePaths(const Graph &graph) const
{
    std::unordered_map<char, std::vector<char>> shortest_paths;
    for (auto itr = graph.begin(), end = graph.end(); itr != end; ++itr)
    {
        char current_node = itr->first;
        std::vector<char> shortest_path;
        while (parents.find(current_node) != parents.end())
        {
            shortest_path.emplace_back(current_node);
            current_node = parents.at(current_node);
        }
        std::reverse(shortest_path.begin(), shortest_path.end());
        shortest_paths[itr->first] = shortest_path;
    }
    return shortest_paths;
}
