//
//  main.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include <iostream>
#include "prims_mst.hpp"

int main(int argc, const char * argv[]) {
    Graph g;
    g.emplace(std::make_pair(1, AdjNodeSet({AdjNode({2, 20}), AdjNode({3, 5}), AdjNode({4, 10})})));
    g.emplace(std::make_pair(2, AdjNodeSet({AdjNode({1, 20}), AdjNode({4, 5})})));
    g.emplace(std::make_pair(3, AdjNodeSet({AdjNode({1, 5}), AdjNode({4, 1})})));
    g.emplace(std::make_pair(4, AdjNodeSet({AdjNode({1, 10}), AdjNode({2, 5}), AdjNode({3, 1})})));
    EdgeSet edges = PrimsMST(g);
    for (auto itr = edges.begin(), end = edges.end(); itr != end; ++itr)
        std::cout << itr->first << ", " << itr->second << std::endl;
    return 0;
}
