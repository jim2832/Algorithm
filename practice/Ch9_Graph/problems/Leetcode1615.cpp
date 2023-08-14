#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

// 先計算每個城市有幾個邊
// 再計算所有兩兩相鄰的城市間最多有幾個邊
// A城市和B城市之間路的數量(若有相連)：A城市的路 + B城市的路 - 1
// A城市和B城市之間路的數量(若沒相連)：A城市的路 + B城市的路

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> num_edges(n, 0); //紀錄每個頂點有幾條邊
        vector<vector<bool>> is_connected(n, vector<bool>(n, false)); //紀錄點跟點跟之間是否有相連

        for(auto& road:roads){
            // road[0] <-> road[1] (undirected)
            num_edges[road[0]]++;
            num_edges[road[1]]++;
            is_connected[road[0]][road[1]] = true;
            is_connected[road[1]][road[0]] = true;
        }

        int max = -2147483648;
        int current; //紀錄目前有幾條邊

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //自己不能和自己比較
                if(i == j){
                    continue;
                }
                //如果 i 和 j 有相連
                else if(is_connected[i][j]){
                    current = num_edges[i] + num_edges[j] - 1;
                }
                else{ //如果 i 和 j 沒有相連
                    current = num_edges[i] + num_edges[j];
                }
                max = current > max ? current : max;
            }
        }

        return max;
    }
};