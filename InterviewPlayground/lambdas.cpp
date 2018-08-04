//
//  lambdas.cpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 8/4/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#include "lambdas.hpp"

#include <functional>

int ExecuteFunction(std::function<int(const int&, const int&)> func, const int &lhs, const int &rhs)
{
    return func(lhs, rhs);
}

int Add(const int &lhs, const int &rhs)
{
    return ExecuteFunction([](const int &lhs, const int &rhs) { return lhs + rhs; }, lhs, rhs);
}

int Subtract(const int &lhs, const int &rhs)
{
    return ExecuteFunction([](const int &lhs, const int &rhs) { return lhs - rhs; }, lhs, rhs);
}

int IntegerDivide(const int &lhs, const int &rhs)
{
    return ExecuteFunction([](const int &lhs, const int &rhs) { return lhs / rhs; }, lhs, rhs);
}

int Multiply(const int &lhs, const int &rhs)
{
    return ExecuteFunction([](const int &lhs, const int &rhs) { return lhs * rhs; }, lhs, rhs);
}
