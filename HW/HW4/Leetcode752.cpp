#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans = 0;
        queue<string> q;

        set<string> s(deadends.begin(), deadends.end());
        //如果 deadends 中有 "0000" 則直接結束
        if(s.find("0000") != s.end()){
            return -1;
        }

        //BFS
        q.push("0000");
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                //取出 queue 中第一個元素
                auto current = q.front();
                q.pop();

                //找到答案
                if(current == target){
                    return ans;
                }

                //4個號碼
                for(int j=0; j<4; j++){
                    string forward, backward;

                    forward = current.substr(0,j) + to_string(current[j]=='0'?9:current[j]-'0'-1) + current.substr(j+1);
                    backward = current.substr(0,j) + to_string(current[j] =='9'?0:current[j]-'0'+ 1) + current.substr(j+1);

                    //check
                    if(!s.count(forward)){
                        s.insert(forward);
                        q.push(forward);
                    }
            
                    //check
                    if(!s.count(backward)){
                        s.insert(backward);
                        q.push(backward);
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};