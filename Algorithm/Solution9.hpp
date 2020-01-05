//
//  Solution9.hpp
//  Algorithm
//
//  Created by Pancf on 2020/1/5.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution9_hpp
#define Solution9_hpp

#include <stdio.h>

class Solution9 {
/**
 Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

 Example 1:

 Input: 121
 Output: true
 Example 2:

 Input: -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 Example 3:

 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 ================================================================================================
 Accept details:
 Runtime: 16 ms, faster than 52.74% of C++ online submissions for Palindrome Number.
 Memory Usage: 8.1 MB, less than 98.18% of C++ online submissions for Palindrome Number.
 思路：根据题目定义，负数显然都是非回文数，可以提前排除。而回文数恰好和这个数的逆序相等，因此可以复用Solution7将数字逆序，
 判断逆序后的数字是否和原数字相等即可
 */
public:
    bool isPalindrome(int x);
    static void test() {
        Solution9 s = Solution9();
        printf("%d ", s.isPalindrome(121));
        printf("%d ", s.isPalindrome(-121));
        printf("%d ", s.isPalindrome(10));
    }
};
#endif /* Solution9_hpp */
