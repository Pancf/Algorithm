//
//  Solution14.hpp
//  Algorithm
//
//  Created by Pancf on 2020/1/5.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution14_hpp
#define Solution14_hpp

#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution14 {
/**
 Write a function to find the longest common prefix string amongst an array of strings.

 If there is no common prefix, return an empty string "".

 Example 1:

 Input: ["flower","flow","flight"]
 Output: "fl"
 Example 2:

 Input: ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
 Note:

 All given inputs are in lowercase letters a-z.
 ================================================================================================
 Accept details:
 Runtime: 8 ms, faster than 53.33% of C++ online submissions for Longest Common Prefix.
 Memory Usage: 8.9 MB, less than 50.00% of C++ online submissions for Longest Common Prefix.
 */
public:
    string longestCommonPrefix(vector<string>& strs);
    static void test() {
        vector<string> v1{ "flower", "flow", "flight" };
        vector<string> v2{ "dog", "raceer", "car" };
        Solution14 s = Solution14();
        printf("%s ", s.longestCommonPrefix(v1).c_str());
        printf("%s ", s.longestCommonPrefix(v2).c_str());
    }
};
#endif /* Solution14_hpp */
