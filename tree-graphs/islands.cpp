//https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<char>> & grid, int row, int col){

    int maxRowPos = grid.size();
    int maxColPos = grid[row].size();
    grid[row][col] = 0;

    //left
    if (col > 0 && grid[row][col-1] == 1){
        dfs(grid, row, col-1);
    }

    //right
    if (col+1 < maxColPos && grid[row][col+1] == 1){
        dfs(grid, row, col+1);
    }

    //top
    if (row > 0 && grid[row-1][col] == 1){
        dfs(grid, row-1, col);
    }

    //bottom
    if (row+1 < maxRowPos && grid[row+1][col] == 1){
        dfs(grid, row+1, col);
    }
}

int numIslands(vector<vector<char>> & grid){
    int islands = 0;
    for(int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            //land, follow it
            if (grid[i][j] == 1) {
                islands++;
                dfs(grid, i, j);
            }
        }
    }
    return islands;
}

  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
  }
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }
    return num_islands;
  }


int main (){

     vector<vector<char>> grid1 = {
      {1,1,1,1,0},
      {1,1,0,1,0},
      {1,1,0,0,0},
      {0,0,0,0,0}
    };

    vector<vector<char>> grid2 = {
      {1,1,0,0,0},
      {1,1,0,0,0},
      {0,0,1,0,0},
      {0,0,0,1,1}
    };



    cout << "ANSWER1: " << numIslands(grid1) << "\n";
    cout << "ANSWER2: " <<  numIslands(grid2) << "\n";
}