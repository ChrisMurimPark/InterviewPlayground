//
//  CommonOperations.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 8/5/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "CommonOperations.hpp"

bool GetBit(int num, int i)
{
    return num & (1 << i);
}

int SetBit(int num, int i)
{
    return num | (1 << i);
}

int ClearBit(int num, int i)
{
    return num & (~(1 << i));
}

int ClearMSBtoI(int num, int i)
{
    return num & ((1 << i) - 1);
}

int ClearItoZero(int num, int i)
{
    return num & (~((1 << (i + 1)) - 1));
}

int UpdateBit(int num, int i, int v)
{
    return (num & (~(1 << i))) | (v << i);
}

