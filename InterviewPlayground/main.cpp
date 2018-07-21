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
#include "custom_hash.hpp"

int main(int argc, const char * argv[]) {
    std::unordered_map<MyStruct, int> struct_map;
    
    MyStruct s1 = {1, "s1", {1, 2, 3}};
    MyStruct s2 = {2, "s2", {3, 2, 1}};
    
    struct_map[s1] = 1;
    struct_map[s2] = 2;
    
    assert(struct_map[s1] == 1);
    assert(struct_map[s2] == 2);
    
    return 0;
}
