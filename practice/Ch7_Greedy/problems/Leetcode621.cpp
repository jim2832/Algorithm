/*

給定一連串回家作業Hi
每份作業都有各自的繳交期限Di
遲交的扣分Pi
已知每份作業都需要一天的時間完成，則該如何安排寫作業的順序可以讓遲交的扣分最少?

實際步驟：
1. 依照 Pi 進行排序
2. 依照 Pi 大小把 Hi 放到死線 Di 前
   A. 有衝突往前放
   B. 放滿了代表只能遲交，往最後放

*/

// 若只有有一個工作A，則總長為(n+1)(t-1)+1
// 若有兩個工作A, B，則總長為(n+1)(t-1)+counts
// 通式: max(taskAmount, (n+1)(t-1)+counts)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        int leastInterval(vector<char>& tasks, int n){
            int counts[26] = {0}; //紀錄每個英文字出現的次數
            
            for(char c:tasks){
                counts[c-'A']++;
            }

            // 計算裡面出現最多的次數為多少
            int max_frequency = -1; //出現頻率最大的
            for(int i=0; i<26; i++){
                if(counts[i] > max_frequency){
                    max_frequency = counts[i];
                }
            }

            // 最大頻率下的工作有多少種
            int max_frequency_words = 0;
            for(int i=0; i<26; i++){
                if(counts[i] == max_frequency){
                    max_frequency_words++;
                }
            }

            int result = (n+1)*(max_frequency-1) + max_frequency_words;
            return tasks.size() > result ? tasks.size() : result;
        }
};