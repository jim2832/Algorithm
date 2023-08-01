#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& box1, vector<int>& box2){
    return box1[1] > box2[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //先將資料依照容量大小作排序
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int total = 0; //總共能取多少

        for(vector<int>& box:boxTypes){
            if(!truckSize){
                break;
            }

            int number = box[0]; //背包的數量
            int capacity = box[1]; //背包的容量
            
            //還拿得動，全拿
            if(truckSize > number){
                truckSize -= number;
                total += number * capacity;
            }
            //沒辦法拿全部，只拿部分
            else{
                total += truckSize * capacity;
                truckSize = 0;
            }
        }

        return total;
    }
};