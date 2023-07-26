#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //recursion version
        //return Binary_search(nums, 0, nums.size()-1, target);
        
        //iteration version
        int lower = 0;
        int upper = nums.size()-1;
        int position;
        while(upper >= lower){
            int mid = (lower + upper) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                upper = mid-1;
                position = mid;
            }
            else if(nums[mid] < target){
                lower = mid+1;
                position = mid+1;
            }
        }
        return position;
    }
    
    //recursion version
    /*
    int Binary_search(vector<int> &nums, int lower, int upper, int target){
        if(upper < lower){
            return lower;
        }
        
        int mid = lower + (upper - lower) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            return Binary_search(nums, lower, mid-1, target);
        }
        else{
            return Binary_search(nums, mid+1, upper, target);
        }
    }
    */
};