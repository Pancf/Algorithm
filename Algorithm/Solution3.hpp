//
//  Solution3.hpp
//  Algorithm
//
//  Created by Pancf on 2020/1/5.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution3_hpp
#define Solution3_hpp

#include <stdio.h>
#include <string>

using std::string;

class Solution3 {
/**
 Given a string, find the length of the longest substring without repeating characters.

 Example 1:

 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 Example 2:

 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 Example 3:

 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 ================================================================================================
 Accept details:
 Runtime: 24 ms, faster than 50.12% of C++ online submissions for Longest Substring Without Repeating Characters.
 Memory Usage: 10.8 MB, less than 64.68% of C++ online submissions for Longest Substring Without Repeating Characters.
 思路：使用map保存**字符-索引**的Key-Value对，当遍历到已经出现过的字符时（mp.find(s[i]) != mp.end()），更新当前不重复字符串的
 start为该重复字符上次出现的索引，注意start只向后更新，不会向前。每次遍历都保存Key-Value，更新max_len。
 */
public:
    int lengthOfLongestSubstring(string s);
    static void test() {
        Solution3 s = Solution3();
        printf("%d\n", s.lengthOfLongestSubstring("abcabcbb"));
        printf("%d\n", s.lengthOfLongestSubstring("abba"));
        printf("%d\n", s.lengthOfLongestSubstring("pwwkew"));
    }
};
#endif /* Solution3_hpp */
