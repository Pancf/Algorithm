//
//  Solution130.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/20.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution130.hpp"

static void BFS(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y)
{
  // out of bound
  if (x < 0 || x >= board.size()) return;
  if (y < 0 || y >= board[0].size()) return;
  if (board[x][y] == 'X' || visited[x][y] == 1) return;
  if (board[x][y] == 'O') visited[x][y] = 1;
  BFS(board, visited, x - 1, y); // left
  BFS(board, visited, x, y - 1); // top
  BFS(board, visited, x + 1, y); // right
  BFS(board, visited, x, y + 1); // bottom
}

void Solution130::solve(vector<vector<char>> &board)
{
  
  size_t row = board.size();
  size_t col = board[0].size();
  if (row == 1 || col == 1) return;
  
  vector<vector<int>> visited{row, vector<int>(col, 0)};
  int i = 0, j = 0;
  for (; j < col; ++j) {
    if (board[0][j] == 'O' && visited[0][j] == 0) {
      // collect path
      BFS(board, visited, 0, j);
    }
  }
  for (; i < row; ++i) {
    if (board[i][col - 1] == 'O' && visited[i][col - 1] == 0) {
      BFS(board, visited, i, static_cast<int>(col) - 1);
    }
  }
  for (j = 0; j < col; ++j) {
    if (board[row - 1][j] == 'O' && visited[row - 1][j] == 0) {
      BFS(board, visited, static_cast<int>(row) - 1, j);
    }
  }
  for (i = 0; i < row; ++i) {
    if (board[i][0] == 'O' && visited[i][0] == 0) {
      BFS(board, visited, i, 0);
    }
  }
  for (i = 0; i < row; ++i) {
    for (j = 0; j < col; ++j) {
      if (visited[i][j] == 1) {
        board[i][j] = 'O';
      } else {
        board[i][j] = 'X';
      }
    }
  }
}
