//
//  Solution6.cpp
//  Algorithm
//
//  Created by Pancf on 2020/1/5.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution6.hpp"

string Solution6::convert(string s, int numRows) {
    if (numRows == 1) return s;
    string rv;
    for (int i = 0; i < numRows; ++i) {
        int step1 = (numRows - i - 1) * 2;
        int step2 = i * 2;
        int pos = i;
        if (pos < s.size()) {
            rv += s[pos];
        }
        while (true) {
            pos += step1;
            if (pos >= s.size()) {
                break;
            }
            if (step1) {
                rv += s[pos];
            }
            pos += step2;
            if (pos >= s.size()) {
                break;
            }
            if (step2) {
                rv += s[pos];
            }
        }
    }
    return rv;
}
