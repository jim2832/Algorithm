#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int step_1 = cost[0];
        int step_2 = cost[1];
        int step_3;

        // 處理邊界條件
        cost.push_back(0);

        for(int i=2; i<=len; i++){
            step_3 = min(step_1, step_2) + cost[i];
            //重複利用變數
            step_1 = step_2;
            step_2 = step_3;
        }

        return step_3;
    }
};