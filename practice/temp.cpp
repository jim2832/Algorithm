#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
            return nums[0];
        if(len==0)
            return -2147483648;

        vector<int> data_left(nums.begin(),nums.begin()+(len-1)/2);
        vector<int> data_right(nums.begin()+(len+1)/2,nums.end());
        int max_left = maxSubArray(data_left);
        int max_right = maxSubArray(data_right);
        int max_center = maxCrossArray(nums);

        if(max_left>=max_center && max_left>=max_right)
            return max_left;
        else if(max_right>=max_center && max_right>=max_left)
            return max_right;
        else
            return max_center;
    }
    int maxCrossArray(vector<int>& nums) {
        int len = nums.size();
        int max_center = nums[(len-1)/2];
        int index_left = -1, index_right = 1,left_sum = 0,right_sum = 0, max = 0;
        while((len-1)/2+index_left>=0){
            left_sum += nums[(len-1)/2+index_left];
            if(left_sum > max)
                max = left_sum;
            index_left--;
        }
        max_center += max;

        max = 0;
        while((len-1)/2+index_right<len){
            right_sum += nums[(len-1)/2+index_right];
            if(right_sum > max)
                max = right_sum;
            index_right++;
        }
        max_center += max;
        return max_center;
    }
};