//
//  dijkstra.hpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/21/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#ifndef dijkstra_hpp
#define dijkstra_hpp

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "HashCombine.hpp"

struct DijkstraResult
{
    std::unordered_map<char, std::vector<char>> shortest_paths;
    std::unordered_map<char, unsigned int> distances;
};

struct WeightedVertex
{
    bool operator==(const WeightedVertex &other) const
    {
        return this->id == other.id;
    }
    
    char id;
    unsigned int weight;
};

namespace std
{
    template <>
    struct hash<WeightedVertex>
    {
        size_t operator()(const WeightedVertex &v) const
        {
            size_t seed = 0;
            HashCombine<char>(seed, v.id);
            HashCombine<unsigned int>(seed, v.weight);
            return seed;
        }
    };
}

typedef std::unordered_map<char, std::unordered_set<WeightedVertex>> Graph;

class Dijkstra
{
public:
    DijkstraResult dijsktra(const Graph &graph, const char start);
private:
    std::shared_ptr<char> FindClosestVertex() const;
    void ExploreVertex(const char c, const Graph &graph);
    std::unordered_map<char, std::vector<char>> CalculatePaths(const Graph &graph) const;
    
    std::unordered_map<char, unsigned int> distance_from_start; // could this be min heap?
    std::unordered_map<char, char> parents;
    std::unordered_set<char> explored;
};


#endif /* dijkstra_hpp */
