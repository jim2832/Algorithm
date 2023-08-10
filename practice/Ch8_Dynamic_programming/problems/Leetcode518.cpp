#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

DP[i][j]: 用前 i 種硬幣去找 j 元

1. 如果不使用第 i 種硬幣，只使用前 i-1 種
則 DP[i][j] = DP[i-1][j]

2. 若使用至少一個第 i 種硬幣
則 DP[i][j-coin[i-1]]

*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<vector<int>> DP(len+1, vector<int>(amount+1, 0));
        DP[0][0] = 1;

        // row
        for(int i=1; i<=len; i++){
            DP[i][0] = 1;
            for(int j=1; j<=amount; j++){
                // DP[i][j] = DP[i-1][j] + DP[i][j-coins[i-1]]

                DP[i][j] += DP[i-1][j]; //如果不選擇第i個硬幣
                
                if(j-coins[i-1] >= 0){ //檢查要>=0
                    DP[i][j] += DP[i][j-coins[i-1]]; //如果選擇第i個硬幣
                }
            }
        }

        return DP[len][amount];
    }
};

//另一種解法(比較省空間複雜度)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<int> DP(amount+1, 0);
        DP[0] = 1;

        for(int coin:coins){
            for(int i=coin; i<=amount; i++){
                DP[i] += DP[i-coin];
            }
        }

        return DP[amount];
    }
};