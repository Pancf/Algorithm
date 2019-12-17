//
//  Solution29.hpp
//  Algorithm
//
//  Created by Pancf on 2019/11/26.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution29_hpp
#define Solution29_hpp

#include <stdio.h>

class Solution29 {
/**
 Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 
 Return the quotient after dividing dividend by divisor.
 
 The integer division should truncate toward zero.
 
 Example 1:
 
 Input: dividend = 10, divisor = 3
 Output: 3
 Example 2:
 
 Input: dividend = 7, divisor = -3
 Output: -2
 Note:
 
 Both dividend and divisor will be 32-bit signed integers.
 The divisor will never be 0.
 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the  purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
 ================================================================================================
 Accept details:
 Runtime: 8 ms, faster than 22.92% of C++ online submissions for Divide Two Integers.
 Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Divide Two Integers.
 思路：计算机中的乘法例如 0110 * 0011 可以理解为 0110 << 0 + 0110 << 1 = 0110 + 1100 = 10010
 而除法就是逆向，如 0110 / 0011 = ((0110 - 0011 << x) - 0011 << y)... x满足0110 < (0011 << x+1) && 0110 > (0011 << x)，最后把x,y等
 直接相加可得结果
*/
public:
    int divide(int dividend, int divisor);
    static void test() {
        Solution29 s = Solution29();
        printf("%d\n", s.divide(-2147483648, -1109186033));
    }
};

#endif /* Solution29_hpp */
