#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

//MST

struct edge{
    int from;
    int to;
    int cost;
};

// Kruskal's algo
class compare{
    public:
        bool operator()(edge &e1, edge &e2){
            return e1.cost > e2.cost;
        }
};

class Solution {
        vector<int> MST_set;
        int ans = 0;

    public:
        int find_set(int current){
            int root = current;

            //先找到根節點
            while(MST_set[root] >= 0){
                root = MST_set[root];
            }

            //current不斷往上，直到找到根節點
            while(current != root){
                int predecessor = MST_set[current];
                MST_set[current] = root; //指向根節點
                current = predecessor;
            }

            return root;
        }

        void merge_set(int u, int v){
            int u_root = find_set(u);
            int v_root = find_set(v);

            if(u_root == v_root) return;

            //代表 u_root 比較大
            if(MST_set[u_root] <= MST_set[v_root]){
                MST_set[u_root] += MST_set[v_root];
                MST_set[v_root] = u_root; //讓 v 指向 u
            }
            else{ //代表 v_root 比較大
                MST_set[v_root] += MST_set[u_root];
                MST_set[u_root] = v_root; //讓 u 指向 v
            }
        }

        int minCostConnectPoints(vector<vector<int>>& points) {
            int vertex = points.size();
            int edges_completed = 0; //已經處理完的邊
            MST_set.resize(vertex);
            priority_queue<edge, vector<edge>, compare> sorted_edges;

            // push and initialization
            for(int i=0; i<vertex; i++){
                MST_set[i] = -1; //一開始每個點自己本身都是一個MST

                // edge i -> j
                for(int j=i+1; j<vertex; j++){
                    int current_cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    edge current = {i, j, current_cost};
                    sorted_edges.push(current);
                }
            }

            while(!sorted_edges.empty() && edges_completed < vertex-1){
                edge current = sorted_edges.top();
                sorted_edges.pop();
                //確認不會形成環
                if(find_set(current.from) != find_set(current.to)){
                    merge_set(current.from, current.to);
                    ans += current.cost;
                    edges_completed++;
                }
            }

            return ans;
        }
};

// Prim's algo
class Solution {
        int vertex;
        vector<int> predecessor; //紀錄如果要走到MST，要走哪個點
        vector<int> distance;
        vector<bool> finished;
        vector<list<edge>> edges;

    public:
        int find_minimal_distance(){
            int minimal = INT_MAX;
            int index = -1;
            for(int i=0; i<vertex; i++){
                if(distance[i] < minimal && !finished[i]){
                    index = i;
                    minimal = distance[i];
                }
            }
            return index;
        }
        
        int minCostConnectPoints(vector<vector<int>>& points) {
            vertex = points.size();
            // init
            predecessor.resize(vertex);
            distance.resize(vertex);
            finished.resize(vertex);
            edges.resize(vertex);
            for(int i=0; i<vertex; i++){
                predecessor[i] = -1;
                distance[i] = INT_MAX;
                finished[i] = false;
            }

            // push and initialization
            for(int i=0; i<vertex; i++){
                // edge i -> j
                for(int j=i+1; j<vertex; j++){
                    int current_cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    edge current1 = {i, j, current_cost};
                    edge current2 = {j, i, current_cost};
                    edges[i].push_back(current1);
                    edges[j].push_back(current2);
                }
            }

            //先選一個起點 (以0為例)
            distance[0] = 0;
            int index, sum = 0; //index代表被選定的點
            for(int i=0; i<vertex; i++){
                index = find_minimal_distance(); //選一個就目前點來說權重最小的
                finished[index] = true;
                sum += distance[index];
                for(auto iter=edges[index].begin(); iter!=edges[index].end(); iter++){
                    int target = iter->to;
                    int current_weight = distance[target];
                    int cross_weight = iter->cost;
                    if(finished[target]){
                        continue;
                    }
                    if(cross_weight < current_weight){
                        distance[target] = cross_weight;
                        predecessor[target] = index;
                    }
                }
            }

            return sum;
        }
};