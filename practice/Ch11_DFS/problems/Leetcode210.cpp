#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//DFS解法
class Solution {
    vector<int> color;
    vector<vector<int>> edges; //紀錄相鄰邊
    vector<int> topological_sort; //紀錄修課順序

    bool check_cycle(int vertex){
        color[vertex] = 1; //走訪後設定成灰色

        for(int i=0; i<edges[vertex].size(); i++){
            if(color[edges[vertex][i]] == 0){ //如果是白點，則可以繼續走訪
                bool cycled = check_cycle(edges[vertex][i]); //繼續往下走訪
                if(cycled){ //有環
                    return true;
                }
            }
            //有環(有走訪到黑點)
            else if(color[edges[vertex][i]] == 1){
                return true;
            }
        }
        
        color[vertex] = 2; //走訪後設定成黑色
        topological_sort.insert(topological_sort.begin(), vertex);
        return false;
    }

    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            color.resize(numCourses);
            edges.resize(numCourses);
            vector<int> empty;

            for(auto edge:prerequisites){
                // edge[1] -> edge[0]
                edges[edge[1]].push_back(edge[0]);
            }

            //DFS
            for(int i=0; i<numCourses; i++){
                if(color[i] == 0){ //找白點
                    //檢查是否有環，如果有，則無法符合題目條件
                    bool cycled = check_cycle(i);
                    if(cycled){
                        return empty;
                    }
                }
            }

            return topological_sort;
        }
};