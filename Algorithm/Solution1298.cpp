//
//  Solution1298.cpp
//  Algorithm
//
//  Created by Pancf on 2020/8/9.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution1298.hpp"
#include <set>
#include <queue>

// 遍历initialBoxes，可打开的盒子加到一个queue中，可见但不可打开的加到一个vector中
// loop:
//  queue.pop，把candies[i]加到总数中，遍历keys[i]，已在vector中且状态为不可打开的加到queue中，然后将盒子状态置为打开。
//  遍历containedBoxes[i]，将状态为打开的盒子加到queue中，否则就加到vector中。
//  goto loop until queue.isEmpty
int Solution1298::maxCandies(vector<int>& status,
                             vector<int>& candies,
                             vector<vector<int>>& keys,
                             vector<vector<int>>& containedBoxes,
                             vector<int>& initialBoxes)
{
    int sumOfCandies = 0;
    std::queue<int> openedBoxes;  // 已打开的盒子
    vector<bool> reachableButClosedBoxes(status.size(), false);  // 能接触到但未打开的盒子
    for (auto &box : initialBoxes) {
        if (status[box]) {
            openedBoxes.push(box);
        } else {
            reachableButClosedBoxes[box] = true;
        }
    }
    while (!openedBoxes.empty()) {
        sumOfCandies += candies[openedBoxes.front()];
        for (auto &box : keys[openedBoxes.front()]) {
            if (reachableButClosedBoxes[box]) {
                openedBoxes.push(box);
                reachableButClosedBoxes[box] = false;
            }
            status[box] = 1;
        }
        for (auto &box : containedBoxes[openedBoxes.front()]) {
            if (status[box]) {
                openedBoxes.push(box);
            } else {
                reachableButClosedBoxes[box] = true;
            }
        }
        openedBoxes.pop();
    }
    return sumOfCandies;
}
