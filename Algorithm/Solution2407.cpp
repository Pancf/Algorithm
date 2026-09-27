//
//  Solution2407.cpp
//  Algorithm
//
//  Created by focus on 9/24/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution2407.hpp"
#include <algorithm>

class SegmentTree {
  int size_;
  vector<int> tree_;

  int query_util(int index_of_tree, int l, int r, int query_l, int query_r)
  {
    if (query_r < l || query_l > r) return 0;
    if (query_l <= l && query_r >= r) return tree_[index_of_tree];
    int m = (l + r) / 2;
    int left_val = query_util(index_of_tree * 2, l, m, query_l, query_r);
    int right_val = query_util(index_of_tree * 2 + 1, m + 1, r, query_l, query_r);
    return std::max(left_val, right_val);
  }
  
  void update_util(int index_of_tree, int l, int r, int pos, int val)
  {
    if (pos < l || pos > r) return;
    if (l == r) {
      tree_[index_of_tree] = std::max(tree_[index_of_tree], val);
      return;
    }
    int m = (l + r) / 2;
    update_util(2 * index_of_tree, l, m, pos, val);
    update_util(2 * index_of_tree + 1, m + 1, r, pos, val);
    tree_[index_of_tree] = std::max(tree_[index_of_tree * 2],
                                    tree_[index_of_tree * 2 + 1]);
  }
  
public:
  SegmentTree(int size) : size_(size)
  {
    // root start at index 1, left child is at index 2, right child is at index3
    // for node at index 'p', left child is at '2 * p', right child is at '2 * p + 1'
    int tree_size = ceil(log2(size));
    tree_size = pow(2, tree_size + 1);
    tree_ = vector<int>(tree_size, 0);
  }
  
  int max_value() { return tree_[1]; }
  
  int query(int query_l, int query_r)
  {
    return query_util(1, 0, size_ - 1, query_l, query_r);
  }
  
  void update(int i, int val)
  {
    update_util(1, 0, size_ - 1, i, val);
  }
  
};

int Solution2407::lengthOfLIS(vector<int>& nums, int k)
{
  int length = static_cast<int>(nums.size());
  if (length == 1) return 1;
  SegmentTree tree(1e5 + 1);
  for (auto num : nums) {
    int lower = std::max(0, num - k);
    int cur = tree.query(lower, num - 1) + 1;
    tree.update(num, cur);
  }
  return tree.max_value();
}
