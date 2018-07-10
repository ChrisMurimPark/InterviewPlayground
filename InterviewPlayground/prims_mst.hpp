//
//  prims_mst.hpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/10/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#ifndef prims_mst_hpp
#define prims_mst_hpp

#include <utility>
#include <unordered_set>
#include <unordered_map>
#include "Utils/HashCombine.hpp"

struct Edge
{
    int first;
    int second;
};

struct EdgeComparator
{
    bool operator()(const Edge &lhs, const Edge &rhs) const
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

struct EdgeHasher
{
    size_t operator()(const Edge &e) const
    {
        size_t seed = 0;
        HashCombine<int>(seed, e.first);
        HashCombine<int>(seed, e.second);
        return seed;
    }
};

struct AdjNode
{
    int id;
    int dist;
};

struct AdjNodeComparator
{
    bool operator()(const AdjNode &lhs, const AdjNode &rhs) const
    {
        return lhs.id == rhs.id;
    }
};

struct AdjNodeHasher
{
    size_t operator()(const AdjNode &a) const
    {
        return std::hash<int>()(a.id);
    }
};

typedef std::unordered_set<Edge, EdgeHasher, EdgeComparator> EdgeSet;
typedef std::unordered_set<AdjNode, AdjNodeHasher, AdjNodeComparator> AdjNodeSet;
typedef std::unordered_map<int, AdjNodeSet> Graph;

EdgeSet PrimsMST(const Graph &g);

#endif /* prims_mst_hpp */
