//
//  Solution1202.cpp
//  Algorithm
//
//  Created by Pancf on 2020/8/4.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution1202.hpp"

class UF
{
private:
    vector<int> sz;
    vector<int> cnts;
public:
    UF(int length)
    {
        sz = vector<int>();
        cnts = vector<int>(length, 1);
        for (int i = 0; i < length; ++i) {
            sz.push_back(i);
        }
    }
    bool isConnected(int lhs, int rhs)
    {
        return find(lhs) == find(rhs);
    }
    int find(int i)
    {
        while (sz[i] != i) {
            i = sz[i];
        }
        return i;
    }
    void Union(int lhs, int rhs)
    {
        if (isConnected(lhs, rhs)) {
            return;
        }
        int lhs_parent = find(lhs);
        int rhs_parent = find(rhs);
        if (cnts[lhs_parent] < cnts[rhs_parent]) {
            sz[lhs_parent] = rhs_parent;
            cnts[rhs_parent] += cnts[lhs_parent];
        } else {
            sz[rhs_parent] = lhs_parent;
            cnts[lhs_parent] += cnts[rhs_parent];
        }
    }
};

string Solution1202::smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
{
    if (s.length() == 1) {
        return s;
    }
    // 构造连通图
    UF uf((int)s.length());
    for (auto pair : pairs) {
        uf.Union(pair[0], pair[1]);
    }
    // 将每个连通图的结点构成一个集合
    vector<vector<int>> m(s.length());
    for (int i = 0; i < s.length(); ++i) {
        m[uf.find(i)].push_back(i);
    }
    for (auto &ids : m) {
        string ss = "";
        for (auto id : ids) {
            ss += s[id];
        }
        // 连通区域排序
        sort(begin(ss), end(ss));
        // 排序后放回原位
        for (auto i = 0; i < ids.size(); ++i)
            s[ids[i]] = ss[i];
    }
    return s;
}
