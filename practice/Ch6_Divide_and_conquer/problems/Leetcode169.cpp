#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 使用 divide and conquer 方法
    // 若左右兩邊 array 之眾數一樣，直接回傳
    // 否則，判斷左右兩個出現的眾數哪個比較多

    int majorityElement_range(vector<int>& nums, int lower, int upper){
        if(lower == upper){
            return nums[lower];
        }

        int mid = lower + (upper - lower) / 2; //中間之值
        int left_major = majorityElement_range(nums, lower, mid); //左邊之眾數
        int right_major = majorityElement_range(nums, mid+1, upper); //右邊之眾數

        //若左右兩邊眾數一樣，直接回傳
        if(left_major == right_major){
            return right_major;
        }

        //若左右兩邊眾數不一樣，則回傳較多那邊
        int left_count = 0, right_count = 0;
        for(int i=lower; i<=mid; i++){
            if(nums[i] == left_major){
                left_count++;
            }
        }
        for(int i=mid+1; i<=upper; i++){
            if(nums[i] == right_major){
                right_count++;
            }
        }

        return left_count > right_count ? left_major : right_major;
    }

    int majorityElement(vector<int>& nums){
        return majorityElement_range(nums, 0, nums.size()-1);
    }
};