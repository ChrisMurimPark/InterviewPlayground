//
//  main.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "hash_table.hpp"

int main(int argc, const char * argv[]) {
    HashTable table;
    bool found;
    assert(table.Contains(1) == false);
    
    table.Set(1, 2);
    assert(table.Find(1, &found) == 2);
    assert(found == true);
    
    table.Set(2, 3);
    assert(table.Contains(2) == true);
    assert(table.Find(2, &found) == 3);
    assert(found == true);
    
    table.Set(2, 100);
    assert(table.Contains(2) == true);
    assert(table.Find(2, &found) == 100);
    assert(found == true);
    
    assert(table.Find(3, &found) == -1);
    assert(found == false);
    
    table.Set(10, 10);
    table.Set(50, 50);
    table.Set(13, 13);
    table.Set(6, 6);
    table.Set(7, 7);
    table.Set(8, 8);
    table.Set(15, 15);
    
    bool deleted;
    table.Delete(10, &deleted);
    table.Delete(50, &deleted);
    table.Delete(13, &deleted);
    table.Delete(6, &deleted);
    table.Delete(7, &deleted);
    table.Delete(8, &deleted);
    
    assert(table.Contains(10) == false);
    assert(table.Contains(50) == false);
    
    return 0;
}
