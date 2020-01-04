//
//  Solution7.hpp
//  Algorithm
//
//  Created by Pancf on 2020/1/4.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution7_hpp
#define Solution7_hpp

#include <stdio.h>

class Solution7 {
/**
 Given a 32-bit signed integer, reverse digits of an integer.

 Example 1:

 Input: 123
 Output: 321
 Example 2:

 Input: -123
 Output: -321
 Example 3:

 Input: 120
 Output: 21
 Note:
 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 ================================================================================================
 Accept details:
 Runtime: 4 ms, faster than 69.04% of C++ online submissions for Reverse Integer.
 Memory Usage: 8.2 MB, less than 89.52% of C++ online submissions for Reverse Integer.
 */
public:
    int reverse(int x);
    static void test() {
        int x1 = 1534236469;
        int x2 = -987654;
        int x3 = 1230;
        Solution7 s = Solution7();
        printf("%d\n", s.reverse(x1));
        printf("%d\n", s.reverse(x2));
        printf("%d\n", s.reverse(x3));
    }
};

#endif /* Solution7_hpp */
