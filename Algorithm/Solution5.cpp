//
//  Solution5.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/23.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution5.hpp"
#include <vector>

using std::vector;

static int start;
static int offset;

void extendPalindrome(string &s, int i, int j) {
    while (i >= 0 && j < s.length() && s[i] == s[j]) {
        i--;
        j++;
    }
    if (j - i > offset) {
        start = i + 1;
        offset = j - i - 1;
    }
}

string Solution5::longestPalindrome(string s) {
    size_t length = s.length();
    if (length == 0 || length == 1) {
        return s;
    }
    for (size_t i = 0; i < length - 1; ++i) {
        // assume palindrome is odd
        extendPalindrome(s, i, i);
        // assume even
        extendPalindrome(s, i, i+ 1);
    }
    return s.substr(start, offset);
}
// dp solution
//string Solution5::longestPalindrome(string s) {
//    size_t length = s.length();
//    if (length == 0 || length == 1) {
//        return s;
//    }
//    int start = 0, len = 1;
//    // dp[i][j] means whether s[i, j] is palindrome or not, i <= j
//    vector<vector<bool>> dp(length, vector<bool>(length, false));
//    for (size_t i = 0; i < length; ++i) {
//        dp[i][i] = true;
//        if (i < length - 1) {
//            if (s[i] == s[i+1]) {
//                dp[i][i+1] = true;
//                start = (int)i;
//                len = 2;
//            }
//        }
//    }
//    // i is length
//    for (size_t i = 2; i < length; ++i) {
//        // j is start
//        for (size_t j = 0; j < length - i; ++j) {
//            // k is end
//            int k = (int)(i + j);
//            if (dp[j+1][k-1] && s[j] == s[k]) {
//                dp[j][k] = true;
//                int new_len = (int)(k - j + 1);
//                if (new_len > len) {
//                    start = (int)j;
//                    len = new_len;
//                }
//            }
//        }
//    }
//    return s.substr(start, len);
//}
