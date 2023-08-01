#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passenger(1001, 0); //計算每個站的上下車人數
        
        for(vector<int>& trip:trips){
            int num_passenger = trip[0]; //乘客數量
            int start_location = trip[1]; //起點
            int end_location = trip[2]; //終點

            passenger[start_location] += num_passenger; //起點的上車人數
            passenger[end_location] -= num_passenger; //終點的下車人數
        }

        for(int num:passenger){
            capacity -= num;

            //載不下了
            if(capacity < 0){
                return false;
            }
        }

        return true;
    }
};