#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> in_degree(numCourses,0);
        for(auto& prerequisite:prerequisites){
            // prerequisite[1] -> prerequisite[0]
            edges[prerequisite[1]].push_back(prerequisite[0]);
            in_degree[prerequisite[0]]++;
        }
        
        queue<int> topological_sort;
        int visited = 0;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0){
                topological_sort.push(i);
                visited++;
            }
        }

        while(!topological_sort.empty()){
            int current = topological_sort.front();
            topological_sort.pop();
            
            int len = edges[current].size();
            for(int i=0;i<len;i++){
                // current->edges[current][i]
                in_degree[edges[current][i]]--;
                if(in_degree[edges[current][i]]==0){
                    topological_sort.push(edges[current][i]);
                    visited++;
                }
            }
        }
        return (visited==numCourses);
    }
};