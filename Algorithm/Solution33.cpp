//
//  Solution33.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/14.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution33.hpp"

int Solution33::search(std::vector<int> &nums, int target)
{
//    int lo = 0, hi = (int)nums.size() - 1;
//    while (lo <= hi) {
//        int mid = (lo + hi) / 2;
//        // 此处必须是mid > hi，不能mid > lo，因为翻转前整个数组就是单调递增的，
//        // mid > lo会把pivot = 0的情况也包括进去
//        if (nums[mid] > nums[hi]) {
//            // [lo, mid]为单调递增区间，[mid, hi]*一定*不是单调递增区间
//            if (target == nums[mid]) {
//                lo = mid;
//                break;
//            } else if (target > nums[mid] || target <= nums[hi]) {
//                // target在（mid, hi]区间内（非单调递增）
//                lo = mid + 1;
//            } else {
//                // target在[lo, mid)区间内
//                hi = mid - 1;
//            }
//        } else {
//            // [mid, hi]为单调递增区间，[lo, mid]*可能*是单调递增区间
//            if (target == nums[mid]) {
//                lo = mid;
//                break;
//            } else if (nums[mid] < target && target <= nums[hi]) {
//                // target在(mid, hi]区间内
//                lo = mid + 1;
//            } else {
//                // target在[lo, mid)区间内
//                hi = mid - 1;
//            }
//        }
//    }
//    return target == nums[lo] ? lo : -1;
    int lo = 0;
    int hi = (int)nums.size() - 1;
    // 寻找翻转点pivot
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        // 必须是mid > hi，不可以使用mid > lo
        if (nums[hi] < nums[mid]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    int pivot = lo;
    lo = 0;
    hi = (int)nums.size() - 1;
    // 第一次剪枝，最佳情况是将解空间缩小到1/2，最差情况是将解空间缩小一个值
    if (0 < pivot && nums[lo] <= target && target <= nums[pivot - 1]) {
        // target在[lo, pivot-1]中
        hi = pivot - 1;
    } else if (nums[pivot] <= target && target <= nums[hi]) {
        // target 在[pivot, hi]中
        lo = pivot;
    } else {
        return -1;
    }
    // 经过第一次剪枝，[lo, hi]已经是单调递增区间，进行常规的二分查找即可
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] < target) {
            lo = mid + 1;
        } else if (nums[mid] > target) {
            hi = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
