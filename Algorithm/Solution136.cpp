//
//  Solution136.cpp
//  Algorithm
//
//  Created by Pancf on 2021/1/3.
//  

#include "Solution136.hpp"

/**
 * http://zh.wikipedia.org/wiki/%E9%80%BB%E8%BE%91%E5%BC%82%E6%88%96
 * 利用了xor的性质
 */
 
int Solution136::singleNumber(std::vector<int> &nums)
{
    int res = 0;
    for (auto num : nums) {
        res ^= num;
    }
    return res;
}
