#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// using DP approach

// step[2]
// = min(step[0] + cost[2], step[1] + cost[2])
// = min(step[0], step[1]) + cost[2]
// = min(1, 100) + 1
// = 2

// step[3]
// = min(step[1], step[2]) + cost[3]
// = min(100, 2) + 1
// = 3

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        //紀錄每一階的最小成本(之所以長度為len+1是為了避免處理邊界條件而在尾端push進一個0)
        vector<int> step(len+1);

        // initialization
        step[0] = cost[0];
        step[1] = cost[1];

        // 尾端插入0避免處理邊界條件
        cost.push_back(0);

        for(int i=2; i<=len; i++){
            step[i] = min(step[i-1], step[i-2]) + cost[i];
            // step[i] = (step[i-1] < step[i-2] ? step[i-1] : step[i-2]) + cost[i];
        }

        return step[len];
    }
};