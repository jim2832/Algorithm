#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
    public:
        Graph(int); //建構式
        void print_edges(); //印出 adjacency matrix
        void add_edge(int, int); //新增一條邊(from, to)
        void BFS(int); //廣度優先搜尋

    private:
        int vertex; //紀錄節點
        vector<list<int>> edges;
};

//建構式
Graph::Graph(int v){
    vertex = v; //表示有幾個頂點
    edges.resize(vertex);
}

//印出 adjacency list
void Graph::print_edges(){
    for(int i=0; i<vertex; i++){
        cout << i+1;

        auto iter = edges[i].begin();
        //list<edge*>::iterator

        for(; iter!=edges[i].end(); iter++){
            cout << " -> " << (*iter)+1;
        }
        cout << endl;
    }
}

//新增一條邊(from, to, weight) -> 若新增成功回傳true，否則回傳false
void Graph::add_edge(int from, int to){
    edges[from-1].push_back(to-1);
    // edges[to].push_back(new edge{from, weight}); // undirected edge
}

//廣度優先搜尋
void Graph::BFS(int start){
    cout << "BFS result: ";

    start--; //考慮到 index 是從 0 開始
    // 0: white
    // 1: gray
    // 2: black
    vector<int> color(vertex, 0); //用來紀錄顏色
    queue<int> q; //暫存走訪資料之queue

    q.push(start);
    color[start] = 1; //將起點的顏色改成灰色
    cout << start+1 << " -> ";

    //若queue不為空，則繼續做
    while(!q.empty()){
        int current = q.front(); //取出第一筆資料
        q.pop(); //將第一筆資料刪除

        //取出current的所有相鄰節點 (存在edges[current]內)
        for(auto iter=edges[current].begin(); iter!=edges[current].end(); iter++){
            if(color[*iter] == 0){ //如果鄰點為白色才能放到queue內
                q.push(*iter); //將此白點放入queue
                color[*iter] = 1; //改成灰色
                cout << (*iter)+1 << " -> ";
            }
        }
        color[current] = 2; //將相鄰點後都處理完後，將current改成黑色
    }
    cout << endl;
}

int main(void){
    Graph graph(7);
    graph.add_edge(1,3);
    graph.add_edge(1,2);
    graph.add_edge(1,6);
    graph.add_edge(2,4);
    graph.add_edge(2,7);
    graph.add_edge(3,4);
    graph.add_edge(4,5);
    graph.add_edge(6,5);
    graph.add_edge(7,6);
    graph.add_edge(7,5);

    graph.BFS(1);

    return 0;
}