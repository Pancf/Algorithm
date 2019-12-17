//
//  Solution56.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/10.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution56_hpp
#define Solution56_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution56 {
/**
 Given a collection of intervals, merge all overlapping intervals.

 Example 1:

 Input: [[1,3],[2,6],[8,10],[15,18]]
 Output: [[1,6],[8,10],[15,18]]
 Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 Example 2:

 Input: [[1,4],[4,5]]
 Output: [[1,5]]
 Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 ================================================================================================
 Accept details:
 Runtime: 20 ms, faster than 73.74% of C++ online submissions for Merge Intervals.
 Memory Usage: 13 MB, less than 36.05% of C++ online submissions for Merge Intervals.
 思路：感觉没啥好说的，按interval的左边界升序排列，然后遍历一遍就行了。当然要注意合并区间的时候不见得前一个区间的右边界就一定大于后一个区间的右边界
*/
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals);
    static void test() {
        Solution56 s = Solution56();
        vector<vector<int>> param = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};
        auto rv = s.merge(param);
        for (auto v : rv) {
            printf("[%d, %d]\n", v[0], v[1]);
        }
    }
};

#endif /* Solution56_hpp */
