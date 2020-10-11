//
//  Solution1298.hpp
//  Algorithm
//
//  Created by Pancf on 2020/8/9.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution1298_hpp
#define Solution1298_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution1298 {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes);
    static void test()
    {
        vector<int> status{1, 0, 1, 0};
        vector<int> candies{7, 5, 4, 100};
        vector<vector<int>> keys{{}, {}, {1}, {}};
        vector<vector<int>> containedBoxes{{1, 2}, {3}, {}, {}};
        vector<int> initalBoxes{0};
        auto ret = Solution1298().maxCandies(status, candies, keys, containedBoxes, initalBoxes);
        printf("%d\n", ret);
    }
};

#endif /* Solution1298_hpp */
