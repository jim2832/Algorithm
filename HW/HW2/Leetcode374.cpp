#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lower = 1, upper = n;

        while(lower <= upper){
            int mid = lower + (upper - lower) / 2; //每次都猜正中間的
            int guess_result = guess(mid);

            if(guess_result == 0){
                return mid;
            }
            else if(guess_result == -1){
                upper = mid - 1;
            }
            else if(guess_result == 1){
                lower = mid + 1;
            }
        }

        return -1;
    }
};