#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    void Bubble_sort(vector<int>& nums){
    for(int i=0; i<nums.size()-1; i++){
        for(int j=0; j<nums.size()-i-1; j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

    void sortColors(vector<int>& nums) {
        // 0: red
        // 1: white
        // 2: blue
        Bubble_sort(nums);
    }
};