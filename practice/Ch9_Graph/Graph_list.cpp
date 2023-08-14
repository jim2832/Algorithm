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
    // edges[to].push_back(new edge{from, weight}); // undirected edge
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