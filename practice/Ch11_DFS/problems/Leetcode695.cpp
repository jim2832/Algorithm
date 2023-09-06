#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int area(vector<vector<int>>& grid, int i, int j, int row, int col){
            //檢查邊界條件
            if(i < 0 || j < 0){ //超出範圍
                return 0;
            }
            if(i >= row || j >= col){ //超出範圍
                return 0;
            }
            if(grid[i][j] == 0){ //是海洋
                return 0;
            }
            if(grid[i][j] == -1){ //已經走過
                return 0;
            }
            
            grid[i][j] = -1;
            int up = area(grid, i-1, j, row, col);
            int down = area(grid, i+1, j, row, col);
            int left = area(grid, i, j-1, row, col);
            int right = area(grid, i, j+1, row, col);
            
            return up + down + left + right + 1;
        }

        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int max = 0;
            int temp;

            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    if(grid[i][j] == 1){ //遇到陸地
                        temp = area(grid, i, j, row, col);
                        max = temp > max ? temp : max;
                    }
                }
            }

            return max;
        }
};