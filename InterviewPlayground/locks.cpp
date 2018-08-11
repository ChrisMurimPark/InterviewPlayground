//
//  locks.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 8/8/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "locks.hpp"
#include <mutex>
#include <thread>
#include <list>
#include <iostream>

std::list<int> my_list;
std::mutex list_mutex;

void AddItemToList(int i)
{
    std::lock_guard<std::mutex> lg(list_mutex);
    my_list.push_back(i);
}

size_t GetSizeOfList()
{
    std::lock_guard<std::mutex> lg(list_mutex);
    return my_list.size();
}

void ExecuteThreadsWithLock()
{
    std::thread t1(AddItemToList, 1);
    std::thread t2(AddItemToList, 2);
    std::thread t3(AddItemToList, 3);
    
    t1.join();
    t2.join();
    t3.join();

    std::cout << GetSizeOfList() << std::endl;
    for (int i : my_list)
        std::cout << i << std::endl;
}
