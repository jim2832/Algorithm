#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
可以轉換為圖論問題
其實就是要找是否存在一點其 degree 為 n-1 (也就是法官)
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // exception
        if(!trust.size() && n == 1){
            return 1;
        }

        vector<int> in_degree(n, 0); //紀錄每個點的 in degree
        vector<int> out_degree(n, 0); //紀錄每個點的 out degree

        for(vector<int>& edge:trust){
            // edge[0] -> edge[1]
            in_degree[edge[1]-1]++;
            out_degree[edge[0]-1]++;
        }

        for(int i=0; i<n; i++){
            //所有人都信任法官，但法官不信任任何人
            if(in_degree[i] == n-1 && out_degree[i] == 0){
                return i+1;
            }
        }

        return -1;
    }
};