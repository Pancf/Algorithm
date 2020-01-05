//
//  Solution6.hpp
//  Algorithm
//
//  Created by Pancf on 2020/1/5.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution6_hpp
#define Solution6_hpp

#include <stdio.h>
#include <string>

using std::string;

class Solution6 {
/**
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P    A     H    N
 A P L S  I   I G
 Y    I      R
 And then read line by line: "PAHNAPLSIIGYIR"

 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string s, int numRows);
 Example 1:

 Input: s = "PAYPALISHIRING", numRows = 3
 Output: "PAHNAPLSIIGYIR"
 Example 2:

 Input: s = "PAYPALISHIRING", numRows = 4
 Output: "PINALSIGYAHRPI"
 Explanation:

 P       I       N
 A   L S    I G
 Y A   H R
 P       I
 ================================================================================================
 Accept details:
 Runtime: 12 ms, faster than 77.05% of C++ online submissions for ZigZag Conversion.
 Memory Usage: 10.4 MB, less than 72.22% of C++ online submissions for ZigZag Conversion.
 思路:这道题主要在于观察Z字型字符串的结构特点
 n = numRows
 0        1                         2n-1
 1        2                2n-2   2n                       step1 = (2n-2) - 2      step2 = 2n - (2n-2)
 .         .                .           .
 .         .           .                .
 .       n-1    n+1             3n-3                     step1 = (n+1) - (n-1)  step2 = (3n-3) - (n+1)
 n-1    n                         3n-2                    (numRows - i - 1) * 2           i * 2       **i** represents row index
 */
public:
    string convert(string s, int numRows);
    static void test() {
        string str = "PAYPALISHIRING";
        Solution6 s = Solution6();
        printf("%s\n", s.convert(str, 3).c_str());
        printf("%s\n", s.convert(str, 4).c_str());
    }
};
#endif /* Solution6_hpp */
