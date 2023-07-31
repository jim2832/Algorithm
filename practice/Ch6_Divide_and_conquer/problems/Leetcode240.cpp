#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 此題是使用 divide and conquer 方法
    // 會將問題拆解成 "往下找(找大的)" 以及 "往左找(找小的)" 來找到目標

    bool searchMatrix(vector<vector<int>>& matrix, int target){
        // exception
        if(matrix.empty()){
            return false;
        }
        if(matrix[0].empty()){
            return false;
        }

        int rows = matrix.size(); //列數
        int cols = matrix[0].size(); //行數
        int cur_row = 0, cur_col = cols - 1; //目前在的列與行(起點為最左上角)
        
        while(cur_row < rows && cur_col >= 0){
            if(matrix[cur_row][cur_col] == target){
                return true;
            }
            else if(matrix[cur_row][cur_col] > target){
                cur_col--;
            }
            else{ // matrix[cur_row][cur_col] < target
                cur_row++;
            }
        }

        return false;
    }
};