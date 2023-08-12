#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int nodes = edges.size()+1;
        vector<int> degree(nodes, 0); //紀錄每個點的degree

        for(vector<int> edge:edges){
            degree[edge[0]-1]++;
            degree[edge[1]-1]++;
        }

        for(int i=0; i<nodes; i++){
            if(degree[i] == nodes-1){
                return i+1;
            }
        }

        return -1;
    }
};