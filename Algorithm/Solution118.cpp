//
//  Solution118.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/13.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution118.hpp"

std::vector<std::vector<int>> Solution118::generate(int numRows)
{
    std::vector<std::vector<int>> res;
    for (int i = 0; i < numRows; ++i) {
        std::vector<int> tmp;
        for (int j = 0; j <= i; ++j) {
            if (j == 0) tmp.push_back(1);
            else if (j == i) tmp.push_back(1);
            else tmp.push_back(res[i-1][j-1] + res[i-1][j]);
        }
        res.push_back(tmp);
    }
    return res;
}
