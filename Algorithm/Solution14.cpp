//
//  Solution14.cpp
//  Algorithm
//
//  Created by Pancf on 2020/1/5.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution14.hpp"

string Solution14::longestCommonPrefix(vector<string> &strs) {
    string rv = "";
    if (strs.empty()) return rv;
    rv = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        int len = std::min(rv.size(), strs[i].size());
        if (len == 0) {
            rv = "";
            break;
        }
        int common_len = len;
        for (int j = 0; j < len; ++j) {
            if (rv.at(j) != strs[i].at(j)) {
                common_len = j;
                break;
            }
        }
        rv = rv.substr(0, common_len);
    }
    return rv;
}
