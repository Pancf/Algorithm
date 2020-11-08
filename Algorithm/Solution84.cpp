//
//  Solution84.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/8.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution84.hpp"
#include <stack>

int Solution84::largestRectangleArea(std::vector<int> &heights)
{
    if (heights.size() == 0) return 0;
    if (heights.size() == 1) return heights.front();
    int size = (int)heights.size(), res = 0;
    std::vector<int> smallerFromLeft(size, 0);
    std::vector<int> smallerFromRight(size, 0);
    smallerFromLeft[0] = -1;
    smallerFromRight[size - 1] = size;
    for (int i = 1; i < size; ++i) {
        int left = i - 1;
        while (left >= 0 && heights[left] >= heights[i]) {
            left = smallerFromLeft[left];
        }
        smallerFromLeft[i] = left;
    }
    for (int i = size - 2; i >= 0; --i) {
        int right = i + 1;
        while (right < size && heights[right] >= heights[i]) {
            right = smallerFromRight[right];
        }
        smallerFromRight[i] = right;
    }
    for (int i = 0; i < size; ++i) {
        res = std::max(res, (smallerFromRight[i] - smallerFromLeft[i] - 1) * heights[i]);
    }
    return res;
    // 设 n = heights.size()
    // 如果heights是单调递增数组，那么从0遍历到n-1或从n-1遍历到0，找出heights[i] * (n - i) 的最大值即可
    // 当遇到heights[k]小于k左侧的bar时，从k向前找小于heights[k]的bar，在寻找过程中更新max，直至找到heights[i] < heights[k]，或者找不到为止
//    std::stack<int> indices;
//    int max = 0, i = 0;
//    heights.push_back(0);
//    while (i < heights.size()) {
//        if (indices.empty() || heights[indices.top()] < heights[i]) {
//            // indices is an monotone increasing stack
//            indices.push(i);
//            i++;
//        } else {
//            int h = heights[indices.top()];
//            indices.pop();
//            int j = indices.empty() ? -1 : indices.top();
//            max = std::max(max, h * (i - j - 1));
//        }
//    }
//    return max;
}
