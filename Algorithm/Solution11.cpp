//
//  Solution11.cpp
//  Algorithm
//
//  Created by Pancf on 2020/1/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution11.hpp"

int Solution11::maxArea(vector<int> &height) {
    int max_size = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int tmp = 0;
        if (height[j] > height[i]) {
            tmp = (j - i) * height[i];
            i++;
        } else {
            tmp = (j - i) * height[j];
            j--;
        }
        max_size = std::max(max_size, tmp);
    }
    return max_size;
}
