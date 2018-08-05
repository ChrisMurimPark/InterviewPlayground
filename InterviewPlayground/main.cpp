//
//  main.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "BitOfBits/CommonOperations.hpp"

int main(int argc, const char * argv[]) {

    assert(GetBit(10, 3));
    assert(!GetBit(10, 2));
    assert(SetBit(10, 2) == 14);
    assert(SetBit(10, 1) == 10);
    assert(ClearBit(10, 3) == 2);
    assert(ClearBit(10, 0) == 10);
    assert(ClearMSBtoI(13, 2) == 1);
    assert(ClearItoZero(13, 2) == 8);
    assert(UpdateBit(13, 1, 1) == 15);
    assert(UpdateBit(13, 1, 0) == 13);
    return 0;
}
