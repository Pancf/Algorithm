//
//  Solution22.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/9.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution22.hpp"

bool isSafe(string& cand, int lindex, int rindex, int n) {
    if (lindex > n || rindex > n || rindex > lindex) {
        return false;
    } else {
        return true;
    }
}

void bt(vector<string>& rv, string& parentheses, int lindex, int rindex, int n) {
    if (!isSafe(parentheses, lindex, rindex, n)) {
        return;
    }
    if (lindex == n && rindex == n) {
        rv.push_back(parentheses);
        return;
    }
    parentheses.push_back('(');
    if (isSafe(parentheses, lindex + 1, rindex, n)) {
        bt(rv, parentheses, lindex + 1, rindex, n);
        parentheses.pop_back();
    } else {
        parentheses.pop_back();
    }
    
    parentheses.push_back(')');
    if (isSafe(parentheses, lindex, rindex + 1, n)) {
        bt(rv, parentheses, lindex, rindex + 1, n);
        parentheses.pop_back();
    } else {
        parentheses.pop_back();
    }
}

vector<string> Solution22::generateParenthesis(int n) {
    vector<string> rv;
    if (n == 0) {
        return rv;
    }
    string cand;
    bt(rv, cand, 0, 0, n);
    return rv;
}
