//
//  Solution4.hpp
//  Algorithm
//
//  Created by Pancf on 2019/11/24.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution4_hpp
#define Solution4_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution4 {
/**
 难度：Hard
 There are two sorted arrays nums1 and nums2 of size m and n respectively.

 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 You may assume nums1 and nums2 cannot be both empty.

 Example 1:

 nums1 = [1, 3]
 nums2 = [2]

 The median is 2.0
 Example 2:

 nums1 = [1, 2]
 nums2 = [3, 4]

 The median is (2 + 3)/2 = 2.5
 ================================================================================================
 Accept details:
 Runtime: 16 ms, faster than 90.77% of C++ online submissions for Median of Two Sorted Arrays.
 Memory Usage: 10.3 MB, less than 30.93% of C++ online submissions for Median of Two Sorted Arrays.
 思路:求两个数组的中位数，o(log(m+n))复杂度，其实归并排序刚好就是这个复杂度。所以直接归并再取合并后的数组中位数即可。
 但是这样做会多花掉一些空间以及时间，因为归并数组增长到 (m+n)/2 + 1长度时，其实已经没有必要继续了。若m+n是奇数，
 那么中间值其实就是归并数组的第(m+n)/2 + 1个数字；若m+n是偶数，那么中间值就是最后两个数字的平均值。
 从结果来看耗时在我的预期内，但暂时没想明白memory usage为什么这么多。
 */
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    
    static void test() {
        vector<int> nums1 = vector<int>{1, 2};
        vector<int> nums2 = vector<int>{3, 4};
        Solution4 s = Solution4();
        printf("%f", s.findMedianSortedArrays(nums1, nums2));
    }
};

#endif /* Solution4_hpp */
