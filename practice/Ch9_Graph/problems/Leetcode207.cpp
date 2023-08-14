#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

/*

這題在考 AOV network

演算法:
1. 先找到一個 in degree 為 0 的點
2. 刪除其相鄰邊
3. 不斷重複 step1 和 step2 直到找不到 in degree 為 0 的點  

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses); //紀錄順序
        vector<int> in_degree(numCourses, 0); //紀錄每個點的 in degree
        queue<int> topological_sort; //紀錄已處理好的順序
        int visited = 0; //紀錄已經走訪過的點

        //把prerequisites每筆資料取出來
        for(auto& prerequisite:prerequisites){
            // prerequisites[1] -> prerequisites[0] (代表先完成1才能做0)
            edges[prerequisite[1]].push_back(prerequisite[0]);
            in_degree[prerequisite[0]]++; //被指到所以in degree +1
        }

        //先找出一個 in degree 為 0 的點
        for(int i=0; i<numCourses; i++){
            if(in_degree[i] == 0){
                topological_sort.push(i);
                visited++;
            }
        }

        while(!topological_sort.empty()){
            int current = topological_sort.front();
            topological_sort.pop();
            
            int edge_count = edges[current].size(); //目前這個點有幾個邊
            // 刪除所有這個點的相鄰邊
            for(int i=0; i<edge_count; i++){
                // current -> edges[current][i]
                in_degree[edges[current][i]]--; //因為刪掉了，所以被指向的點 in degree 要 -1
                if(in_degree[edges[current][i]] == 0){
                    topological_sort.push(edges[current][i]);
                    visited++;
                }
            }
        }

        //若最後 in degree 為 0 的節點數等於總節點數，則代表有一組 topological_sort
        return (visited==numCourses);
    }
};