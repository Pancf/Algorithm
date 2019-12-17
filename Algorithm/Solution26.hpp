//
//  Solution26.hpp
//  Algorithm
//
//  Created by Pancf on 2019/11/24.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution26_hpp
#define Solution26_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution26 {
/**
 难度：Easy
 Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

 Example 1:

 Given nums = [1,1,2],

 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

 It doesn't matter what you leave beyond the returned length.
 Example 2:

 Given nums = [0,0,1,1,1,2,2,3,3,4],

 Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

 It doesn't matter what values are set beyond the returned length.
 Clarification:

 Confused why the returned value is an integer but your answer is an array?

 Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

 Internally you can think of this:

 // nums is passed in by reference. (i.e., without making a copy)
 int len = removeDuplicates(nums);

 // any modification to nums in your function would be known by the caller.
 // using the length returned by your function, it prints the first len elements.
 for (int i = 0; i < len; i++) {
     print(nums[i]);
 }
 ================================================================================================
 Accept details:
 Runtime: 20 ms, faster than 93.75% of C++ online submissions for Remove Duplicates from Sorted Array.
 Memory Usage: 10 MB, less than 82.50% of C++ online submissions for Remove Duplicates from Sorted Array.
 思路：注意题目，要求空间复杂度O(1)，因此就别想着开新集合了，也别想用set。仔细观察题目，不要被“去重”迷惑，真正要返回的是数组中不同数字的个数，
 设个数为x，要求参数nums[0...x](不包含x）仍保持升序，而x及以后的部分并不关注。
 在我的第一次做法中，设i从0开始，j从1开始遍历，遇到nums[i] != nums[j]时，把[i+1,j)区间都设为nums[j],即新的数字，然后i自增。但这样的做法
 耗时286ms，基本输给了大多数提交。所以我开始反思为什么会这么慢。去洗衣机取个衣服的空档我意识到，其实[i+1,j)区间没有必要全设为nums[j],因为做
 比较的是nums[i]和nums[j]，只需要把nums[i+1]修改为nums[j]即可，[i+2, j)区间的内容修改毫无意义（假定i+2<j不影响结果)，所以第一种做法中的
 for(size_t k = i+1; k < j; ++k) { nums[k] = nums[j]; } 直接变成 nums[++i] = nums[j]，对某些case来说会省掉很多inner for循环，
 最终耗时变为20ms。
*/
public:
    int removeDuplicates(vector<int>& nums);
    static void test() {
        Solution26 s = Solution26();
        vector<int> v = {0,0,1,1,1,2,2,3,3,4};
        int rv = s.removeDuplicates(v);
        printf("%d\n", rv);
    }
};

#endif /* Solution26_hpp */
