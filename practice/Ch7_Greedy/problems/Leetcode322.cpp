#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //這邊是用貪婪演算法(greedy)來做，但答案會是錯的(因為只考慮到局部最佳解)

    int coinChange(vector<int>& coins, int amount) {
        // exception
        if(amount == 0){
            return 0;
        }

        sort(coins.begin(), coins.end(), greater<int>()); //排序(由大到小)
        int coin = 0; //紀錄有幾枚硬幣
        int len = coins.size();

        for(int i=0; i<len; i++){
            int value = coins[i]; //目前硬幣的面額
            coin += amount / value; //目前要找幾枚硬幣(例如11元一開始找11/5=2枚)
            amount %= value; //剩餘要找的錢
        }

        // 如果最後要找的錢為0(也就是全部找開了)則回傳數量，否則回傳-1
        return (!amount) ? coin : -1;
    }
};