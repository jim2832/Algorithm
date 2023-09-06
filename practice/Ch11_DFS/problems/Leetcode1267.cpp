#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int connect(vector<vector<int>>& grid, int i, int j, int row, int col){
            if(grid[i][j] == -1){ //有走過(避免重複算)
                return 0;
            }
            grid[i][j] = -1;
            int row_sum = 0;
            int col_sum = 0;

            //每次處理一行
            for(int m=0; m<row; m++){
                if(grid[m][j] == 1){
                    col_sum += connect(grid, m, j, row, col); //計算這台server在這行和多少server相連
                }
            }

            //每次處理一列
            for(int n=0; n<col; n++){
                if(grid[i][n] == 1){
                    row_sum += connect(grid, i, n, row, col); //計算這台server在這行和多少server相連
                }
            }

            return row_sum + col_sum + 1;
        }

        int countServers(vector<vector<int>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int count = 0;

            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    if(grid[i][j] == 1){
                        int temp = connect(grid, i, j, row, col);
                        if(temp > 1){ //代表有和其他 server 相連
                            count += temp;
                        }
                    }
                }
            }

            return count;
        }
};