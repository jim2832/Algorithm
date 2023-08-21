#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int lower = 1, upper = num / 2;
        if(num == 1){
            return true;
        }

        while(lower <= upper){
            long long int mid = lower + (upper - lower) / 2;
            if((long long)mid * mid == num){
                return true;
            }
            else if((long long)mid * mid > num){
                upper = mid - 1;
            }
            else{
                lower = mid + 1;
            }
        }

        return false;
    }
};