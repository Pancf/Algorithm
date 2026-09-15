//
//  Solution130.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/20.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution130_hpp
#define Solution130_hpp

#include <stdio.h>
#include <vector>
#include <assert.h>

using std::vector;

class Solution130 {
public:
  void solve(vector<vector<char>>& board);
  static void test()
  {
    vector<vector<char>> board1 {
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'O', 'X'},
      {'X', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'}
    };
    Solution130 s;
    s.solve(board1);
    for (int i = 0; i < board1.size(); ++i) {
      for (int j = 0; j < board1[i].size(); ++j) {
        if (i == 3 && j == 1) {
          assert(board1[i][j] == 'O');
        } else {
          assert(board1[i][j] == 'X');
        }
      }
    }
    vector<vector<char>> board2 { {'X'} };
    s.solve(board2);
    assert(board2[0][0] == 'X');
  }
};

#endif /* Solution130_hpp */
