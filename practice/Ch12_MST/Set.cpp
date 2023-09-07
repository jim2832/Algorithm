#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

typedef struct{
    int to; //指向的點
    int weight; //指向點的權重
}edge;

class Graph{
    public:
        Graph(int); //建構式
        void print_edges(); //印出 adjacency matrix
        void add_edge(int, int, int=1); //新增一條邊(from, to, weight)
        int find_set(int); //找到是屬於哪個集合
        void merge_set(int, int); //合併兩個集合

    private:
        int vertex; //紀錄節點
        vector<list<edge*>> edges;
        vector<int> MST_Set; //紀錄每個頂點的set
};

//建構式
Graph::Graph(int v){
    vertex = v; //表示有幾個頂點
    edges.resize(vertex);
    MST_Set.resize(vertex);
}

//印出 adjacency list
void Graph::print_edges(){
    for(int i=0; i<vertex; i++){
        cout << i+1;

        auto iter = edges[i].begin();
        //list<edge*>::iterator

        for(; iter!=edges[i].end(); iter++){
            cout << " -> " << (*iter)->to+1 << "(" << (*iter)->weight << ")";
        }
        cout << endl;
    }
}

//新增一條邊(from, to, weight) -> 若新增成功回傳true，否則回傳false
void Graph::add_edge(int from, int to, int weight){
    edges[from-1].push_back(new edge{to-1, weight});
    edges[to-1].push_back(new edge{from-1, weight}); // undirected edge
}

//找到是屬於哪個集合
int Graph::find_set(int u){
    //先找到根節點
    int root = u;
    while(MST_Set[root] >= 0){
        root = MST_Set[root];
    }

    //u不斷往上，直到根節點
    while(u != root){
        int predecessor = MST_Set[u];
        MST_Set[u] = root; //直接指向根節點
        u = predecessor;
    }

    return root;
}

//合併兩個集合
void Graph::merge_set(int u, int v){
    int u_root = find_set(u);
    int v_root = find_set(v);

    //代表 u_root 比較大
    if(MST_Set[u_root] <= MST_Set[v_root]){
        MST_Set[u_root] += MST_Set[v_root];
        MST_Set[v_root] = u_root; //讓 v 指向 u
    }
    else{ //代表 v_root 比較大
        MST_Set[v_root] += MST_Set[u_root];
        MST_Set[u_root] = v_root; //讓 u 指向 v
    }
}

int main(void){
    Graph graph(10);
    graph.add_edge(1, 5, 10);
    graph.add_edge(2, 6, 3);
    graph.add_edge(5, 5, 6);
    graph.add_edge(3, 5, 5);
    graph.add_edge(3, 6, 12);
    graph.add_edge(10, 10);

    graph.print_edges();

    return 0;
}