#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> visited; //黑灰白
    vector<int> color; //顏色

    bool DFS(int vertex, int color_now, vector<vector<int>>& graph){
        visited[vertex] = 1;
        for(int i=0; i<graph[vertex].size(); i++){ //走訪相鄰節點
            int vertex_now = graph[vertex][i];
            if(color[vertex_now] == color_now){ //如果遇到一樣顏色的，代表不是二分圖
                return false;
            }
            if(visited[vertex_now] == 0){ //白點
                if(color[vertex_now] == -1){
                    color[vertex_now] = !color_now;
                }
                bool flag = DFS(vertex_now, !color_now, graph);
                if(!flag){
                    return false;
                }
            }
        }
        visited[vertex] = 2;
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vertex = graph.size(); //節點數量
        visited.resize(vertex);
        color.resize(vertex, -1);

        // DFS
        // color: 0 1 0 1 0 1...
        for(int i=0; i<vertex; i++){
            if(!visited[i]){ //如果還沒走訪過
                color[i] = 0;
                bool flag = DFS(i, 0, graph);
                if(!flag){
                    return false;
                }
            }
        }

        return true;
    }
};