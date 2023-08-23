#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); //加油站個數
        int total_gas = 0; //總共可以加的油
        int total_cost = 0; //總共需要耗費的油
        int current_gas = 0; //目前有多少油
        int start = 0; //起點

        for(int i=0; i<n; i++){
            //先確認能得到的所有油要 > 總消耗的油，不然無法完成
            total_gas += gas[i];
            total_cost += cost[i];

            //目前的油量
            current_gas += gas[i] - cost[i];
            
            //如果在中途油耗盡了，表示這個起點沒辦法完成旅途，要換下一個
            if(current_gas < 0){
                start = i+1; //換下一個起點
                current_gas = 0; //開始新的一輪，重置現有油量
            }

        }

        //如果能得到的油量 < 總消耗，代表沒辦法完成
        if(total_gas < total_cost){
            return -1;
        }
        else{
            return start;
        }
    }
};