//
//  Solution10.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/10.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution10_hpp
#define Solution10_hpp

#include <stdio.h>
#include <string>

using std::string;

class Solution10 {
/**
 Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 The matching should cover the entire input string (not partial).

 Note:

 s could be empty and contains only lowercase letters a-z.
 p could be empty and contains only lowercase letters a-z, and characters like . or *.
 Example 1:

 Input:
 s = "aa"
 p = "a"
 Output: false
 Explanation: "a" does not match the entire string "aa".
 Example 2:

 Input:
 s = "aa"
 p = "a*"
 Output: true
 Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 Example 3:

 Input:
 s = "ab"
 p = ".*"
 Output: true
 Explanation: ".*" means "zero or more (*) of any character (.)".
 Example 4:

 Input:
 s = "aab"
 p = "c*a*b"
 Output: true
 Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
 Example 5:

 Input:
 s = "mississippi"
 p = "mis*is*p*."
 Output: false
 ================================================================================================
 Accept details:
 递归解法
 Runtime: 220 ms, faster than 12.22% of C++ online submissions for Regular Expression Matching.
 Memory Usage: 15.2 MB, less than 11.87% of C++ online submissions for Regular Expression Matching.
 DP解法
 Runtime: 4 ms, faster than 92.91% of C++ online submissions for Regular Expression Matching.
 Memory Usage: 8.8 MB, less than 69.49% of C++ online submissions for Regular Expression Matching.
 */
public:
    bool isMatch(string s, string p);
    static void test() {
        Solution10 s = Solution10();
        string s1 = "aa";
        string p1 = "a";
        string s2 = "aa";
        string p2 = "a*";
        string s3 = "ab";
        string p3 = ".*";
        string s4 = "aab";
        string p4 = "c*a*b";
        string s5 = "mississippi";
        string p5 = "mis*is*p*.";
        string s6 = "ab";
        string p6 = ".*c";
        printf("%d\n", s.isMatch(s1, p1));
        printf("%d\n", s.isMatch(s2, p2));
        printf("%d\n", s.isMatch(s3, p3));
        printf("%d\n", s.isMatch(s4, p4));
        printf("%d\n", s.isMatch(s5, p5));
        printf("%d\n", s.isMatch(s6, p6));
    }
};

#endif /* Solution10_hpp */
