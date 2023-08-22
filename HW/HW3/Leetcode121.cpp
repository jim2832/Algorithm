#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0; //紀錄最高價值
        int min_value = 2147483647; //紀錄價格最低點
        int len = prices.size();

        //exception
        if(len == 1){
            return 0;
        }

        // DP approach
        for(int i=0; i<len; i++){
            max_profit = prices[i] - min_value > max_profit ? prices[i] - min_value : max_profit;
            min_value = prices[i] < min_value ? prices[i] : min_value;
        }

        return max_profit;
    }
};