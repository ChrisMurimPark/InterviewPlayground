//
//  hash_table.hpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/12/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#ifndef hash_table_hpp
#define hash_table_hpp

#include <vector>
#include <utility>

class HashTable
{
public:
    HashTable();
    void Set(int key, int value);
    int Find(int key, bool *found) const;
    bool Contains(int key) const;
    void Delete(int key, bool *deleted);
private:
    std::vector<std::vector<std::pair<int, int>>> map;
    size_t num_elements;
    const static size_t INITIAL_SIZE = 8;
    
    size_t Hash(int key, size_t mod) const;
    double LoadFactor() const;
    
    void IncreaseMapSize();
    void DecreaseMapSize();
    void MoveElementsToNewMap(std::vector<std::vector<std::pair<int, int>>> *new_map, const size_t new_size);
};

#endif /* hash_table_hpp */
