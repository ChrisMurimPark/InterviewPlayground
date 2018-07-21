//
//  hash_table.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/12/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "hash_table.hpp"

HashTable::HashTable()
{
    map.resize(INITIAL_SIZE);
}

void HashTable::Set(int key, int value)
{
    size_t hash_value = Hash(key, map.size());
    std::vector<std::pair<int, int>> &bucket = map[hash_value];
    // check to see if key already exists and set if found
    for (std::pair<int, int> &item : bucket)
    {
        if (item.first == key)
        {
            item.second = value;
            return;
        }
    }
    
    // key is new key
    if (map.size() == num_elements) // load factor == 1
    {
        IncreaseMapSize();
        Set(key, value);
    } else {
        ++num_elements;
        bucket.emplace_back(std::make_pair(key, value));
    }
}

int HashTable::Find(int key, bool *found) const
{
    size_t hash_value = Hash(key, map.size());
    const std::vector<std::pair<int, int>> &bucket = map[hash_value];
    for (const std::pair<int, int> &item : bucket)
    {
        if (item.first == key)
        {
            *found = true;
            return item.second;
        }
    }
    *found = false;
    return -1;
}

bool HashTable::Contains(int key) const
{
    size_t hash_value = Hash(key, map.size());
    const std::vector<std::pair<int, int>> &bucket = map[hash_value];
    for (const std::pair<int, int> &item : bucket)
    {
        if (item.first == key)
            return true;
    }
    return false;
}

void HashTable::Delete(int key, bool *deleted)
{
    size_t hash_value = Hash(key, map.size());
    std::vector<std::pair<int, int>> &bucket = map[hash_value];
    for (auto itr = bucket.begin(), end = bucket.end(); itr != end; ++itr)
    {
        if (itr->first == key)
        {
            bucket.erase(itr);
            --num_elements;
            *deleted = true;
            if (LoadFactor() <= 0.25 && map.size() > INITIAL_SIZE)
                DecreaseMapSize();
            return;
        }
    }
    *deleted = false;
}

size_t HashTable::Hash(int key, size_t mod) const
{
    if (key < 0)
        key = -key;
    std::hash<int> hasher;
    size_t hash_value = hasher(key) % mod;
    return hash_value;
}

double HashTable::LoadFactor() const
{
    return (double) num_elements / (double) map.size();
}

void HashTable::IncreaseMapSize()
{
    size_t new_size = map.size() * 2;
    std::vector<std::vector<std::pair<int, int>>> new_map;
    new_map.resize(new_size);
    MoveElementsToNewMap(&new_map, new_size);
    map = new_map;
}

void HashTable::DecreaseMapSize()
{
    size_t new_size = map.size() / 2;
    std::vector<std::vector<std::pair<int, int>>> new_map;
    new_map.resize(new_size);
    MoveElementsToNewMap(&new_map, new_size);
    map = new_map;
}

void HashTable::MoveElementsToNewMap(std::vector<std::vector<std::pair<int, int>>> *new_map, const size_t new_size)
{
    for (auto bucket_itr = map.begin(), bucket_end = map.end(); bucket_itr != bucket_end; ++bucket_itr)
        for (auto item_itr = bucket_itr->begin(), item_end = bucket_itr->end(); item_itr != item_end; ++item_itr)
            (*new_map)[Hash(item_itr->first, new_size)].emplace_back(*item_itr);
}
