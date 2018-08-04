//
//  main.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/3/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "lambdas.hpp"

int main(int argc, const char * argv[]) {
    int a = 5;
    int b = 2;
    
    assert(Add(a, b) == 7);
    assert(Subtract(a, b) == 3);
    assert(IntegerDivide(a, b) == 2);
    assert(Multiply(a, b) == 10);
    
    return 0;
}
