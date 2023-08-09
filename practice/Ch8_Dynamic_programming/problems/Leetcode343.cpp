#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> DP(n, 1); //存DP運算的結果

        for(int i=2; i<n; i++){
            // 把 i+1 分為 j, i-j+1
            int max = -2147483648;
            for(int j=1; j<i; j++){
                // j * DP[i-j]
                // j * (i-j+1)
                int now = j * DP[i-j] > j * (i-j+1) ? j * DP[i-j] : j * (i-j+1);
                max = now > max ? now : max;
            }
            DP[i] = max;
        }

        return DP[n-1];
    }
};