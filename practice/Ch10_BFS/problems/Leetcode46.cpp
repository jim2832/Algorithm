#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

//用 BFS 和 queue 的概念解

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        queue<vector<int>> permutation; //用來存每種排列的vector
        vector<vector<int>> final_result;

        for(int i=0; i<len; i++){
            //建立一個新的vector來存
            vector<int> temp(1, nums[i]);
            //先把初始vector內的每個元素push進queue
            permutation.push(temp);
        }

        while(!permutation.empty()){
            vector<int> current = permutation.front(); //取出queue第一筆資料
            permutation.pop(); //刪除queue第一筆資料
            
            //檢查現在vector的長度是否已經和原先初始vector一樣 -> 代表是最後一輪
            if(current.size() == len){
                final_result.push_back(current);
                continue;
            }

            for(int i=0; i<len; i++){
                //如果 nums[i] 不在 current 內
                auto iter = find(current.begin(), current.end(), nums[i]);
                if(iter != current.end()){ //有找到
                    continue;
                }
                else{ //沒找到
                    vector<int> result(current.begin(), current.end());
                    result.push_back(nums[i]);
                    permutation.push(result);
                }
            }
        }

        return final_result;
    }
};