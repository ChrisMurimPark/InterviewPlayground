//
//  CommonOperations.hpp
//  InterviewPlayground
//
//  Created by Chris (Murim) Park on 8/5/18.
//  Copyright © 2018 Chris (Murim) Park. All rights reserved.
//

#ifndef CommonOperations_hpp
#define CommonOperations_hpp

bool GetBit(int num, int i); // returns value of the ith LSB

int SetBit(int num, int i); // sets ith LSB to 1

int ClearBit(int num, int i); // sets ith LSB to 0

int ClearMSBtoI(int num, int i); // sets bits MSB to ith LSB (inclusive) to 0

int ClearItoZero(int num, int i); // sets i LSB to 0

int UpdateBit(int num, int i, int v); // sets ith LSB to v

#endif /* CommonOperations_hpp */
