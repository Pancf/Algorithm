//
//  Solution5.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/23.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution5_hpp
#define Solution5_hpp

#include <stdio.h>
#include <string>

using std::string;

class Solution5 {
/**
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

 Example 1:

 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:

 Input: "cbbd"
 Output: "bb"
 ================================================================================================
 Accept details:
 Runtime: 12 ms, faster than 87.50% of C++ online submissions for Longest Palindromic Substring.
 Memory Usage: 8.6 MB, less than 98.62% of C++ online submissions for Longest Palindromic Substring.
 思路：这道题我一开始的思路是用动态规划做，dp[i][j]（i <= j）表示字符串s[i,j]是否是回文字符串，显然单个字符都是回文字符串。
 初始化的时候把dp矩阵的对角线都初始化为true，顺便把dp[i][i+1] （i < s.length - 1）也判断一下初始化。然后自底向上的思路是
 外循环为子字符串间隔 i = 2 --> s.length（结束下标 - 起始下标），内循环为子字符串的起始下标 j = 0 --> s.length - i，然后根据 i 和 j
 算出子字符串的末尾下标k，在 dp[j][k] = dp[j-1][k+1] && s[j]==s[k] 为真的情况下，记录子字符串的起始下标和长度。
 这个解法的问题在于无论输入参数好与坏，时间复杂度都是 O(n^2)。dp解法运行时间大概在200ms。
 后来我想到了从逻辑上更容易理解的解法，回文子字符串的长度分为两种情况，要么是奇数要么是偶数。那么可以使用一个循环 i = 0--> s.length - 2，
 如果回文子字符串长度为奇数，那么把 s[i] 当作子字符串的中点同时向两边扩展，如果长度为偶数，那么把 s[i, i+1]作为初始同时向两边扩展，在没有
 越界的前提下只要每次向前后扩展的字符都相等，就可以继续扩展。
 这种解法在最坏的输入情况下（比如"aaaaa"），时间复杂度和dp解法的时间复杂度类似，但除去这种比较特殊的输入，这种解法的时间复杂度会
 小于dp解法，因为扩展的时候它可以及时剪枝。
 */
public:
    string longestPalindrome(string s);
    static void test() {
        Solution5 s = Solution5();
        printf("%s\n", s.longestPalindrome("abcba").c_str());
    }
};

#endif /* Solution5_hpp */
