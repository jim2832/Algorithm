#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

// 此題為 BFS 之應用

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // sr: source row
        // sc: source column

        int rows = image.size();
        int cols = image[0].size();
        queue<int> Pixel; //用來存座標

        // image[2][1] -> 2 * cols + 1 = P
        // image[x][y] -> x * cols + y = P
        // P = (P / cols, P % cols) -> 轉換成(x,y)座標

        Pixel.push(sr * cols + sc); //先把起點push到queue裡面
        int origin_color = image[sr][sc]; //先記錄image[sr][sc]原本的顏色
        image[sr][sc] = color; //替換掉起點的顏色

        //exception
        //若要替換的顏色和原本的一樣，則直接回傳原圖就好
        if(origin_color == color){
            return image;
        }

        while(!Pixel.empty()){
            int current = Pixel.front();
            Pixel.pop();
            int x = current / cols; 
            int y = current % cols;

            //往下走訪(如果下面的顏色要換掉的話)
            if(x+1 < rows && image[x+1][y] == origin_color){
                image[x+1][y] = color;
                int P = (x+1) * cols + y; //算出pixel的位置
                Pixel.push(P);
            }

            //往上走訪(如果上面的顏色要換掉的話)
            if(x-1 >= 0 && image[x-1][y] == origin_color){
                image[x-1][y] = color;
                int P = (x-1) * cols + y; //算出pixel的位置
                Pixel.push(P);
            }

            //往左走訪(如果左面的顏色要換掉的話)
            if(y-1 >= 0 && image[x][y-1] == origin_color){
                image[x][y-1] = color;
                int P = x * cols + (y-1); //算出pixel的位置
                Pixel.push(P);
            }

            //往右走訪(如果右面的顏色要換掉的話)
            if(y+1 < cols && image[x][y+1] == origin_color){
                image[x][y+1] = color;
                int P = x * cols + (y+1); //算出pixel的位置
                Pixel.push(P);
            }
        }

        return image;
    }
};