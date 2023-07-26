#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //iteration version
        int lower = 0;
        int upper = n;

        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            bool isBad = isBadVersion(mid);
            //若是壞的，則代表好的應該在右邊
            if(isBad){
                upper = mid - 1;
            }
            //若是好的，則代表好的應該在左邊
            else{
                lower = mid + 1;
            }
        }
        return lower;
    }

    bool isBadVersion(int num){
        cout << "";
    }
};