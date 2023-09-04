#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

// 利用BFS來處理最短路徑問題

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<int> Position;

        //如果起點是牆壁，則直接結束
        if(grid[0][0] == 1){
            return -1;
        }
        Position.push(0);

        //把所有 1(牆壁) 都改成 -1
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = -1;
                }
                else{
                    grid[i][j] = 2147483647; //設定成無限大
                }
            }
        }
        grid[0][0] = 1;
        
        //八種方向(上、下、左、右、左上、右上、左下、右下)
        int direction_x[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        int direction_y[8] = {0, 0, -1, 1, 1, -1, -1, 1};

        //BFS
        while(!Position.empty()){
            int current = Position.front();
            Position.pop();
            int x = current / cols;
            int y = current % cols;
            int distance = grid[x][y]; //取出目前的距離

            // 8個方向
            for(int i=0; i<8; i++){
                int offset_x = direction_x[i]; //x偏移量
                int offset_y = direction_y[i]; //y偏移量
                int new_x = x + offset_x; //新的x座標
                int new_y = y + offset_y; //新的y座標
                
                //檢查邊界條件
                if(new_x < 0 || new_y < 0){
                    continue;
                }
                if(new_x >= rows || new_y >= cols){
                    continue;
                }
                if(grid[new_x][new_y] == -1){ //是牆壁
                    continue;
                }

                int distance_now = distance + 1;
                if(distance_now < grid[new_x][new_y]){
                    grid[new_x][new_y] = distance_now;
                    int P = new_x * cols + new_y;
                    Position.push(P);
                }
            }
        }
        
        //如果最右下角那格仍然是無限大，表示沒被更新到，表示無法走到
        if(grid[rows-1][cols-1] == 2147483647){
            return -1;
        }
        return grid[rows-1][cols-1];
    }
};