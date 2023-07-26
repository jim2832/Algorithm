#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    long long int sum(long long int mid){
        return mid*(mid+1)/2;
    }
public:
    //有k個row -> 可以放下 k*(k+1)/2 個 coins
    // (k-1)*k/2 < n < k*(k+1)/2
    int arrangeCoins(int n){
        int lower = 0;
        int upper = 2*sqrt(n);

        while(upper > lower){
            int mid = lower + (upper - lower) / 2;
            if(sum(mid) == n){
                return mid;
            }
            else if(sum(mid) > n){
                upper = mid;
            }
            // mid*(mid+1)/2 < n
            else{
                lower = mid+1;
            }
        }

        return lower-1;
    }
};