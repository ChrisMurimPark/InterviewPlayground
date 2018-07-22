//
//  main.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <memory>

#include "dijkstra.hpp"

int main(int argc, const char * argv[]) {
    
    Graph g = {
        {'A', { WeightedVertex {'B', 10}, WeightedVertex {'C', 6} }},
        {'B', { WeightedVertex {'A', 10}, WeightedVertex {'D', 1} }},
        {'C', { WeightedVertex {'A', 6}, WeightedVertex {'D', 6} }},
        {'D', { WeightedVertex {'B', 1}, WeightedVertex {'C', 6}, WeightedVertex {'E',8} }},
        {'E', { WeightedVertex {'D', 8 } }}
    };
    
    Dijkstra d;
    DijkstraResult result = d.dijsktra(g, 'A');
    
    std::cout << "Distances" << std::endl;
    for (auto itr = result.distances.begin(), end = result.distances.end(); itr != end; ++itr)
    {
        std::cout << itr->first << ": " << itr->second << std::endl;
    }
    
    std::cout << "Paths" << std::endl;
    for (auto itr = result.shortest_paths.begin(), end = result.shortest_paths.end(); itr != end; ++itr)
    {
        std::cout << itr->first << ": ";
        for (auto path_itr = itr->second.begin(), path_end = itr->second.end(); path_itr != path_end; ++path_itr)
        {
            std::cout << *path_itr << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
