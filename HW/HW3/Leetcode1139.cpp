#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLargestSquare(vector<vector<int>>& matrix){ 
        int max = 0;
        int m = matrix.size(); //列數
        int n = matrix[0].size(); //行數
        vector<vector<int>> hor(m, vector<int>(n,0)); //用來累加水平值
        vector<vector<int>> ver(m, vector<int>(n,0)); //用來累加垂直值
    
        for(int i=0; i<m; i++){ 
            for(int j=0; j<n; j++){ 
                if(matrix[i][j] == 1){
                    hor[i][j] = (j == 0) ? 1 : hor[i][j-1] + 1; //水平累加
                    ver[i][j] = (i == 0) ? 1 : ver[i-1][j] + 1; //垂直累加
                } 
            } 
        } 
            
        for(int i=m-1; i>=0; i--){ 
            for(int j=n-1; j>=0; j--){ 
                //從兩個矩陣中選一個最小值
                int small = min(hor[i][j], ver[i][j]);

                while(small > max){
                    //check if square exists with 'small' length
                    if(ver[i][j-small+1] >= small && hor[i-small+1][j] >= small){
                        max = small;
                    }
                    small--; 
                } 
            } 
        } 
        return max * max; 
    } 

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        return findLargestSquare(grid);
    }
};