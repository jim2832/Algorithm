#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

// 要自己寫一個排序法
// 若有兩個數字 a 和 b 
// 則我們要比較的規則為
// to_string(a) + to_string(b) > to_string(b) + to_string(a);

bool compare(int a, int b){
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare); //sorting
        string result = "";

        for(int i=0; i<nums.size(); i++){
            result += to_string(nums[i]);
        }

        //exception
        if(result[0] == '0'){
            return "0";
        }

        return result;
    }
};