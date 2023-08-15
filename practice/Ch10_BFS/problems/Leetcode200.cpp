#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

//此題為BFS之應用

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<int> Pixel; //用一個pixel來表示(x,y)座標
        int island = 0;

        // 0: 海洋
        // 1: 未造訪過的路地
        // 2: 已造訪過的路地
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '1'){ //如果有發現陸地，則對他做BFS
                    island++; //找到一個島嶼
                    grid[i][j] = '2'; //代表已經走訪過
                    int P = i * cols + j; //先算出pixel值
                    Pixel.push(P);

                    //BFS
                    while(!Pixel.empty()){
                        int current = Pixel.front();
                        Pixel.pop();
                        int x = current / cols;
                        int y = current % cols;
                        
                        //向下走訪
                        if(x+1 < rows && grid[x+1][y] == '1'){
                            grid[x+1][y] = '2';
                            int P_now = (x+1) * cols + y; //先算出pixel值
                            Pixel.push(P_now);
                        }

                        //向上走訪
                        if(x-1 >= 0 && grid[x-1][y] == '1'){
                            grid[x-1][y] = '2';
                            int P_now = (x-1) * cols + y; //先算出pixel值
                            Pixel.push(P_now);
                        }

                        //向右走訪
                        if(y+1 < cols && grid[x][y+1] == '1'){
                            grid[x][y+1] = '2';
                            int P_now = x * cols + (y+1); //先算出pixel值
                            Pixel.push(P_now);
                        }

                        //向左走訪
                        if(y-1 >= 0 && grid[x][y-1] == '1'){
                            grid[x][y-1] = '2';
                            int P_now = x * cols + (y-1); //先算出pixel值
                            Pixel.push(P_now);
                        }
                    }
                }
            }
        }

        return island;
    }
};