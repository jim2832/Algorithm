#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        //sorting
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0; //the index of nums1 and nums2
        while(i < nums1.size() && j < nums2.size()){
            // case 1
            if(nums1[i] < nums2[j]){
                i++;
            }
            // case 2
            else if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            // case 3
            // nums1[i] < nums2[j]
            else{
                j++;
            }
        }

        // eliminate the duplicate element
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }
};