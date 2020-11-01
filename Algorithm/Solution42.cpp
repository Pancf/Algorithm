//
//  Solution42.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution42.hpp"

int Solution42::trap(std::vector<int> &height)
{
    if (height.size() < 3) return 0;
    // 从两边向中间遍历，选择从较低一侧倒水，每次倒的水width为1，height为（当前最高水位-当前bar的高度）
    // 当前水位和当前bar高度相等时，倒的水为0，所以无需特殊处理
    // 因为每次迭代总是固定bar更高的一侧，所以从较低一侧倒水是必然可行的
    int waterSum = 0, waterLevel = 0, left = 0, right = (int)height.size() - 1;
    while (left < right) {
        int lower = height[left] < height[right] ? height[left++] : height[right--];
        waterLevel = std::max(waterLevel, lower);
        waterSum += waterLevel - lower;
    }
    return waterSum;
}
