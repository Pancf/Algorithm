//
//  Solution10.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/10.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution10.hpp"
#include <vector>

using std::vector;

// 递归解法
//bool Solution10::isMatch(string s, string p) {
//    if (p.empty()) {
//        return s.empty();
//    }
//    if (p[1] == '*') {
//        //isMatch(s, p.substr(2)) means x* match empty
//        return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
//    } else {
//        return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
//    }
//}
// DP解法
bool Solution10::isMatch(string s, string p) {
    //dp[i][j] = true if s[0...i-1] match p[0...j-1], 求dp[s.size()][p.size()]
    //if p[j-1] == '*', dp[i][j] = dp[i][j-2] || ((p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j]),前者是x* match empty,后者是x*匹配xx*
    //else dp[i][j] = dp[i-1][j-1] && ((p[j-1] == s[i-1] || p[j-1] == '.')) && i > 0
    int m = (int)s.size(), n = (int)p.size();
    auto dp = vector<vector<bool>>(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                //p[0] == '*' make no sense
                dp[i][j] = (j >= 2) && (dp[i][j-2] || ((i > 0) && (p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j-1]));
            } else {
                dp[i][j] = (i > 0) && dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '.');
            }
        }
    }
    return dp[m][n];
}
