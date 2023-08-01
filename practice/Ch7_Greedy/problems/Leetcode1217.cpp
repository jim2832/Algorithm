#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //目標: 回傳 min(奇數的籌碼和, 偶數的籌碼和)
    int minCostToMoveChips(vector<int>& position){
        int len = position.size();
        int odd_sum = 0, even_sum = 0;

        for(int i=0; i<len; i++){
            if(position[i] % 2){
                odd_sum++;
            }
            else{
                even_sum++;
            }
        }

        //return odd_sum < even_sum ? odd_sum : even_sum;
        return min(odd_sum, even_sum);
    }
};