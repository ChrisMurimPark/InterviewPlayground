//
//  custom_hash.hpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/21/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#ifndef custom_hash_hpp
#define custom_hash_hpp

#include <string>
#include <vector>
#include "Utils/HashCombine.hpp"

struct MyStruct
{
    bool operator==(const MyStruct &other) const
    {
        return this->value == other.value && this->name == other.name && this->numbers == other.numbers;
    }
    
    int value;
    std::string name;
    std::vector<int> numbers;
};

namespace std
{
    template <>
    struct hash<MyStruct>
    {
        size_t operator()(const MyStruct &s) const
        {
            size_t seed = 0;
            HashCombine<int>(seed, s.value);
            HashCombine<std::string>(seed, s.name);
            for (int i : s.numbers)
                HashCombine<int>(seed, i);
            return seed;
        }
    };
}

#endif /* custom_hash_hpp */
