//
//  Solution17.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/3.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution17_hpp
#define Solution17_hpp

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution17 {
/**
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 （参照九宫格键盘）
 Example:

 Input: "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:

 Although the above answer is in lexicographical order, your answer could be in any order you want.
 ================================================================================================
 Accept details:
 *BFS*
 Runtime: 4 ms, faster than 60.33% of C++ online submissions for Letter Combinations of a Phone Number.
 Memory Usage: 8.5 MB, less than 88.57% of C++ online submissions for Letter Combinations of a Phone Number.
 *DFS*
 Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
 Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
 思路：这道题有两种方法，一种类似于DFS，一种类似于BFS。
 把输入的数字字符串每个数字当作结点，每个数字有3-4片叶子，以数字2为例
    2
  / | \
 a  b  c
 后续的数字作为前一个数字每片叶子的叶子，以此类推会得到一棵树。两种方法其实就是遍历这颗树的两种方法了。
 */
public:
    vector<string> letterCombinations(string digits);
    static void test() {
        Solution17 s = Solution17();
        string param = "234";
        vector<string> str_vector = s.letterCombinations(param);
        for (auto s : str_vector) {
            std::cout<<s<<std::endl;
        }
    }
};
#endif /* Solution17_hpp */
