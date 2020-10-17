//
//  Solution34.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/17.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution34.hpp"

std::vector<int> Solution34::searchRange(std::vector<int> &nums, int target)
{
// metho1, method1耗时比method2耗时更短的原因是method1更早剪枝
    if (nums.size() == 0) return {-1, -1};
    std::vector<int> res;
    int lo = 0, hi = (int)nums.size() - 1;
    int pivot = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            pivot = mid;
            break;
        } else if (nums[mid] > target && nums[lo] <= target) {
            // [lo, mid)
            hi = mid - 1;
        } else if (nums[mid] < target && target <= nums[hi]) {
            // (mid, hi]
            lo = mid + 1;
        } else {
            break;
        }
    }
    if (pivot == -1) return {-1, -1};
    // come here, means nums[pivot] == target
    lo = 0;
    hi = pivot;
    // find lower bound
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] < target) {
            // [lo, mid]被剪枝
            lo = mid + 1;
        } else {
            // nums[mid] == target
            hi = mid;
        }
    }
    res.push_back(lo);
    lo = pivot;
    hi = (int)nums.size() - 1;
    // find upper bound
    while (lo < hi) {
        // +1 非常重要，mid需要取ceil
        int mid = (lo + hi + 1) / 2;
        if (nums[mid] > target) {
            // [mid, hi]被剪枝
            hi = mid - 1;
        } else {
            // nums[mid] == target
            lo = mid;
        }
    }
    res.push_back(hi);
    return res;
// method2
//    std::vector<int> res{-1, -1};
//    if (nums.size() == 0) return res;
//    int lo = 0, hi = (int)nums.size() - 1;
//    // find lower bound
//    while (lo < hi) {
//        int mid = (lo + hi) / 2;
//        if (nums[mid] < target) {
//            // cut [lo, mid]
//            lo = mid + 1;
//        } else {
//            hi = mid;
//        }
//    }
//    if (target == nums[lo]) {
//        res[0] = lo;
//    } else {
//        // early prune
//        return res;
//    }
//    // it is unnacessary to reset lo
//    hi = (int)nums.size() - 1;
//    // find upper bound
//    while (lo < hi) {
//        // +1 is important which makes mid ceiling
//        int mid = (lo + hi + 1) / 2;
//        if (nums[mid] > target) {
//            // cut [mid, hi]
//            hi = mid - 1;
//        } else {
//            lo = mid;
//        }
//    }
//    res[1] = target == nums[lo] ? lo : -1;
//    return res;
}
