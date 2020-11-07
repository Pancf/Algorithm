//
//  Solution76.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/7.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution76.hpp"
#include <unordered_map>

std::string Solution76::minWindow(std::string s, std::string t)
{
    std::unordered_map<char, int> ch2count;
    // ch2count represent count of char in t to be traversed
    for (auto c : t) {
        ch2count[c]++;
    }
    // [start...end] represent a window, length represent min window length
    // minStart represent the start index of min window
    // counter represent the number of characters in t to be found in s
    size_t start = 0, end = 0, counter = t.size(), length = INT32_MAX, minStart = 0;
    while (end < s.size()) {
        char c = s[end];
        // find c in t
        if (ch2count[c] > 0) counter--;
        // flag as traversed
        ch2count[c]--;
        end++;
        while (counter == 0) { // find valid window, shift start to find smaller window
            if (end - start < length) {
                minStart = start;
                length = end - start;
            }
            ch2count[s[start]]++;
            if (ch2count[s[start]] > 0) { // when s[start] is the charater in t, increase counter
                counter++;
            }
            start++;
        }
    }
    return length == INT32_MAX ? "" : s.substr(minStart, length);
}
