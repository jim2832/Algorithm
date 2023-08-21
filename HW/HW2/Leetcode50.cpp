#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // 將n視為一個二進制數字
        // 透過二進制的方式處理
        double result = 1;
        while(n){
            if(n % 2){
                if(n > 0){
                    result *= x;
                }
                else{
                    result /= x;
                }
            }
            x *= x;
            n /= 2;
        }

        return result;
        //return pow(x, n);
    }
};