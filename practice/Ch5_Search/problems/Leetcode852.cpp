#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // for(int i=1; i<arr.size()-1; i++){
        //     if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
        //         return i;
        //     }
        // }
        
        // return -1;
        
        int lower = 1;
        int upper = arr.size()-2;
        while(upper >= lower){
            int mid = lower + (upper - lower) / 2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1]){
                lower = mid + 1;
            }
            else{
                upper = mid - 1;
            }
        }
        
        return -1;
    }
};