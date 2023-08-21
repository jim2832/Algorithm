#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // exception
        if(x < 0){
            return -1;
        }

        if(x == 0){
            return x;
        }

        //the first and last element respectively
        int lower = 1, upper = x;
        
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2; //取中間值

            // case1: equal
            if(mid == x / mid){
                return mid;
            }
            // case2: appear at the left part 
            else if(mid > x / mid){
                upper = mid - 1;
            }
            // case3: appear at the right part
            else{ // mid < x / mid
                lower = mid + 1;
            }
        }

        return upper;
    }
};