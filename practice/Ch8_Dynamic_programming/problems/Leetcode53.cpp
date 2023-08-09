#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 利用 DP 之方法
// 看加上新值後有沒有變大，如果有則更新，沒有的話就只算自己的就好
// DP[i] = max(DP[i-1] + Data[i], Data[i])

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 1){
            return nums[0];
        }

        vector<int> DP(len); //用來記錄到目前為止的最大值
        DP[0] = nums[0];
        for(int i=1; i<len; i++){
            // 看加上新值後有沒有變大，如果有則更新，沒有的話就只算自己的就好
            DP[i] = max(DP[i-1] + nums[i], nums[i]);
        }

        int max = *max_element(DP.begin(), DP.end()); //取 vector 內之最大值

        return max;
    }
};