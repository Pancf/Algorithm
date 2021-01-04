//
//  Solution45.cpp
//  Algorithm
//
//  Created by Pancf on 2021/1/3.
//  

#include "Solution45.hpp"

int Solution45::jump(std::vector<int>& nums)
{
    int size = (int)nums.size();
    if (size == 1) return 0;
    std::vector<int> steps(size, 0); //steps[i]表示到达i所需要的最少步数
    int maxReachableIdx = 0;
    for (int i = 0; i <= maxReachableIdx && i < size; ++i) {
        // 从当前位置i能到达更远位置或者能到达终点时，就要尝试更新steps
        if (maxReachableIdx < nums[i] + i || nums[i] + i >= size - 1) {
            maxReachableIdx = nums[i] + i;
            for (int j = i + 1; j <= maxReachableIdx && j < size; ++j) {
                if (steps[j] == 0) {
                    steps[j] = steps[i] + 1;
                } else {
                    steps[j] = std::min(steps[i] + 1, steps[j]);
                }
            }
        }
    }
    return steps[size - 1];
//    if (size == 1) return 0;
//    int largestLadderLen = nums[0]; // ‘梯子’最远能到达的坐标
//    int stepsLeftOnLadder = nums[0]; // 当前‘梯子’还剩几步可以使用
//    int steps = 1;
//    for (int i = 1; i < size; ++i) {
//        stepsLeftOnLadder--; // 每走一步，当前‘梯子’可用步数减一
//        int newLadder = i + nums[i];
//        largestLadderLen = std::max(largestLadderLen, newLadder); // 更新‘梯子’最远能到达的坐标
//        if (stepsLeftOnLadder == 0) { // 把当前‘梯子’可用步数耗尽后才使用新的‘梯子’，此时新‘梯子’可能已经‘走了’几步了
//            steps++;
//            stepsLeftOnLadder = largestLadderLen - i;
//        }
//    }
//    return steps;
}
