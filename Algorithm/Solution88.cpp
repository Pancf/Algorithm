//
//  Solution88.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/8.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution88.hpp"

void Solution88::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    if (i < 0) {
        while (k >= 0 && j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
}
