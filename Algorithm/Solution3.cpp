//
//  Solution3.cpp
//  Algorithm
//
//  Created by Pancf on 2020/1/5.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution3.hpp"
#include <map>

using std::map;

int Solution3::lengthOfLongestSubstring(string s) {
    map<char, int> mp;
    int max_len = 0, start = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (mp.find(s[i]) != mp.end()) {
            start = std::max(start, mp[s[i]]);
        }
        mp[s[i]] = i;
        max_len = std::max(max_len, i - start);
    }
    return max_len;
}
