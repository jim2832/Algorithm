#include <iostream>
#include <vector>
using namespace std;

int maxCrossArray(vector<int> &nums){
    int len = nums.size();
    int mid = (len-1)/2; //取中心點
    int max_center = nums[mid];
    int index_left = -1, index_right = 1, left_sum = 0, right_sum = 0, max = 0;

    while(mid + index_left >= 0){
        left_sum += nums[mid + index_left];
        if(left_sum > max){
            max = left_sum;
        }
        index_left--;
    }
    max_center += max;

    max = 0;
    while(mid + index_right < len){
        right_sum += nums[mid + index_right];
        if(right_sum > max){
            max = right_sum;
        }
        index_right++;
    }
    max_center += max;

    return max_center;
}