//
//  threads.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 8/6/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "threads.hpp"
#include <thread>
#include <iostream>
#include <chrono>

class thread_guard
{
public:
    thread_guard(std::thread &t) : m_t(t) {}
    ~thread_guard()
    {
        if (m_t.joinable())
            m_t.join();
    }
private:
    std::thread &m_t;
};

struct PrintInt
{
    void operator()(const int &i) const
    {
        std::cout << i << std::endl;
    }
};


void ExecuteThreads()
{
    std::thread t1([]{
        std::cout << "Thread calling lambda function." << std::endl;
    });
    int x = 10;
    std::thread t2(PrintInt(), std::ref(x));
    
    std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
    std::cout << "Thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "Thread 2 id: " << t2.get_id() << std::endl;
    
    t1.join();
    t2.join();
    
    std::cout << "Thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "Thread 2 id: " << t2.get_id() << std::endl;
    std::cout << "Max threads: " << std::thread::hardware_concurrency() << std::endl;
}
