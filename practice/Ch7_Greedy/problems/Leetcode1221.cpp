#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int L_count = 0, R_count = 0;
        int counts = 0;
        
        for(char c:s){
            if(c == 'L'){
                L_count++;
            }
            else{ // c == 'R'
                R_count++;
            }

            if(L_count == R_count && L_count){
                L_count = R_count = 0;
                counts++;
            }
        }

        return counts;
    }
};