//
//  Solution22.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/9.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution22_hpp
#define Solution22_hpp

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution22 {
/**
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 ================================================================================================
 Accept details:
 Runtime: 4 ms, faster than 88.73% of C++ online submissions for Generate Parentheses.
 Memory Usage: 13.8 MB, less than 87.60% of C++ online submissions for Generate Parentheses.
 思路：这是一道非常典型的backtracking题，backtracking可以想象为从树的根节点出发，每个节点的下一步会有几种可能性就有几个分支，比如这道题里
 现有的字符串下一步可以插入'('或')'，那么每个节点就有两个分支，选择其中一个分支往下走一步，判断是否还是符合限制，如果符合则往下走，如果不符合
 则回退，并且把这个分支剪枝。backtracking类型的题目可以归结为以下思路
 procedure bt(c)
    if reject(P,c) then return       #不满足限制条件则剪枝，然后return
    if accept(P,c) then output(P,c)  #满足全部条件，根据需要输出或者保存结果，然后return
    s ← first(P,c)                   #获取当前节点的第一个分支，比如这道题里的push '('
    while s ≠ NULL do                #判断往下走了一步以后是否满足条件，满足的话递归调用，不满足的话则会return。选择分支是用if-else还是循环视情况而定
        bt(s)
        s ← next(P,s)                #获取下一个分支
*/
public:
    vector<string> generateParenthesis(int n);
    static void test() {
        Solution22 s = Solution22();
        auto rv = s.generateParenthesis(3);
        for (auto str : rv) {
            std::cout<<str<<std::endl;
        }
    }
};
#endif /* Solution22_hpp */
