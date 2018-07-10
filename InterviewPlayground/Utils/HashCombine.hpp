//
//  HashCombine.hpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 7/10/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#ifndef HashCombine_hpp
#define HashCombine_hpp

template <class T>
inline void HashCombine(size_t& seed, const T &v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

#endif /* HashCombine_hpp */
