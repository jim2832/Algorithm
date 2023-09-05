#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

//對邊緣的格子做BFS，且把走訪到的點改成0

class Solution {
public:
    void BFS(vector<vector<int>>& grid, int rows, int cols,  int start){
        int x = start / cols;
        int y = start % cols;

        int direction_x[4] = {-1, 1, 0, 0};
        int direction_y[4] = {0, 0, -1, 1};

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int P = q.front();
            q.pop();
            int x = P / cols;
            int y = P % cols;

            if(grid[x][y] == 0){
                continue;
            }

            grid[x][y] = 0;

            for(int i=0; i<4; i++){
                int new_x = x + direction_x[i];
                int new_y = y + direction_y[i];

                //邊界條件
                if(new_x < 0 || new_y < 0){
                    continue;
                }
                if(new_x >= rows || new_y >= cols){
                    continue;
                }
                //如果移動後是0，則不需加到queue中
                if(grid[new_x][new_y] == 0){
                    continue;
                }

                q.push(new_x * cols + new_y);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int sum = 0;

        for (int i = 0; i < rows; i++){
			// Position = x*cols+y
			// 檢查最左邊的直行
			if (grid[i][0]){
				// 對應的 Position 是 i*cols
                BFS(grid, rows, cols, i * cols);
			}
			// 檢查最右邊的直行
			if (grid[i][cols - 1]){
				// 對應的 Position 是 i * cols + (cols - 1)
                BFS(grid, rows, cols, i * cols + (cols - 1));
			}
		}
        
		for (int j = 0; j < cols; j++){
			// 檢查最上面的橫列
			if (grid[0][j]){
				// 對應的 Position 是 j
                BFS(grid, rows, cols, j);
			}
			// 檢查最下面的橫列
			if (grid[rows - 1][j]){
				// 對應的 Position 是 (rows-1)*cols+j
                BFS(grid, rows, cols, (rows - 1) * cols + j);
			}
		}
		// 用雙重迴圈檢查剩下幾個 1
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (grid[i][j])
					sum++;
			}
		}

        return sum;
    }
};