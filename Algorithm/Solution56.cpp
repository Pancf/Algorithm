//
//  Solution56.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/10.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution56.hpp"
#include <algorithm>

vector<vector<int>> Solution56::merge(vector<vector<int> > &intervals) {
    vector<vector<int>> rv;
    if (intervals.empty()) {
        return rv;
    }
    std::sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) {
        return lhs[0] < rhs[0];
    });
    vector<int> tmp = intervals[0];
    for (auto interval : intervals) {
        if (tmp[1] >= interval[0]) {
            tmp[1] = tmp[1] > interval[1] ? tmp[1] : interval[1];
        } else {
            rv.push_back(tmp);
            tmp = interval;
        }
    }
    rv.push_back(tmp);
    return rv;
}
