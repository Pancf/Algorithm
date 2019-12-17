//
//  Solution4.cpp
//  Algorithm
//
//  Created by Pancf on 2019/11/24.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution4.hpp"


double Solution4::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    size_t new_vector_count = (nums1.size() + nums2.size()) / 2 + 1;
    bool select_last = (nums1.size() + nums2.size()) % 2;
    auto merge_vector = vector<int>();
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            merge_vector.push_back(nums1[i]);
            ++i;
        } else {
            merge_vector.push_back(nums2[j]);
            ++j;
        }
        if (merge_vector.size() == new_vector_count) {
            break;
        }
    }
    while (merge_vector.size() != new_vector_count) {
        if (i == nums1.size()) {
            if (j < nums2.size()) {
                merge_vector.push_back(nums2[j++]);
            }
        } else if (j == nums2.size()) {
            if (i < nums1.size()) {
                merge_vector.push_back(nums1[i++]);
            }
        }
    }
    if (select_last) {
        return merge_vector.back();
    } else {
        return (merge_vector[new_vector_count - 1] + merge_vector[new_vector_count - 2]) / 2.0;
    }
}
