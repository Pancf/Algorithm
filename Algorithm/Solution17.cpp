//
//  Solution17.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/3.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution17.hpp"

//vector<string> Solution17::letterCombinations(string digits) {
//    vector<string> rv;
//    if (digits.empty()) {
//        return rv;
//    }
//    rv.push_back("");
//    const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//    for (auto ch : digits) {
//        if (ch < '2' || ch > '9') {
//            continue;
//        }
//        auto candidate = v[ch - '0'];
//        if (candidate.empty()) {
//            continue;
//        }
//        vector<string> tmp;
//        for (auto candi_ch : candidate) {
//            for (auto rv_ch : rv) {
//                tmp.push_back(rv_ch + candi_ch);
//            }
//        }
//        rv.swap(tmp);
//    }
//    return rv;
//}

void dfs(const vector<string>& candidates, vector<string>& rv, string& local, const string dig, int index) {
    if (dig.size() == index) {
        rv.push_back(local);
    } else {
        auto candidate = candidates[dig[index] - '0'];
        for (auto ch : candidate) {
            local.push_back(ch);
            dfs(candidates, rv, local, dig, index+1);
            local.pop_back();
        }
    }
}

vector<string> Solution17::letterCombinations(string digits) {
    vector<string> rv;
    if (digits.empty()) {
        return rv;
    }
    const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string local;
    dfs(v, rv, local, digits, 0);
    return rv;
}
