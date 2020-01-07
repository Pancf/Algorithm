//
//  Solution11.hpp
//  Algorithm
//
//  Created by Pancf on 2020/1/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution11_hpp
#define Solution11_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution11 {
/**
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

 Note: You may not slant the container and n is at least 2.
 Example:

 Input: [1,8,6,2,5,4,8,3,7]
 Output: 49
 ================================================================================================
 Accept details:
 Runtime: 20 ms, faster than 66.31% of C++ online submissions for Container With Most Water.
 Memory Usage: 9.9 MB, less than 64.95% of C++ online submissions for Container With Most Water.
 思路：矩形面积S = w * h，当w = j - i，h为min(height[i], height[j])。如果我们让 i from 0 to size - 2, j from i+1 to size - 1，时间复杂度为
 O(n^2)，测试集会出现超时的情况。那么如何减少循环次数呢？
 因为 if height[i] > height[j] then S(i, j-1) = (j-1 - i) * min(height[j-1], height[i]) >= S(i+1, j) = (j - i-1) * min(height[i+1], height[j])
 由上面的公式我们得出了缩小底边w时的判断依据，因此一开始可以使底边w = size - 1,然后逐渐递减至1，每次缩减计算得到的面积和之前
 的最大面积比较，取较大值。这样时间复杂度就变成了O(n)
 */
public:
    int maxArea(vector<int>& height);
    static void test() {
        vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};
        Solution11 s = Solution11();
        printf("%d\n", s.maxArea(heights));
    }
};

#endif /* Solution11_hpp */
