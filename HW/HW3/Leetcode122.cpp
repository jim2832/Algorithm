#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 一次只能擁有一個股票
        // 可以馬上買馬上賣
        int maxProfit = 0;
        
        for(int i=0; i<prices.size()-1; i++){
            maxProfit += max(prices[i+1] - prices[i], 0);
        }
   
        return maxProfit;
    }
};