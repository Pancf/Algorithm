//
//  Solution55.cpp
//  Algorithm
//
//  Created by Pancf on 2020/8/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution55.hpp"

bool Solution55::canJump(vector<int> &nums)
{
    int i = 0;
    // furthest表示到 i 为止，前面的点所能跳到的最远位置。跳出循环的条件为数组遍历完毕或者 i 超过了furthest
    for (int furthest = 0; i < nums.size() && i <= furthest; ++i) {
        furthest = std::max(i + nums[i], furthest);
    }
    return (i == nums.size());
}
/** Method 2
bool Solution55::canJump(vector<int> &nums)
{
    // last记录了能跳到终点的索引值，逆向遍历一遍，只要last最终小于等于0即可
    int last = nums.size(), i;
    for (i = nums.size() - 2;i >= 0; i--) {
        if(i + nums[i] >= last) {
            last=i;
        }
    }
    return last <= 0;
}
*/
