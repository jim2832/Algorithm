#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct{
    int from; //指向這個點的點
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
        void MST_Kruskal();

    private:
        int vertex; //紀錄節點
        vector<list<edge*>> edges;
        vector<int> MST_Set; //紀錄每個頂點的set
        vector<edge> MST_Edges; //紀錄MST目前有的邊
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
    edges[from-1].push_back(new edge{from-1, to-1, weight});            
    edges[to-1].push_back(new edge{to-1, from-1, weight}); // undirected edge
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

    if(u_root == v_root) return;

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

class compare{
    public:
        bool operator()(edge &e1, edge &e2){
            return e1.weight > e2.weight;
        }
};

// Kruskal Algorithm
void Graph::MST_Kruskal(){
    int edges_completed = 0; //有幾條邊已經被放入MST
    MST_Edges.clear();
    priority_queue<edge, vector<edge>, compare> sorted_edges; //邊從權重小排到大

    // push and initialization
    for(int i=0; i<vertex; i++){
        MST_Set[i] = -1; //一開始每個點自己本身都是一個MST
        
        // 初始化
        // 從 edges[i].begin() 取到 edges[i].end()
        for(auto iter=edges[i].begin(); iter!=edges[i].end(); iter++){
            // iter: iterator
            // *iter: edge*
            // **iter: edge
            sorted_edges.push(**iter);
        }
    }

    // 當 priority queue 還不為空 或 已挑到的邊還沒到 v-1 個時繼續做
    while(!sorted_edges.empty() && edges_completed < vertex-1){
        edge current = sorted_edges.top(); //取出權重最小的邊
        sorted_edges.pop();
        //如果屬於不同集合(也就是不會形成環)則挑選之
        if(find_set(current.from) != find_set(current.to)){
            merge_set(current.from, current.to);
            MST_Edges.push_back(current);
            edges_completed++;
        }
    }

    int sum = 0;
    for(int i=0; i<vertex-1; i++){
        cout << (char)(MST_Edges[i].from + 65) << "->" << (char)(MST_Edges[i].to + 65) << endl;
        sum += MST_Edges[i].weight;
    }
    cout << "Weight of this MST is: " << sum << endl;
}

int main(void){
    Graph g(7);
    g.add_edge(1,2,20);
    g.add_edge(1,3,10);
    g.add_edge(1,4,15);
    g.add_edge(2,5,10);
    g.add_edge(3,5,10);
    g.add_edge(3,4,10);
    g.add_edge(3,6,5);
    g.add_edge(4,7,25);
    g.add_edge(6,7,10);
    g.add_edge(5,7,5);
    g.MST_Kruskal();

    return 0;
}