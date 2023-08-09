#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    int start;
    int finish;
    int profit;
}job;

bool compare(job* A, job* B){
    return A->finish < B->finish;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len = profit.size(); //有幾個工作
        vector<job*> jobs(len); //存不同 job 的 vector (使用結構指標排序會更有效率)

        //先將 struct 初始化
        for(int i=0; i<len; i++){
            jobs[i] = new job{startTime[i], endTime[i], profit[i]};
        }

        //將工作依照結束時間由小排到大
        sort(jobs.begin(), jobs.end(), compare);

        //利用DP方法來不斷更新vector
        //總共天數的最後一天為最後一個工作的結束天數
        vector<int> max_profit(len+1, 0);

        for(int i=1; i<=len; i++){
            //每一個工作的 start, finish, profit
            int start = jobs[i-1]->start;
            int finish = jobs[i-1]->finish;
            int profit = jobs[i-1]->profit;

            // 第一個活動的特例
            if(i == 1){
                max_profit[i] = profit;
                continue;
            }
            
            // 若選擇當前這個工作可得的收益
            // 需往前找到上一個可行的工作
            int choose = profit;
            for(int j=i-2; j>=0; j--){
                if(jobs[j]->finish <= start){
                    choose += max_profit[j+1];
                    break;
                }
            }
            
            // 若不選擇當前這個工作可得的為上一個的收益
            int not_choose = max_profit[i-1];

            // 先比較選與不選兩個選項
            int max_choose = choose > not_choose ? choose : not_choose;
            
            // 再來要比較同一時間結束的不同工作中有較大收益者
            max_profit[i] = max_profit[i] > max_choose ? max_profit[i] : max_choose;
        }
        // 回傳最後一個工作結束時間的 max_profit
        return max_profit.back();
    }
};