#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills){
        // 三種不同面額硬幣之計數
        int five = 0, ten = 0, twenty = 0;
        int len = bills.size();

        for(int i=0; i<len; i++){
            int coin = bills[i]; //此次顧客所給的硬幣面額

            // case1: 如果顧客給5元
            if(coin == 5){
                five++;
            }

            // case2: 如果顧客給10元
            else if(coin == 10){
                //如果有5元，則直接找他5元
                if(five){
                    five--;
                    ten++;
                }
                //如果沒有5元，則直接不能找錢(沒其他方案)
                else{
                    return false;
                }
            }

            // case3: 如果顧客給20元
            else if(coin == 20){
                //如果同時有10元和5元，則優先用10元而不用5元(因為5元比較珍貴和好用)
                if(ten && five){
                    ten--;
                    five--;
                    twenty++;
                }
                //如果沒10元，那只能找3枚5元
                else if(five > 2){
                    five -= 3;
                    twenty++;
                }
                //如果沒10元且5元硬幣少於3枚，則找不開
                else{
                    return false;
                }
            }
        }

        return true;
    }
};