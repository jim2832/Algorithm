#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct{
    int from; //指到這個點的點
    int to; //指向的點
    int flow; //現在流量
    int capacity; //總流量
}edge;

class Graph{
    public:
        Graph(int); //建構式
        void print_edges(); //印出 adjacency matrix
        void add_edge(int, int, int=1); //新增一條邊(from, to, weight)
        int Network_flow(int, int); //Edmonds_Karps(s: 起點, t: 匯點)

    private:
        int vertex; //紀錄節點
        vector<list<edge*>> edges;
};

//建構式
Graph::Graph(int v){
    vertex = v; //表示有幾個頂點
    edges.resize(vertex);
}

//印出 adjacency list
void Graph::print_edges(){
    for(int i=0;i<vertex;i++){
        cout << i+1 << "\t";
        auto iter = edges[i].begin();
        // list<edge*>::iterator
        for(;iter!=edges[i].end();iter++){
            cout << "->" << (*iter)->to+1 << "," << (*iter)->capacity;
        }
        cout << endl;
    }
}

//新增一條邊(from, to, weight) -> 若新增成功回傳true，否則回傳false
void Graph::add_edge(int from, int to, int capacity){
    edges[from-1].push_back(new edge{from-1, to-1, 0, capacity});
    edges[to-1].push_back(new edge{to-1, from-1, 0, capacity}); // Undirected graph
}

// Edmonds_Karps
int Graph::Network_flow(int s, int t){
    s--;
    t--;
    int max_flow = 0;

    while(true){

        // step1: find a augmenting path(增廣路徑)
        queue<vector<int>> data; //紀錄路徑
        bool found = false;
        vector<int> initial_path, current, visited(vertex);
        initial_path.push_back(s);
        visited[s] = 1;
        data.push(initial_path);

        while(!data.empty()){
            current = data.front();
            data.pop();
            int now = current.back();

            //到終點了
            if(now == t){
                found = true;
                break;
            }
            else{
                for(auto iter=edges[now].begin(); iter!=edges[now].end(); iter++){
                    if((*iter)->capacity > (*iter)->flow && visited[(*iter)->to] == 0){ //還有足夠的流量空間
                        vector<int> new_path = current;
                        new_path.push_back((*iter)->to);
                        visited[(*iter)->to] = 1;
                        data.push(new_path);
                    }
                }
            }
        }

        // Augmenting path not found
        if(!found)
            break;

        // step 2: Find the minimal residual capacity
        int minimal = 2147483647;
        for(int i=0; i<current.size()-1; i++){
            int u = current[i];
            int v = current[i+1];
            for(auto iter=edges[u].begin();iter!=edges[u].end();iter++){
                if((*iter)->to == v){
                    if((*iter)->capacity - (*iter)->flow < minimal)
                        minimal = (*iter)->capacity - (*iter)->flow;
                }
            }
        }

        // step 3: Update the residual networks
        for(int i=0; i<current.size()-1; i++){
            int u = current[i];
            int v = current[i+1];
            for(auto iter=edges[u].begin();iter!=edges[u].end();iter++){
                if((*iter)->to == v){
                    (*iter)->flow += minimal;
                }
            }
        }
        
        max_flow += minimal;
    }

    return max_flow;
}

int main(void){
    Graph graph(7);
    graph.add_edge(1,2,20);
    graph.add_edge(1,3,10);
    graph.add_edge(1,4,15);
    graph.add_edge(2,5,10);
    graph.add_edge(3,5,10);
    graph.add_edge(3,4,10);
    graph.add_edge(3,6,5);
    graph.add_edge(4,7,25);
    graph.add_edge(6,7,10);
    graph.add_edge(5,7,5);

    int s = 1, t = 7;
    cout << "Max Flow from " << s << " to " << t << ": " << graph.Network_flow(s,t);

    return 0;
}