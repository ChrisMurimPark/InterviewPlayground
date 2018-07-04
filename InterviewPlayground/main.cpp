//
//  main.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include <iostream>
#include "quicksort.hpp"

int main(int argc, const char * argv[]) {
    std::vector<int> arr =
    {
        86,
        4,
        19,
        32,
        30,
        88,
        21,
        32,
        4,
        67,
        21,
        78,
        93,
        46,
        90,
        56,
        56,
        73,
        36,
        92,
        15,
        28,
        15,
        62,
        9,
        23,
        81,
        4,
        27,
        55,
        20,
        13,
        76,
        20,
        4,
        44,
        22,
        13,
        52,
        90,
        87,
        8,
        20,
        49,
        83,
        65,
        85,
        70,
        10,
        82
    };
    quicksort(arr);
    for (size_t i = 0, n = arr.size(); i < n; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}
