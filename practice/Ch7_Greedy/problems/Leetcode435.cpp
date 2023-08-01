/*

使用 greedy 方法來處理

1. 把活動依照開始日期進行排序
2. 檢查第一個開始活動 a1 的區間，起點為s1，終點為f1
3. 檢查第二個開始活動 a2 的區間，起點為s2，終點為f2
   A. 若 s2 > f1，採納活動 a1 (代表完全沒有重疊)
   B. 若 s2 <= f1 (有重疊)
      a. 若 f2 > f1 (代表活動 a2 比 a1 還晚結束)，採納活動 a1
      b. 若 f2 <= f1 (代表 a2 比 a1 期間短，而且期間是 a1 的子集合)，採納活動 a2

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//排序: 前面活動的開始時間要小於後面活動的開始時間，也就是依照開始時間先後排序
bool compare(vector<int> interval_1, vector<int> interval_2){
    return interval_1[0] < interval_2[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), compare);
        int delete_num = 0; //要刪除幾個活動
        int finish = intervals[0][1]; //代表第一個活動的結束時間

        for(vector<int>& interval:intervals){
            int next_start = interval[0]; //下一個活動的開始時間
            int next_finish = interval[1]; //下一個活動的結束時間
            //如果沒有重疊
            if(next_start >= finish){
                finish = next_finish;
            }
            //有重疊 -> 刪除比較晚結束的活動
            else{ //next_start < finish
                delete_num++;
                // finish = min(finish, next_finish)
                finish = finish < next_finish ? finish : next_finish;
            }
        }
        //因為一開始 finish 設定成地一個活動的結束時間，這樣會和自己比較到
        //而這樣 delete_num 就會多減一次，因此最後要-1
        delete_num--;

        return delete_num;
    }
};